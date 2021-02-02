/* file:  simple_fornaioFIFo.c 
	  il fornaio serve i clienti nell'ordine
	  con cui hanno ottenuto il biglietto.
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

La variabile globale bigliettoSulBancone viene settata dal cliente
quando arriva al bancone ed e' pronto per essere servito.
Dopo avere settato la variabile, il cliente al bancone sveglia il fornaio
con una signal su condSaluto per avvisare di essere arrivato.
Tale variabile viene usata dal fornaio, quando ha finito di servire
il cliente, per settare la variabile previousBigliettoSulBancone.
I clienti in attesa guardano questa variabile incrementata di 1
previousBigliettoSulBancone+1 per sapere chi e' il prossimo cliente
che deve essere servito.
Il solo cliente che ha il proprio biglietto==(1+previousBigliettoSulBancone)
prosegue e viene servito dal fornaio.
I clienti che non hanno quel biglietto non saranno serviti in quel turno,
quindi si bloccano sulla cond condAttendiProssimoTurno.
Quando il fornaio ha finito di servire un cliente
- aggiorna previousBigliettoSulBancone col valore di bigliettoSulBancone
  per indicare di chi e' il prossimo turno,
- alla fine il fornaio sveglia in cliente che stava servendo, signal condSaluto
Poi il fornaio ricomincia il ciclo e, come prima operazione,
sveglia TUTTI i clienti bloccati sulla wait condAttendiProssimoTurno,
*/

/* #define MAINDEBUG */

#define NUMCLIENTICONTEMPORANEAMENTE 50 

/* variabili da proteggere */
int64_t bigliettoGlob=0;
int64_t bigliettoSulBancone, previousBigliettoSulBancone;
/* variabili per la sincronizzazione */
pthread_mutex_t  mutexDistributoreBiglietti;
pthread_mutex_t  mutex;
pthread_cond_t   condFornaioLibero; 
pthread_cond_t   condAttendiProssimoTurno;
pthread_cond_t   condSaluto; 	/* aggiunta per salutare */
/* solo per fare output comprensibile e a fini statistici */
int indiceServito;

void *fornaiochesaluta (void *arg) 
{ 
	char Flabel[128];
	char Flabelsignal[128];
	int indice;

	indice=*((int*)arg);
	free(arg);
	sprintf(Flabel,"F%d",indice);
	sprintf(Flabelsignal,"B%d->C",indice);

	
	while(1) {
		int64_t localBigliettoSulBancone;
		int localIndiceServito;

		/* prendo la mutua esclusione */
		DBGpthread_mutex_lock(&mutex,Flabel); 

		/* dico chi e' il prossimo ad essere servito, solo da adesso
		   il prossimo cliente sa di essere lui il prossimo */
		previousBigliettoSulBancone=bigliettoSulBancone;

		/* libero gli eventuali clienti che erano stati scartati
		   cosi' ora possono vedere nella var aggiornata previousBigliettoSulBancone+1
		   chi e' il prossimo ad essere servito
		*/
#ifdef MAINDEBUG
		printf("il fornaio %s libera clienti \n", Flabel ); 
		fflush(stdout);
#endif
		/* nel caso che il prossimo cliente sia gia' in coda, li risveglio tutti */
		DBGpthread_cond_broadcast( &condAttendiProssimoTurno, Flabel );

		/* il prossimo cliente esce dalla coda e va al banco per essere servito */

		/* aspetto che il cliente sia arrivato al banco e
		   sia pronto a ricevere il saluto del fornaio,
		   Qui esiste la possibilita' che il prossimo cliente 
		   sia gia' arrivato al bancone, */
		DBGpthread_cond_wait ( &condSaluto, &mutex, Flabel );

		/* ORA il cliente mi ha dato il suo biglietto appoggiandolo sul bancone 
		   nella variabile BigliettoSulBancone */
		
		/* fornaio ghini diffidente
		   controlla il biglietto confrontandolo con il precedente +1 
		*/
		if( bigliettoSulBancone != (previousBigliettoSulBancone+1)  ) {
			printf(" ERRORE bigliettoSulBancone %ld DIVERSO "
				"da previousBigliettoSulBancone %ld \n", 
				bigliettoSulBancone, previousBigliettoSulBancone );
			exit(1);
		}
		/* solo per output */
		localBigliettoSulBancone=bigliettoSulBancone;
		localIndiceServito=indiceServito;

		/* rilascio mutua esclusione */
		DBGpthread_mutex_unlock(&mutex,Flabel); 

		/* fornaio serve il cliente */
		printf("fornaio %s serve cliente %d biglietto %li \n", Flabel, localIndiceServito, localBigliettoSulBancone ); 
		fflush(stdout);
		/* il fornaio serve il cliente per 1/2 di sec piu o meno */
		DBGnanosleep( 500000000, Flabel );

		/* fornaio finisce di servire il cliente */
#ifdef MAINDEBUG
		printf("fornaio %s finisce il cliente %d biglietto %li \n", Flabel, localIndiceServito, localBigliettoSulBancone );
		fflush(stdout);
#endif

		/* prendo la mutua esclusione */
		DBGpthread_mutex_lock(&mutex,Flabel); 

		/* fornaio saluta per far uscire fuori il cliente */
		DBGpthread_cond_signal( &condSaluto, Flabel );

		printf("fornaio %s ha salutato cliente %d con biglietto %li \n", Flabel,
			localIndiceServito, localBigliettoSulBancone );
		fflush(stdout);

		/* rilascio mutua esclusione */
		DBGpthread_mutex_unlock(&mutex,Flabel); 

		/* ora il cliente esce */

	}
	pthread_exit(NULL); 
} 

void *clientechevuoleesseresalutato (void *arg) 
{ 
	char Clabel[128];
	char Clabelsignal[128];
	int indice;
	int64_t biglietto;

	indice=*((int*)arg);
	free(arg);
	sprintf(Clabel,"C%d",indice);
	sprintf(Clabelsignal,"C%d->B",indice);

	
	/* il cliente aspetta qualche giorno = 1/2 sec e poi va dal barbiere */
	DBGnanosleep( 500000000, Clabel );

	/* cliente prende il biglietto */
	/* prendo la mutua esclusione */
	DBGpthread_mutex_lock(&mutexDistributoreBiglietti,Clabel); 
	biglietto=bigliettoGlob;
	bigliettoGlob++;
	/* rilascio la mutua esclusione sul distributore */
	DBGpthread_mutex_unlock(&mutexDistributoreBiglietti,Clabel); 

	printf("il cliente %s ha preso il biglietto %ld \n", Clabel, biglietto ); 
	fflush(stdout);


	/* cliente controlla il biglietto sul Bancone
	   per vedere se e' il suo turno oppure no.
	   Se non e' il suo turno aspetta che il fornaio lo risvegli.
	   Al risveglio, il cliente controlla di nuovo se e' il suo turno.
	   Se non e' il suo turno si ri-blocca in attesa del prossimo turno.
	*/
		
	/* prendo la mutua esclusione */
	DBGpthread_mutex_lock(&mutex,Clabel); 

	while( (previousBigliettoSulBancone+1) != biglietto ) {
		/* aspetto */
#ifdef MAINDEBUG
		printf("il cliente %s %li non e' di turno %li , aspetta \n",
			Clabel, biglietto, 1+previousBigliettoSulBancone ); 
		fflush(stdout);
#endif
		DBGpthread_cond_wait( &condAttendiProssimoTurno, &mutex, Clabel );
	}

	/* io cliente esco dalla coda e vado al bancone del fornaio */
	/* il cliente mette il biglietto sul bancone */
	bigliettoSulBancone=biglietto;
	indiceServito=indice; /* solo per output */

	printf("Nuovo Biglietto sul bancone %ld messo da cliente %s\n", bigliettoSulBancone, Clabel ); 
	fflush(stdout);

	DBGpthread_cond_signal ( &condSaluto, Clabel ); /*sono al bancone pronto al saluto*/

	/* il cliente aspetta mentre il fornaio lo serve */
	printf("il cliente %s aspetta mentre viene servito\n", Clabel ); 
	fflush(stdout);

	/* aspetto il saluto del fornaio per andare via dal banco */
	DBGpthread_cond_wait( &condSaluto, &mutex, Clabel );

	/* rilascio mutua esclusione */
	DBGpthread_mutex_unlock(&mutex,Clabel); 

	/* e il cliente se ne va */
	printf("il cliente %s se ne va \n", Clabel ); 
	fflush(stdout);

	pthread_exit(NULL); 
} 

int main (int argc, char* argv[] ) 
{ 
	pthread_t   th, vth[NUMCLIENTICONTEMPORANEAMENTE]; 
	int  rc, i, itot, *intptr;

	rc = pthread_cond_init( &condSaluto , NULL);
	if( rc ) PrintERROR_andExit(rc,"pthread_cond_init failed");
	rc = pthread_cond_init( &condAttendiProssimoTurno , NULL);
	if( rc ) PrintERROR_andExit(rc,"pthread_cond_init failed");
	rc = pthread_mutex_init( &mutex, NULL); 
	if( rc ) PrintERROR_andExit(rc,"pthread_mutex_init failed");
	rc = pthread_mutex_init( &mutexDistributoreBiglietti, NULL); 
	if( rc ) PrintERROR_andExit(rc,"pthread_mutex_init failed");

	bigliettoGlob=1;
	previousBigliettoSulBancone=0;
	
	/* lancio il fornaio */
	intptr=malloc(sizeof(int));
	if( !intptr ) { printf("malloc failed\n");exit(1); }
	*intptr=0; /* un solo barbiere */
	rc=pthread_create( &th, NULL, fornaiochesaluta,(void*)intptr); 
	if(rc) PrintERROR_andExit(rc,"pthread_create failed");

	/* lancio i clienti */
	for(i=0;i<NUMCLIENTICONTEMPORANEAMENTE;i++) {
		intptr=malloc(sizeof(int));
		if( !intptr ) { printf("malloc failed\n");exit(1); }
		*intptr=i;
		rc=pthread_create( &(vth[i]),NULL,clientechevuoleesseresalutato,(void*)intptr); 
		if(rc) PrintERROR_andExit(rc,"pthread_create failed");
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
  
  
  
