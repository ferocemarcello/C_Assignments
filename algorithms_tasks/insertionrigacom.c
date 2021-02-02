#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void insertion(int A[],int p,int r)
{
	int j=0;int i=0;int key=0;
	if(p<r)
	{
		for(j=p+1;j<=r;j++)
		{
			key=A[j];
			i=j-1;
			while(i>=p && A[i]>key)
			{
				A[i+1]=A[i];;
				i=i-1;
			}
			A[i+1]=key;
		}
	}
}
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
int main(int argc, char *argv[])
{
	int*arr;
	int a=0;
	int b=0;
	int n=0;
	if (argc !=4) //controllo sul numero di parametri
	{
		fprintf(stderr, "Usage: func <n>\n");
		return 1;
	}
	a=atoi(argv[2]);
	b=atoi(argv[3]);
	writelist(argv[1],a,b);
	arr=readlist(argv[1],&n);
	printf("vettore iniziale:\n");
	for(a=0;a<n;a++)
	{
		printf("%d\n",*(arr+a));
	}
	insertion(arr,0,n);
	printf("n=%d\n",n);
	printf("vettore ordinato:\n");
	for(a=0;a<n;a++)
	{
		printf("%d\n",*(arr+a));
	}
	return 0;
}
