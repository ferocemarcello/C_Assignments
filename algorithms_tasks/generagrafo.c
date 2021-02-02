#include<stdio.h>
#include<time.h>
#include<stdlib.h>
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
int main ( int argc , char * argv [])
{
	int n,max ,i,j;
	double prob ;
	if( argc !=4)
	{
		fprintf ( stderr ," Usage : randgraph <n> <prob edge > <maxdist >\n");
		return 1;
	}
	n= atoi ( argv [1]) ;
	prob = atof ( argv [2]) ;
	max = atoi ( argv [3]) ;
	srand ( time ( NULL ));
	printf ("% d\n",n);
	for (i =0; i<n; i ++)
	{
		for (j =0; j<n; j ++)
		{
			if (1.0* rand ()/ RAND_MAX < prob )
			printf ("% d %d %d\n",i,j, rand () %( max +1) );
		}
	}
	return 0;
}
