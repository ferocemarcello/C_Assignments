#include<stdio.h>
#include<stdlib.h>
struct Cella //lista dinamica
{
	int valore;
	struct Cella*next;
};
void stampa(struct Cella*T)
{
	struct Cella*tmp;
	tmp=T;
	while(tmp!=NULL)
	{
		printf("%d\n",tmp->valore);
		tmp=tmp->next;
	}
}
struct Cella*cerca(struct Cella*T,int da_cercare)//cerca solo il primo
{
	struct Cella*tmp;
	tmp=T;
	while(tmp!=NULL)
	{
		if(tmp->valore==da_cercare)
		{
			return tmp;
		}
		tmp=tmp->next;
	}
	return NULL;
}
struct Cella*crea(int valore)
{
	struct Cella*nuovo;
	nuovo=(struct Cella*)malloc(sizeof(struct Cella));
	if(nuovo==NULL)
	{
		exit(0);
	}
	nuovo->valore=valore;
	nuovo->next=NULL;
	return nuovo;
}
void inserisci(struct Cella**T,int valore)//passiamo come valore il puntatore a T per far si che le modifiche nella funzioni valgano anche per il main
{
	struct 	Cella*nuovo=(struct Cella*)malloc(sizeof(struct Cella));//alloco una cella di memoria
	if(nuovo==NULL)
	{
		exit(0);
	}
	nuovo->valore=valore;
	nuovo->next=*T;
	*T=nuovo;
}
void elimina(struct cella*T,int da_eliminare)
{
	struct Cella*tmp;
	struct Cella*prev;//previous
	tmp=T;
	prev=NULL;//prev è sull'elemento che precede quello che deve essere eliminato
	while(tmp!=NULL)
	{
		if(tmp->valore==da_eliminare)
		{
			prev->next=tmp->next;
			tmp->next=NULL;
			free(tmp);
			return;
		}
		prev=tmp;
		tmp=tmp->next;
	}
}
int main()
{
	struct Cella*T=NULL;//testa
	struct Cella*tmp;//temporaneo suppongo
	struct Cella*nuovo;
	int trovato=0;
	/*inizializzazione lista*/
	inserisci(&T,10);
	system("pause");
	stampa(T);
	system("pause");
	printf("\nads%d",cerca(T,10)->valore);
	return 0;
}
