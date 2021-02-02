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
void din_initlista(struct Cella**T,struct Cella**C)//inizializzo i puntatori alla lista a NULL
{
	*T=NULL;
	*C=NULL;
}
int menu()//funzione che, dato un menu, restituisce la scelta che si vuole fare
{
	int scelta=0;
	printf("cosa vuoi fare?\n\n");
	printf("verificare se la pila e' vuota\t\t\t\t1\n");
	printf("inserimento in testa\t\t\t\t\t2\n");
	printf("visualizzare la testa ed eliminarla dalla pila\t\t3\n");
	printf("visualizzare la testa della pila\t\t\t4\n");
	printf("esci\t\t\t\t\t\t\t5\n");
	while(scanf("%d",&scelta)==0||scelta<1||scelta>5)//lettura e controllo sull'imput
	{
		printf("digita un intero compreso tra 1 e 5\t");
		fflush(stdin);
	}
	fflush(stdin);
	return scelta;
}
void stat_initlista(struct slista *lis)//inizializzo la lista statica
{
	(*lis).last=-1;
}
int din_isempty(struct Cella*T)//restituisce 1 se la pila è vuota, 0 se non
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
	else return 0;//altrimenti 0
}
void din_push(struct Cella**T,struct Cella**C,int val)//inserisce elemento alla testa
{
	struct 	Cella*nuovo=(struct Cella*)malloc(sizeof(struct Cella));//alloco una cella di memoria
	if(nuovo==NULL)//controllo sul valore di ritorno della malloc
	{
		exit(0);
	}
	nuovo->valore=val;
	nuovo->next=*T;//assegno il puntatore next di nuovo alla testa(iniziale)
	*T=nuovo;//faccio diventare la testa il nuovo elemento
	if(*C==NULL) *C=nuovo;//se la lista era inizialmente vuota assegno al puntatore coda, il nuovo elemento
}
int din_pop(struct Cella**T)//cancella l'elemento testa dalla pila e lo restituisce
{
	struct Cella*tmp;
	int testa=0;
	tmp=*T;
	*T=(*T)->next;//la testa diventa l'elemento successivo
	testa=tmp->valore;
	free(tmp);
	return testa;
}
int din_top(struct Cella*T)//restituisce testa pila
{
	return (T->valore);
}
int stat_isempty(struct slista*lis)//restituisce 1 se la pila è vuota, 0 se non
{
	if((*lis).last<=-1)//se l'indice dell'ultimo elemento della pila==-1, restituisce 1
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void stat_push(struct slista*lis,int val)//inserisce elemento alla testa
{
	int k=(*lis).last;
	int imp=0;
	if(k>=N)//controllo sullo spazio nella lista statica
	{
		printf("spazio insufficiente nella lista\n");
		imp=1;
	}
	if(imp==0)
	{
		for(k;k>=0;k--)//sposto tutti gli elementi avanti di 1
		{
			(*lis).valori[k]=(*lis).valori[k-1];
		}
		(*lis).last++;
		(*lis).valori[0]=val;//assegno al primo elemento della lista l'elemento scelto dall'utente
	}
}
int stat_pop(struct slista*lis)//cancella l'elemneto testa dalla pila e lo restituisce
{
	int k=0;
	int elem=0;
	int imp=0;
	elem=(*lis).valori[0];
	if((*lis).last==-1)//controllo che la lista non sia vuota
	{
		printf("lista vuota");
		imp=1;
		return;
	}
	if(imp==0)
	{
		for(k;k<=(*lis).last;k++)//sposto tutti gli elementi indietro di una posizione
		{
			(*lis).valori[k]=(*lis).valori[k+1];
		}
		(*lis).last--;//decremento l'indice della misura dell'ultima posizione di un elemento nella pila
		return(elem);//restituisco la testa iniziale
	}
}
int stat_top(struct slista*lis)//restituisce testa pila
{
	int imp=0;
	if((*lis).last==-1)
	{
		printf("lista vuota");
		imp=1;
		return;
	}
	return ((*lis).valori[0]);//restituisca la testa della pila
}
