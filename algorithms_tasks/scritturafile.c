#include <stdio.h>
#include <stdlib.h>
#include<time.h>
void printlist(int *A, int n) {
  int i;
  for(i=0; i<n; i++)
    printf("%d ",A[i]);
  printf("\n");
}
int *readlist(char *file, int *n) {
	FILE *in = fopen(file,"r");
	int *list,i,x;

	if(in==NULL) return NULL;
	i=0;
	while(fscanf(in,"%d",&x)!=EOF) i++;
	*n=i;
	if((list = (int *)calloc(*n,sizeof(int)))==NULL)
		return NULL;
	rewind(in);
	i=0;
	while(fscanf(in,"%d",&x)!=EOF) list[i++]=x;
	fclose(in);
	return list;
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
	
	int n=0,a=0;//a è un contatore per il for succesivo
	int*A;
	if (argc !=4) //controllo sul numero di parametri
	{
		fprintf(stderr, "Usage: func <n>\n");
		return 1;
	}
	printf("primo parametro nome del file da creare\nsecondoparametro numero di elementi da scrivere\nterzo parametro valore massimo dei numeri\n");
	n=atoi(argv[2]);
	a=atoi(argv[3]);
	writelist(argv[1],n,a);
	printf("\nil numero di elementi presenti nel file e' %d", n);
	return 0;
}

