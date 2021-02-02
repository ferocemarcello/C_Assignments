#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int *readlist(char *file, int *n)
{
	*n=0;//azzero il contatore di interi
	FILE *in;//puntatore a FILE
	int *list,x;//creo il puntatore che conterra tutti gli elementi letti; in x mettiamo il valore temporaneo letto dal file
	
	if((in=fopen(file,"r"))==NULL) return NULL;//controllo sull'istruzione
	while(fscanf(in,"%d",&x)!=EOF) (*n)++;//con n++aumento il numero di elementi del puntatore di ritorno, while fino a EOF(fine del file)
	if ((list = (int*)calloc(*n,sizeof(int)))==NULL) return NULL;//alloco le celle di memoria necessarie	
	rewind(in);//ci riporta all'inizio del file
	(*n)=0;//azzeriamo n, che è l'indice
	while(fscanf(in,"%d",&x)!=EOF) list[(*n)++]=x;//inserisco gli elementi
	fclose(in);//chiude il file
	return list;//restituisce un puntatore di interi
	
}
void writelist(char *file,int n, int max)//n numero di elementi da inserire, max valore massimo
{
	srand((unsigned) time(NULL));
	FILE *in;//puntatore a FILE
	int x;//creo il puntatore che conterra tutti gli elementi letti; in x mettiamo il valore temporaneo letto dal file
	if((in=fopen(file,"w"))==NULL) return ;//controllo sull'istruzione
	for(x=0;x<n;x++) fprintf(in, "%d\n", rand()%max);
	
	fclose(in);//chiude il file
	
}
