#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define R 11 //range di valori che può assumere ogni elemento dell'array
#define L 10 //lunghezza del puntatore ad intero
int lung;//misura della volte che compare un numero nell'array(è la lunghezza del puntatore restituito dalla funzione cerca
int* cerca(int *vettore,int dimensione,int elem)//cerca la posizione di un elemento in un vettore non ordinato
{
	lung=0;
	int k=0;//indicatore posizione puntatore principale(*vettore)
	int *ptr;//dichiaro il puntatore delle posizioni in cui compare un numero
	ptr=(int*)malloc(sizeof(int));//e gli alloco una cella di memoria
	if(ptr==NULL)
	{
		printf("spazio insufficiente");
		exit(1);
	}
	*(ptr)=-1;//assegno alla prima posizione del puntatore il valore -1
	for(k=0;k<dimensione;k++)//verifico la/e posizione/i di un numero nell'array
	{
		if(elem==vettore[k])//se trovo una posizione del puntatore principale corrispondente al valore cercato alloco una cella di memoria in più 
		{					//al puntatore delle posizioni e gli alloco la posizione del puntatore principale in cui compare l'elemento ricercato
			ptr=(int*)realloc(ptr,(lung+1)*sizeof(int));
			if(ptr==NULL)
			{
				printf("spazio insufficiente");
				exit(1);
			}
			*(ptr+lung)=k;
			lung++;
		}
	}
	return ptr;//restituisco il puntatore delle posizioni
}
int *cerca_vettore_ordinato(int *vettore,int dimensione,int elem)//cerca la posizione di un elemento in un vettore ordinato
{
	lung=0;
	int k=0;//indicatore posizione puntatore principale(*vettore)
	int*ptr;//dichiaro il puntatore delle posizioni in cui compare un numero
	int esci=0;
	ptr=(int*)malloc(sizeof(int));//e gli alloco una cella di memoria
	if(ptr==NULL)
	{
		printf("spazio insufficiente");
		exit(1);
	}
	*(ptr)=-1;//assegno alla prima posizione del puntatore il valore -1
	for(k=0;k<dimensione &&esci==0;k++)//verifico la/e posizione/i di un numero nell'array
	{
			if(elem==vettore[k])//se trovo una posizione del puntatore principale corrispondente al valore cercato alloco una cella di memoria in più 
			{					//al puntatore delle posizioni e gli alloco la posizione del puntatore principale in cui compare l'elemento ricercato
				*(ptr+lung)=k;
				lung++;
				ptr=(int*)realloc(ptr,(lung+1)*sizeof(int));
				if(ptr==NULL)
				{
					printf("spazio insufficiente");
					exit(1);
				}
			}
			if(lung>0)//se l'elemento cercato compare almeno una volta
			{
				
				if(elem!=vettore[k+1])//se il valore del puntatore principale è diverso nella posizione successiva interrompe il programma
				{
					esci=1;
				}	
			}
	}
	return ptr;//restituisco il puntatore delle posizioni
}
int main()
{
	int *arr;//dichiaro il puntatore
	int a=0;
	int k=0;
	int esci=0;
	int risposta=0;//intero che verifica la risposta
	srand((unsigned int) time(NULL));//faccio partire il contatore tempo
	arr=(int*)malloc(L*sizeof(int));//alloco al puntatore un numero di L di celle
	if(arr==NULL)
	{
		printf("spazio insufficiente");
		exit(1);
	}
	printf("vuoi un vettore ordinato?\nrispondere con 1 per si o con 2 per no\n");
	while(scanf("%d",&risposta)==0 || (risposta!=1 && risposta!=2))
	{
		printf("scrivi 1 o 2\n");
		fflush(stdin);
	}
	fflush(stdin);
	if(risposta==2)//vettore non ordinato
	{
		for(a=0;a<L;a++)
		{
			*(arr+a)=rand()%R;//assegno un valore casuale ad ogni elemento dell'array
			printf("arr[%d]=%d\n",a,*(arr+a));
		}
		printf("digita il valore che vuoi ricercare nell'array\t");
		scanf("%d",&a);//leggo il valore
		fflush(stdin);
		if(cerca(arr,L,a)[0]==-1)//se la prima cella del puntatore non è cambiata, vuol dire che l'elemento cercato non è presente nel puntatore
								//nell'if richiamo la funzione, che stampa le posizioni in cui è presente l'elemento(se è presente)
		{
			printf("valore non compreso nell'array");
		}
		else
		{
			for(k=0;k<lung;k++)
			{
				printf("il valore e' presente nella posizione %d\n",cerca(arr,L,a)[k]);
			}
		}
	}
	if(risposta==1)//vettore ordinato in modo crescente
	{
		for(a=0;a<L;a++)
		{
			if(a==0)
			{
				*(arr+a)=rand()%R;//assegno un valore al primo elemento dell'array
				printf("arr[%d]=%d\n",a,*(arr+a));
			}
			if(a>0)
			{
				*(arr+a)=*(arr+(a-1))+rand()%2;//all'elemento successivo assegno un valore pari a quello precedente sommato di uno o due
				printf("arr[%d]=%d\n",a,*(arr+a));
			}
		}
		printf("digita il valore che vuoi ricercare nell'array\t");
		scanf("%d",&a);
		fflush(stdin);
		if(cerca_vettore_ordinato(arr,L,a)[0]==-1)//se la prima cella del puntatore non è cambiata, vuol dire che l'elemento cercato non è presente nel puntatore
		{											//nell'if richiamo la funzione, che stampa le posizioni in cui è presente l'elemento(se è presente)
			printf("valore non compreso nell'array");
		}
		else
		{
			for(k=0;k<lung;k++)
			{
				printf("il valore e' presente nella posizione %d\n",cerca_vettore_ordinato(arr,L,a)[k]);
			}
		}
	}
	free(arr);
	return 0;
}
