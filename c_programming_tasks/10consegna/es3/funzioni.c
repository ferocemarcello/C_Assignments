#include<stdio.h>
#include<stdlib.h>
#define N 10
struct Cella //lista dinamica
{
	int valore;
	struct Cella*next;
};
struct slista //lista statica
{
	int last;
	int valori[N];
};
void din_initlista(struct Cella**T,struct Cella**C)//inizializza la lista
{
	*T=NULL;
	*C=NULL;
}
int din_isempty(struct Cella*T)//restituisce 1 se la coda è vuota, 0 se non
{
	struct Cella*tmp;
	int lung=0;
	tmp=T;
	while(tmp!=NULL)//con questo ciclo scorro tutti gli elementi e calcolo la lunghezza
	{
		lung++;
		tmp=tmp->next;
	}
	if(lung==0)return 1;//se la lunghezza è 0, restituisco 1
	else return 0;//altrimente 0
}
void din_enqueue(struct Cella**T,struct Cella**C,int val)//aggiunge un elemento come ultimo nella struttura coda
{
	struct 	Cella*nuovo=(struct Cella*)malloc(sizeof(struct Cella));//alloco una cella di memoria
	if(nuovo==NULL)//controllo sul valore di ritorno della malloc
	{
		exit(0);
	}
	if (*C==NULL)//se la lista è vuota assegno al puntatore alla testa il nuovo elemento 
	{
		*T=nuovo;
	}
	else //altrimenti il nuovo elemento diventa il successivo alla coda
	{
		(*C)->next=nuovo;
	}
	*C=nuovo;//la coda diventa il nuovo elemento
	nuovo->valore=val;
	nuovo->next=NULL;//assegno a null l'elemento successivo alla coda(nuovo)
}
int din_dequeue(struct Cella**T)//toglie il primo elemento e lo restituisce
{
	struct Cella*tmp;
	int testa=0;
	tmp=*T;
	*T=(*T)->next;//la testa diventa l'elemento successivo
	testa=tmp->valore;
	free(tmp);
	return testa;
}
int din_first(struct Cella*T)//restituisce il primo elemento
{
	return (T->valore);
}
int menu()//funzione che, dato un menu, restituisce la scelta che si vuole fare
{
	int scelta=0;
	printf("cosa vuoi fare?\n\n");
	printf("verificare se la coda e' vuota\t\t\t\t\t1\n");
	printf("inserimento in coda\t\t\t\t\t\t2\n");
	printf("visualizzare la testa ed eliminarla dalla struttura coda\t3\n");
	printf("visualizzare la testa della struttura coda\t\t\t4\n");
	printf("esci\t\t\t\t\t\t\t\t5\n");
	while(scanf("%d",&scelta)==0||scelta<1||scelta>5)
	{
		printf("digita un intero compreso tra 1 e 5\t");
		fflush(stdin);
	}
	fflush(stdin);
	return scelta;
}
void stat_initlista(struct slista *lis)
{
	(*lis).last=-1;
}

int stat_isempty(struct slista*lis)//restituisce 1 se la pila è vuota, 0 se non
{
	if((*lis).last<=-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void stat_enqueue(struct slista*lis,int val)//aggiunge un elemento come ultimo nella struttura coda
{
	(*lis).last++;//incremento di 1 l'indicatore dell'ultimo elemento della lista
	if((*lis).last>=N)
	{
		printf("spazio insufficiente nella lista");
		exit(0);
	}
	(*lis).valori[(*lis).last]=val;//assegno il valore desiserato all'ultimo elemento della lista
}
int stat_dequeue(struct slista*lis)//toglie il primo elemento e lo restituisce
{
	int k=0;
	int imp=0;
	int elem=(*lis).valori[0];
	if((*lis).last==-1)
	{
		imp=1;
		printf("lista vuota\n");
		return;
	}
	if(imp==0)
	{
		for(k;k<(*lis).last;k++)//sposta tutti gli elementi di 1 indietro
		{
			(*lis).valori[k]=(*lis).valori[k+1];
		}
		(*lis).last--;//decremento l'indice dell'ultimo elemento di 1
		return elem;
	}
}
int stat_first(struct slista*lis)//restituisce il primo elemento
{
	return ((*lis).valori[0]);
}
