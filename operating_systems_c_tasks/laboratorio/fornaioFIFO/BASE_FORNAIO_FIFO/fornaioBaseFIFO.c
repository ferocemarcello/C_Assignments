/* file:  fornaioBaseFIFo.c 
	  il fornaio deve servire i clienti nell'ordine
	  con cui hanno ottenuto il biglietto,
	  cioe' nell'ordine crescente del valore di biglietto.
*/ 

#ifndef _MULTI_THREADED
	#define _MULTI_THREADED
#endif
#ifndef _POSIX_C_SOURCE
	#define _POSIX_C_SOURCE 200112L
#endif


#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <stdint.h>	/* uint64_t */
#include <sys/time.h>	/* gettimeofday()    struct timeval */
#include <pthread.h> 

#include "printerror.h"
#include "DBGpthread.h"

/* 
prima di essere servito il cliente prende il biglietto
contenente un numero che stabilisce il suo turno.
Il biglietto viene preso in mutua esclusione mediante
una variabile apposita mutex   mutexDistributoreBiglietti.

Quella variabile mutex mutexDistributoreBiglietti
DEVE ESSERE USATA SOLO PER PRENDERE IL BIGLIETTO.
*/

#define NUMCLIENTICONTEMPORANEAMENTE 5

/* variabile da proteggere con la mutexDistributoreBiglietti */
int64_t bigliettoGlob=0;
int64_t bigliettoSulBancone, previousBigliettoSulBancone;
/* variabili per la sincronizzazione */
pthread_mutex_t  mutexDistributoreBiglietti;
pthread_mutex_t mutex;
pthread_cond_t condAttendiProssimoTurno;
pthread_cond_t   condSaluto; /*aggiunta per salutare*/
void *fornaiochesaluta (void *arg) 
{ 
	char Flabel[128];
	int indice;
	int rc;
	indice=*((int*)arg);
	free(arg);
	sprintf(Flabel,"F%d",indice);

	
	while(1) {
		int64_t temp_bigliettoSulBancone;

		/* il fornaio fa qualcosa per stabilire chi e'
		   il prossimo cliente, 
		   ed ASPETTA l'arrivo del prossimo cliente.

		   AGGIUNGERE CODICE per quanto necessario
		*/
		pthread_mutex_lock(&mutex);

/* dico chi e' il prossimo ad essere */
previousBigliettoSulBancone=bigliettoSulBancone;
/* libero gli eventuali clienti che non erano di turno */
pthread_cond_broadcast( &condAttendiProssimoTurno);
/* aspetto che il cliente arrivi al bancone */
pthread_cond_wait( &condSaluto, &mutex);
/* ORA il cliente ha appoggiato il suo biglietto al bancone */
/*rilascio mutua esclusione*/
pthread_mutex_unlock(&mutex); 
/* fornaio serve il cliente*/
printf("fornaio serve cliente\n" ); 
fflush(stdout);
/* il fornaio serve il cliente per 1/2 di sec piu o meno */
nanosleep( 500000000,Flabel);
/* fornaio finisce di servire il cliente */
/* prendo la mutua esclusione*/
pthread_mutex_lock(&mutex); 
/* fornaio saluta per far uscire fuori il cliente */
pthread_cond_signal( &condSaluto);
printf("fornaio ha salutato cliente\n" );
fflush(stdout);
/* rilascio mutua esclusione*/

		/* quando il prossimo cliente e' arrivato
		   ed ha copiato il proprio biglietto nella variabile globale
		   bigliettoSulBancone

		   il fornaio copia la variabile globale 
		   nella sua variabile locale temp_bigliettoSulBancone
		   per stamparla piu' avanti.

		   AGGIUNGERE CODICE per quanto necessario
		*/

		/*temp_bigliettoSulBancone = bigliettoSulBancone;*/

		/*
		   AGGIUNGERE CODICE per quanto necessario
		*/

		/*rc=pthread_mutex_unlock(&mutexDistributoreBiglietti);*/
		/* Poi, FUORI DALLA MUTUA ESCLUSIONE , il fornaio
		   serve il cliente per 1/2 di sec piu o meno 
		*/
		/*printf("fornaio %s serve cliente con biglietto %li \n", Flabel, temp_bigliettoSulBancone );
		DBGnanosleep( 500000000, Flabel );*/


		/* il fornaio, dopo avere servito il cliente,
		   fa qualcosa per farlo andare via 

		   AGGIUNGERE CODICE per quanto necessario
		*/

		pthread_mutex_unlock(&mutex); 
	}
	pthread_exit(NULL); 
} 

void *clientechevuoleesseresalutato (void *arg) 
{ 
	char Clabel[128];
	int indice;
	int64_t biglietto;

	pthread_mutex_lock(&mutexDistributoreBiglietti); 
biglietto=bigliettoGlob;
/* cliente prende il biglietto */
bigliettoGlob++;
pthread_mutex_unlock(&mutexDistributoreBiglietti); 
/* cliente controlla il biglietto sul Bancone per vedere se e' il suo turno oppure no.
Se non e' il suo turno aspetta che 
il fornaio lo risvegli.
Al risveglio, 
il cliente controlla di nuovo se e' il suo turno.
Se non e' il suo turno si blocca in attesa del prossimo turno.
*/
pthread_mutex_lock(&mutex); 
while( (previousBigliettoSulBancone+1) != biglietto)
{  
/* non sono di turno, aspetto */
pthread_cond_wait( &condAttendiProssimoTurno, &mutex);
}
/* io cliente esco dalla coda e vado al bancone del fornaio */
bigliettoSulBancone=biglietto;
pthread_cond_signal( &condSaluto);
/*ok, sono al banco, ora il fornaio mi serve  */
/* il cliente aspetta mentre il fornaio lo serve */
pthread_cond_wait( &condSaluto, &mutex); 
/* aspetto il saluto del fornaio per andare via dal banco */
pthread_mutex_unlock(&mutex);
/* rilascio mutua esclusione*/
/* e il cliente se ne va */
pthread_exit(NULL);  
} 

int main (int argc, char* argv[] ) 
{ 
	pthread_t   th, vth[NUMCLIENTICONTEMPORANEAMENTE]; 
	int  rc, i, itot, *intptr;
	
	rc= pthread_cond_init(&condSaluto, NULL);
	rc= pthread_cond_init(&condAttendiProssimoTurno, NULL);
	rc = pthread_mutex_init( &mutexDistributoreBiglietti, NULL); 
	if( rc ) PrintERROR_andExit(rc,"pthread_mutex_init failed");
	rc = pthread_mutex_init( &mutex, NULL); 
	if( rc ) PrintERROR_andExit(rc,"pthread_mutex_init failed");
	bigliettoGlob=1;
	
	/* lancio il fornaio */
	intptr=malloc(sizeof(int));
	if( !intptr ) { printf("malloc failed\n");exit(1); }
	*intptr=0; /* un solo barbiere */
	rc=pthread_create( &th, NULL, fornaiochesaluta,(void*)intptr); 
	if(rc) PrintERROR_andExit(rc,"pthread_create failed");

	/* lancio i clienti */
	/*for(i=0;i<NUMCLIENTICONTEMPORANEAMENTE;i++) {
		intptr=malloc(sizeof(int));
		if( !intptr ) { printf("malloc failed\n");exit(1); }
		*intptr=i;
		rc=pthread_create( &(vth[i]),NULL,clientechevuoleesseresalutato,(void*)intptr); 
		if(rc) PrintERROR_andExit(rc,"pthread_create failed");
	}*/
	for(i=0;i<NUMCLIENTICONTEMPORANEAMENTE;i++) 	
	{
		intptr=malloc(sizeof(int));  	
		*intptr=i;
		rc=pthread_create( &(vth[i]),NULL,clientechevuoleesseresalutato,(void*)intptr); 
	}
	itot=i-1;
	i=0;	
	while(1) {
		/* aspetto la fine di un thread e ne lancio un altro */
		void *ptr;
		rc=pthread_join( vth[i] , &ptr );
		if(rc) PrintERROR_andExit(rc,"pthread_join failed");

		intptr=malloc(sizeof(int));
		if( !intptr ) { printf("malloc failed\n");exit(1); }
		*intptr=itot;
		itot++;
		rc=pthread_create( &(vth[i]),NULL,clientechevuoleesseresalutato,(void*)intptr); 
		if(rc) PrintERROR_andExit(rc,"pthread_create failed");
		/* impostare per aspettare il prossimo */
		i++;
		i = i%NUMCLIENTICONTEMPORANEAMENTE;
	}

	pthread_exit(NULL); 

	return(0); 
} 
  
  
  
