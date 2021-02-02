#include <stdio.h>
#include <stdlib.h>

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


int main(int argc, char *argv[])
{
	
	int *punt;//inizializzo un puntatore a caso
	int n=0,a=0;//a è un contatore per il for succesivo
	if (argc !=2) //controllo sul numero di parametri
	{
		fprintf(stderr, "Usage: func <n>\n");
		return 1;
	}
	
	punt=readlist(argv[1], &n);//leggo il file.txt come primo argomento della riga di comando, e mi restituisce n, la lunghezza del puntatore
	if (punt==NULL) exit(1);//controllo sul puntatore
	
	for(a=0;a<n;a++)//stampa
	{
		
		printf("%d	",punt[a]);
		
	}
	
	return 0;
}

