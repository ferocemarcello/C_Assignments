#include<stdio.h>
#include<stdlib.h>
#define N 10 //numero di elementi della lista statica
struct Cella //lista dinamica di interi
{
	int valore;
	struct Cella*next;
};
struct slista //lista statica di interi
{
	int last;
	int valori[N];
};
void din_inserisci_in_testa(struct Cella**T,struct Cella**C,int val)//passiamo come valore il puntatore a T per far si che le modifiche nella funzioni
																	// valgano anche per il main
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
void din_inserisci_in_coda(struct Cella**T,struct Cella**C,int val)//passiamo come valore il puntatore a T per far si che le modifiche
																	// nella funzioni valgano anche per il main
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
void din_inserisci_dopo_elem(struct Cella**T,struct Cella**C,int pos,int val)
{
	int n=0;//variabile per scorrere tutte le posizioni di una lista(dalla testa in poi
	struct 	Cella*tmp;
	struct 	Cella*tmp2;
	struct 	Cella*nuovo=(struct Cella*)malloc(sizeof(struct Cella));//alloco una cella di memoria
	int cond=0;
	if(nuovo==NULL)//controllo sul valore di ritorno della malloc
	{
		exit(0);
	}
	nuovo->valore=val;
	if(*T==NULL)//se la lista era inizialmente vuota
	{
		*T=nuovo;//assegno al puntatore a testa il nuovo elemento
		nuovo->next=NULL;//il successivo alla testa a null
		*C=nuovo;//la coda coincide con la testa
		cond=1;
	}
	tmp=*T;//eguaglio un puntatore temporaneo alla testa
	if(cond==0)
	{
		for(n=0;n<pos;n++)
		{
			tmp=tmp->next;//scorro tutte le posizioni della lista fino ad arrivare alla posizione richiesta dall'utente
		}
		tmp2=tmp->next;
		nuovo->valore=val;
		tmp->next=nuovo;
		nuovo->next=tmp2;
	}
}
void din_cancella_in_testa(struct Cella**T)//passiamo come valore il puntatore a T per far si che le modifiche nella funzioni valgano anche per il main
{
	struct Cella*tmp;//puntatore temporaneo
	int vuota=0;
	if(*T==NULL)//se la lista è vuota esco dalla funzione
	{
		printf("lista vuota");
		vuota=1;
	}
	if(vuota==0)
	{
		tmp=*T;//assegno la testa al puntatore temporaneo
		*T=(*T)->next;//faccio diventare la testa il suo successivo
		free(tmp);//libero la testa iniziale
	}
}
void din_cancella_in_coda(struct Cella**T,struct Cella**C,int lung)//passiamo come valore il puntatore a T per far si che le modifiche nella funzioni valgano anche per il main
{
	int k=0;
	struct Cella*tmp;
	struct Cella*tmp2;
	int vuota=0;
	if(*T==NULL)//se la lista è vuota esco dalla funzione
	{
		printf("lista vuota");
		vuota=1;
	}
	if(vuota==0)
	{
		tmp=*T;
		for(k;k<lung-2;k++)
		{
			tmp=tmp->next;//scorro tutti gli elementi fino ad arrivare al penultimo
		}
		tmp2=*C;//assegno al puntatore temporaneo tmp2, la coda
		*C=tmp;//assegno alla coda il penultimo elemento
		free(tmp2);//libero la cella della coda iniziale
		(*C)->next=NULL;
	}
}
void din_cancella_prima_occorrenza(struct Cella**T,int val)
{
	struct Cella*tmp;//puntatore temporaneo
	struct Cella*tmp2;//puntatore temporaneo
	struct Cella*tmp3;//puntatore temporaneo
	int vuota=0;
	if(*T==NULL)
	{
		printf("lista vuota");
		vuota=1;
	}
	tmp=*T;//assegno al puntatore temporaneo la testa
	if(vuota==0&&tmp->valore==val)//vedo se la testa corrisponde all'elemento cercato
	{
		*T=(*T)->next;//faccio diventare la testa il suo successivo
		free(tmp);//libero la testa iniziale//cancella in testa
		vuota=1;
	}
	while(tmp->next!=NULL&&vuota==0)//scorro tutti gli elementi della lista fino alla fine
	{
		tmp2=tmp;
		tmp=tmp->next;
		tmp3=tmp->next;
		if(tmp->valore==val)//appena trovo la cella che contiene il valore cercato,la elimino ed esco dalla funzione
		{
			tmp2->next=tmp3;
			free(tmp);
			vuota=1;
		}
	}
}
void din_cancella_tutte_occorenze(struct Cella**T,struct Cella**C,int val)
{
	struct Cella*tmp;//puntatore temporaneo
	struct Cella*tmp2;//puntatore temporaneo
	struct Cella*prev;//puntatore temporaneo
	int lung=din_lunghezza(*T);
	int vuota=0;
	int k=0;
	if(*T==NULL)
	{
		printf("lista vuota");
		vuota=1;
	}
	if(vuota==0)//se la lista non è vuota
	{
		tmp=*T;//assegno al puntatore temporaneo la testa
		if(tmp!=NULL)
		{
			printf("lista non vuota\n");
		}
		if(tmp->next==NULL)
		{
			printf("lista di un solo elemento\n");
		}
		while(tmp!=NULL)
		{
			printf("tmp->valore=%d",tmp->valore);
			system("pause");
			tmp=tmp->next;
		}
		system("pause");
		tmp=*T;
			while(tmp!=NULL)
			{
				printf("h\n");
				/*if(tmp==*T && tmp->valore==val)
				{
					tmp2=tmp;
					*T=(*T)->next;
					free(tmp2);
				}*/
				if(tmp!=*T && tmp->next!=NULL && tmp->valore==val)
				{
					tmp2=tmp;
					prev->next=tmp->next;
					free(tmp2);
				}/*
				if(tmp==*C && tmp->valore==val)
				{
					tmp=*T;
					lung=din_lunghezza(*T);
					k=0;
					for(k;k<lung-2;k++)
					{
						tmp=tmp->next;//scorro tutti gli elementi fino ad arrivare al penultimo
					}
					tmp2=*C;//assegno al puntatore temporaneo tmp2, la coda
					*C=tmp;//assegno alla coda il penultimo elemento
					free(tmp2);//libero la cella della coda iniziale
					(*C)->next=NULL;
				}*/
				if(tmp==*T)
				{
					prev=NULL;
				}
				else
				{
					prev=tmp;
				}
				tmp=tmp->next;
			}
	}
}
void din_stampa(struct Cella*T,struct Cella*C)//stampa la lista
{
	struct Cella*tmp;
	tmp=T;
	while(tmp!=NULL)//scorro tutti gli elementi fino alla fine
	{
		printf("%d\t",tmp->valore);
		tmp=tmp->next;
	}
}
int din_lunghezza(struct Cella*T)//funzione che restituisce la lunghezza della lista
{
	struct Cella*tmp;
	int lung=0;
	tmp=T;
	while(tmp!=NULL)//scorro tutti gli elementi incrementando la lunghezza di 1
	{
		lung++;
		tmp=tmp->next;
	}
	return lung;
}
int din_presenza(struct Cella*T,int val)//funzione che restituisce 1 se il valore è presente nella funzione
{
	struct Cella*tmp;
	tmp=T;
	while(tmp!=NULL)//scorro tutti gli elementi della funzione, e se ne trovo almeno 1 con il valore cercato, restituisco 1
	{
		if(tmp->valore==val)
		{
			return 1;
		}
		tmp=tmp->next;
	}
	return 0;//altrimenti restituisco 0
}
void din_initlista(struct Cella**T,struct Cella**C)//richiedo un puntatore a puntatore a struct Cella e non solo un puntatore, cosìcche
													// le modifiche sugli argomenti della funzione valgano anche al di fuori di essa
{
	*T=NULL;//inizializzo la testa e la coda a NULL
	*C=NULL;
}
int menu()//funzione che, dato un menu, restituisce la scelta che si vuole fare
{
	int scelta=0;
	printf("cosa vuoi fare?\n\n");
	printf("inserimento in testa\t\t\t\t\t1\n");
	printf("inserimento in coda\t\t\t\t\t2\n");
	printf("inserimento dopo una certa posizione\t\t\t3\n");
	printf("cancellare l'elemento in testa\t\t\t\t4\n");
	printf("cancellare l'elemento in coda\t\t\t\t5\n");
	printf("cancellare la prima occorenza di un certo elemento\t6\n");
	printf("cancellare tutte le occorrenze di un certo elemento\t7\n");
	printf("esci\t\t\t\t\t\t\t8\n");
	while(scanf("%d",&scelta)==0||scelta<1||scelta>8)//controllo sull'imput
	{
		printf("digita un intero compreso tra 1 e 8\t");
		fflush(stdin);
	}
	fflush(stdin);
	return scelta;
}
void stat_initlista(struct slista *lis)//inizializzo la lista
{
	(*lis).last=-1;
}
void stat_inserisci_in_coda(struct slista *lis,int valore)//inserisce in coda
{
	(*lis).last++;//incremento di 1 l'indicatore dell'ultimo elemento della lista
	if((*lis).last>=N)
	{
		printf("spazio insufficiente nella lista");
		exit(0);
	}
	(*lis).valori[(*lis).last]=valore;//assegno il valore desiserato all'ultimo elemento della lista
}
void stat_inserisci_in_testa(struct slista *lis,int val)//inserisce in testa
{
	int k=0;
	(*lis).last++;
	k=(*lis).last;
	if(k>=N)
	{
		printf("spazio insufficiente nella lista");
		exit(0);
	}
	if((*lis).last==0)//inserisco in testa se la lista è vuota
	{
		(*lis).valori[k]=val;
	}
	for(k;k>0;k--)//inserisco in testa con lista già piena, spostando ogni elemento di 1 posizione
	{
		(*lis).valori[k]=(*lis).valori[k-1];
	}
	(*lis).valori[0]=val;
}
void stat_inserisci_dopo_elem(struct slista *lis,int pos,int val)//inserisco un elemento dopo una certa posizione
{
	(*lis).last++;
	int k=0;
	k=(*lis).last;
	if(k>=N)
	{
		printf("spazio insufficiente nella lista");
		exit(0);
	}
	for(k;k>pos;k--)//dalla fine fino alla posizione desiderata(esclusa)sposto gli elementi avanti di 1
	{
		(*lis).valori[k]=(*lis).valori[k-1];
	}
	(*lis).valori[pos+1]=val;
}
void stat_cancella_in_testa(struct slista *lis)//cancella in testa
{
	int k=0;
	int imp=0;
	if((*lis).last==-1)
	{
		imp=1;
		printf("lista vuota\n");
	}
	if(imp==0)
	{
		for(k;k<=(*lis).last;k++)//sposta tutti gli elementi di 1 indietro
		{
			(*lis).valori[k]=(*lis).valori[k+1];
		}
		(*lis).last--;
	}
}
void stat_cancella_in_coda(struct slista *lis)//cancella la coda
{
	(*lis).last--;
}
void stat_cancella_prima_occorrenza(struct slista *lis,int valore)//cancella la prima occorrenza di un certo elemento
{
	int k=0;
	int y=0;
	int trovato=0;
	while(trovato==0 && k<=(*lis).last)//scorro tutte le posizioni
	{
		if((*lis).valori[k]==valore)//appena trovo l'elemento che cercavo
		{
			y=k;
			while(y<(*lis).last)//sposto da li in poi la lista indietro di 1
			{
				(*lis).valori[y]=(*lis).valori[y+1];
				y++;
			}
			(*lis).last--;//decremento l'indice dell'ultimo elemento
			trovato=1;//assegno alla variabile trovato 1, cosicchè il ciclo while si interrompa
		}
		k++;
	}
}
void stat_cancella_tutte_occorenze(struct slista *lis,int valore)
{
	int k=0;
	int y=0;
	while(k<=(*lis).last)
	{
		if((*lis).valori[k]==valore)//se l'elemento in posizione k corrisponde a quello da eliminare
		{
			y=k;
			while(y<(*lis).last)//scorro tutti gli elementi da li in poi indietro di 1
			{
				(*lis).valori[y]=(*lis).valori[y+1];
				y++;
			}
			(*lis).last--;//decremento di 1 l'indice dell'ultima posizione
			k--;//e decremento k, così da non perdermi nessun elemento
		}
		k++;
	}
}
void stat_stampa(struct slista *lis)//stampa tutti gli elemento della lista
{
	int k=0;
	while(k<=(*lis).last)
	{
		printf("%d\t",(*lis).valori[k]);
		k++;
	}
}
int stat_lunghezza(struct slista* lis)//restituisce la lunghezza della lista
{
	return (*lis).last+1;
}
int stat_presenza(struct slista*lis,int val)//restituisce 1 se la lista non è vuota, altrimenti 0
{
	int k=0;
	for(k;k<=(*lis).last;k++)
	{
		if((*lis).valori[k]==val)
		{
			return 1;
		}
	}
	return 0;
}
