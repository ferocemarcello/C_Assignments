#include<stdio.h>
#include<stdlib.h>
struct studente
{
	int matricola;
	char*nome;
	char*cognome;
	int nascita[3];//giorno mese anno
	char sesso;
	int esami[6];
	int voti[6];
	int numesami;//numero di esami
	struct studente*next;
};
struct anno
{
	int datanno;
	int numero_programmato;//numero degli studenti per il numero programmato, se previsto
	int numstud;
	struct studente*stud;
	struct anno*next;
};
void initlista(struct anno**Tanno,struct anno**Canno)
{
	*Tanno=NULL;
	*Canno=NULL;
}
int menu()//funzione che, dato un menu, restituisce la scelta che si vuole fare
{
	int scelta=0;
	printf("cosa vuoi fare?\n\n");
	printf("1\tinserire un nuovo anno accademico\n");
	printf("2\tinserire un nuovo studente\n");
	printf("3\tcancellare uno studente\n");
	printf("4\tvisualizzare tutti gli studenti\n");
	printf("5\tvisualizzare uno studente\n");
	printf("6\tvisualizzare tutti gli studenti che non hanno sostenuto un esame\n");
	printf("7\tvisualizzare l'anno accademico con la media voti piu' alta\n");
	printf("8\tesci\n");
	while(scanf("%d",&scelta)==0||scelta<1||scelta>8)//controllo sull'imput
	{
		printf("digita un intero compreso tra 1 e 8\t");
		fflush(stdin);
	}
	fflush(stdin);
	return scelta;
}
void nuovoanno(struct anno**Tanno,struct anno**Canno)//funzione per creare una nuova cella della lista dinamica(inserimento in testa)
{
	int anno;
	int numpr=0;
	int num=0;
	int scelta=0;
	int trovato=0;
	struct anno*tmp;//puntatore temporaneo alla struttura principale anno;
	struct anno*nuovo;
	nuovo=(struct anno*)malloc(sizeof(struct anno));
	if(nuovo==NULL)
	{
		printf("spazio insufficiente");
		free(nuovo);
		return;
	}
	printf("quale anno accademico si vuole inserire?");
	while(scanf("%d",&anno)==0||anno<1088||anno>2014)//controllo sull'input
	{
		printf("digita un intero per l'anno compreso tra 1088 e 2014");
		fflush(stdin);
	}
	fflush(stdin);
	tmp=*Tanno;
	if(*Tanno!=NULL)
	{
		while(tmp!=NULL&&trovato==0)
		{
			if(tmp->datanno==anno)
			{
				trovato=1;
			}
			else
			{
				tmp=tmp->next;
			}
		}
		if(trovato==1)
		{
			printf("anno accademico gia' esistente\n");
			return;
		}
	}
	nuovo->numstud=0;//inizializzo il numero di studenti uguale a 0
	nuovo->datanno=anno;//assegno alla variabile datanno, parte della struttura anno
	printf("numero programmato(0 per si, 1 per no)?:\n");
	while(scanf("%d",&scelta)==0||(scelta!=1&&scelta!=0))
	{
		printf("digita 1 o 0\n");
		fflush(stdin);
	}
	fflush(stdin);
	if(scelta==0)
	{
		printf("quant'e' il numero progammato?\n");
		while(scanf("%d",&numpr)==0||numpr<=0)
		{
			printf("digita un intero posiivo\n");
			fflush(stdin);
		}
		fflush(stdin);
		nuovo->numero_programmato=numpr;
	}
	else
	{
		nuovo->numero_programmato=0;
	}
	nuovo->stud=NULL;//assegno a null il puntatore alla lista degli studenti
	nuovo->next=*Tanno;
	*Tanno=nuovo;//faccio diventare la nuova testa, la nuova cella
	if((*Canno)==NULL)
	{
		(*Canno)=nuovo;
	}
}
void nuovostudente(struct anno**Tanno,struct anno**Canno)
{
	int anno;
	int trovato=0;
	struct anno*tmp;
	struct studente*tmp2;
	struct studente*nuovo=(struct studente*)malloc(sizeof(struct studente));
	if(nuovo==NULL)
	{
		printf("spazio insufficiente");
		free(nuovo);
		return;
	}
	char c;
	int s=0;
	int nesami=0;
	int z=0;
	int es=0;
	int matr=0;
	if((*Tanno)==NULL)
	{
		printf("lista vuota\n");
		return;
	}
	printf("in quale anno accademico si vuole inserire lo studente?");
	while(scanf("%d",&anno)==0||anno<1800||anno>2014)
	{
		printf("digita un intero per l'anno compreso tra 1800 e 2014");
		fflush(stdin);
	}
	fflush(stdin);
	tmp=(*Tanno);
	while(tmp!=NULL&&trovato==0)
	{
		if(tmp->datanno==anno)
		{
			trovato=1;
		}
		if(trovato==0)
		{
			tmp=tmp->next;
		}
	}
	if(trovato==0)
	{
		printf("anno accademico non trovato\n");
		return;
	}
	if(tmp->numero_programmato==tmp->numstud&&tmp->numero_programmato>0)//verifico che il numero di studenti non ecceda il numero programmato
	{
		printf("impossibile inserire altri studenti perche' il numero attuale degli studenti e' uguale al numero programmato\n");
		return;
	}
	else
	{
		tmp->numstud++;//aumento il numero di studenti di un preciso anno accademico
	}
	printf("inserire matricola studente\n");//inizia a inserire dalla cella di indice cellainizio(lunghezza del puntatore)+k
	while(scanf("%d",&matr)==0)
	{
		printf("digita un intero\t");
		fflush(stdin);
	}
	fflush(stdin);
	trovato=0;
	tmp2=tmp->stud;
	while(tmp2!=NULL&&trovato==0)//controllo che la matricola non sia già esistente
	{
		if(tmp2->matricola==matr)
		{
			trovato=1;
		}
		if(trovato==0)
		{
			tmp2=tmp2->next;
		}
	}
	if(trovato==1)
	{
		printf("matricola gia' esistente\n");
		return;
	}
	nuovo->matricola=matr;
	printf("inserire nome studente\n");
	s=0;
	nuovo->nome=(char*)malloc(sizeof(char));
	if(nuovo->nome==NULL)
	{
		printf("spazio insufficente");
		free(nuovo->nome);
		return;
	}
	c=getchar();
	while(c!='\n')//legge ogni carattere fino al ritorno a capo e lo inserisce nel puntatore a carattere
	{
		nuovo->nome[s]=c;
		s++;
		nuovo->nome=(char*)realloc(nuovo->nome,(s+1)*sizeof(char));//rialloco lo spazio per un altro carattere,do spazio anche per il terminatore di stringa
		if(nuovo->nome==NULL)
		{
			printf("spazio insufficente");
			free(nuovo->nome);
			return;
		}
		c=getchar();
	}
	nuovo->nome[s]='\0';
	printf("inserire cognome studente \n");
	s=0;
	nuovo->cognome=(char*)malloc(sizeof(char));
	if(nuovo->cognome==NULL)
	{
		printf("spazio insufficente");
		free(nuovo->cognome);
		return;
	}
	c=getchar();
	while(c!='\n')
	{
		nuovo->cognome[s]=c;
		s++;
		nuovo->cognome=(char*)realloc(nuovo->cognome,(s+1)*sizeof(char));
		if(nuovo->cognome==NULL)
		{
			printf("spazio insufficente");
			free(nuovo->cognome);
			return;
		}
		c=getchar();
	}
	nuovo->cognome[s]='\0';
	printf("inserire giorno del mese di nascita studente\n");
	while(scanf("%d",&nuovo->nascita[0])==0 ||nuovo->nascita[0]<1||nuovo->nascita[0]>30 )
	{
		printf("digita un intero compreso tra 1 e 30\t");
		fflush(stdin);
	}
	fflush(stdin);
	printf("inserire mese di nascita in formato numerico studente\n");
	while(scanf("%d",&nuovo->nascita[1])==0||nuovo->nascita[1]<1||nuovo->nascita[1]>12)
	{
		printf("digita un intero compreso tra 1 e 12\t");
		fflush(stdin);
	}
	fflush(stdin);
	printf("inserire anno di nascita studente\n");
	while(scanf("%d",&nuovo->nascita[2])==0||nuovo->nascita[2]<1930)
	{
		printf("digita un intero maggiore uguale a 1930\t");
		fflush(stdin);
	}
	fflush(stdin);
	printf("inserisci sesso(se maschio m; se femmina f) studente\n");
	scanf("%c",&nuovo->sesso);
	fflush(stdin);
	while(nuovo->sesso!='m' && nuovo->sesso!='f')
	{
		printf("inserisci il carattere per il sesso corretto\n");
		scanf("%c",&nuovo->sesso);
		fflush(stdin);
	}
	printf("inserire numero di esami sostenuti studente\n");
	while(scanf("%d",&nesami)==0||nesami<0)
	{
		printf("digita un intero positivo\t");
		fflush(stdin);
	}
	fflush(stdin);
	nuovo->numesami=nesami;
	printf("\t1inglese\n");
	printf("\t2analisi\n");
	printf("\t3programmazione\n");
	printf("\t4algebra e geometria\n");
	printf("\t5algoritmi e strutture dati\n");
	printf("\t6architettura degli elaboratori\n");
	for(z=0;z<nesami;z++)
	{
		printf("inserire esame\n");
		while(scanf("%d",&es)==0||es<1||es>6)
		{
			printf("digita un intero compreso tra 1 e 6\t");
			fflush(stdin);
		}
		fflush(stdin);
		nuovo->esami[z]=es;
		printf("\ninserisci voto esame\n");
		while(scanf("%d",&es)==0||es<0||es>30)
		{
			printf("digita un intero compreso tra 0 e 30\t");
			fflush(stdin);
		}
		fflush(stdin);
		nuovo->voti[z]=es;
	}
	nuovo->next=tmp->stud;
	tmp->stud=nuovo;
}
void cancellastud(struct anno**Tanno,struct anno**Canno)
{
	int anno;
	int trovato=0;
	struct anno*tmp;
	struct studente*tmp2;
	struct studente*tmp3;
	int matr=0;
	if((*Tanno)==NULL)
	{
		printf("lista vuota\n");
		return;
	}
	printf("in quale anno accademico si vuole cancellare lo studente?");
	while(scanf("%d",&anno)==0||anno<1800||anno>2014)
	{
		printf("digita un intero per l'anno compreso tra 1800 e 2014");
		fflush(stdin);
	}
	fflush(stdin);
	tmp=(*Tanno);
	while(tmp!=NULL&&trovato==0)//controllo che esista l'anno cercato
	{
		if(tmp->datanno==anno)
		{
			trovato=1;
		}
		if(trovato==0)
		{
			tmp=tmp->next;
		}
	}
	if(trovato==0)
	{
		printf("anno accademico non trovato\n");
		return;
	}
	if(tmp->numstud==0)
	{
		printf("numero di studenti=0\n");
		return;
	}
	printf("inserire matricola studente\n");//inizia a inserire dalla cella di indice cellainizio(lunghezza del puntatore)+k
	while(scanf("%d",&matr)==0)
	{
		printf("digita un intero\t");
		fflush(stdin);
	}
	fflush(stdin);
	tmp2=tmp->stud;
	trovato=0;
	while(tmp2!=NULL&&trovato==0)//controllo che esista la matricola cercata
	{
		if(tmp2->matricola==matr)
		{
			trovato=1;
			tmp->numstud--;
		}
		if(trovato==0)
		{
			tmp2=tmp2->next;
		}
	}
	if(trovato==0)
	{
		printf("matricola non trovata\n");
		return;
	}
	trovato=0;
	tmp2=tmp->stud;
	if(tmp2->matricola==matr)
	{
		tmp3=tmp2->next;
		free(tmp2);//libero la memoria
		tmp->stud=tmp3;
	}
	else
	{
		tmp3=tmp2->next;
		while(tmp3!=NULL&&trovato==0)
		{
			if(tmp3->matricola==matr)
			{
				trovato=1;
			}
			if(trovato==0)
			{
				tmp2->next=tmp3->next;
				free(tmp3);//libero la memoria
			}
		}
	}
}
void visualizzastud(struct anno*Tanno,struct anno*Canno)
{
	int anno;
	int trovato=0;
	struct anno*tmp;
	struct studente*tmp2;
	struct studente*tmp3;
	int matr=0;
	int k=0;
	if(Tanno==NULL)
	{
		printf("lista vuota\n");
		return;
	}
	printf("in quale anno accademico si vuole visualizzare lo studente?");
	while(scanf("%d",&anno)==0||anno<1800||anno>2014)//controllo sull'input
	{
		printf("digita un intero per l'anno compreso tra 1800 e 2014");
		fflush(stdin);
	}
	fflush(stdin);
	tmp=Tanno;
	while(tmp!=NULL&&trovato==0)
	{
		if(tmp->datanno==anno)
		{
			trovato=1;
		}
		if(trovato==0)
		{
			tmp=tmp->next;
		}
	}
	if(trovato==0)
	{
		printf("anno accademico non trovato\n");
		return;
	}
	if(tmp->numstud==0)
	{
		printf("numero di studenti=0\n");
		return;
	}
	printf("inserire matricola studente\n");//inizia a inserire dalla cella di indice cellainizio(lunghezza del puntatore)+k
	while(scanf("%d",&matr)==0)
	{
		printf("digita un intero\t");
		fflush(stdin);
	}
	fflush(stdin);
	tmp2=tmp->stud;
	trovato=0;
	while(tmp2!=NULL&&trovato==0)
	{
		if(tmp2->matricola==matr)
		{
			trovato=1;
		}
		if(trovato==0)
		{
			tmp2=tmp2->next;
		}
	}
	if(trovato==0)
	{
		printf("matricola non trovata\n");
		return;
	}
	printf("anno accademico %d/%d:\n",tmp->datanno,tmp->datanno+1);
	printf("\tmatricola=%d\n",tmp2->matricola);
	printf("\tnome=%s\n",tmp2->nome);
	printf("\tcognome=%s\n",tmp2->cognome);
	printf("\tdata di nascita=%d/%d/%d\n",tmp2->nascita[0],tmp2->nascita[1],tmp2->nascita[2]);
	printf("\tsesso=%c\n",tmp2->sesso);
	for(k=0;k<tmp2->numesami;k++)
	{
		printf("esame %d=\t",k+1);
		switch(tmp2->esami[k])
		{
			case 1:printf("inglese");break;
			case 2:printf("analisi");break;
			case 3:printf("programmazione");break;
			case 4:printf("algebra e geometria");break;
			case 5:printf("algoritmi e strutture dati");break;
			case 6:printf("architettura degli elaboratori");break;
		}
		printf("\tvoto=%d\n",tmp2->voti[k]);
	}
}
void nonesame(struct anno*Tanno,struct anno*Canno)
{
	int anno;
	int trovato=0;
	struct anno*tmp;
	struct studente*tmp2;
	struct studente*tmp3;
	int es=0;
	int k=0;
	if(Tanno==NULL)
	{
		printf("lista vuota\n");
		return;
	}
	printf("in quale anno accademico si vuole visualizzare lo studente?");
	while(scanf("%d",&anno)==0||anno<1800||anno>2014)//controllo sull'input
	{
		printf("digita un intero per l'anno compreso tra 1800 e 2014");
		fflush(stdin);
	}
	fflush(stdin);
	tmp=Tanno;
	while(tmp!=NULL&&trovato==0)
	{
		if(tmp->datanno==anno)
		{
			trovato=1;
		}
		if(trovato==0)
		{
			tmp=tmp->next;
		}
	}
	if(trovato==0)
	{
		printf("anno accademico non trovato\n");
		return;
	}
	if(tmp->numstud==0)
	{
		printf("numero di studenti=0\n");
		return;
	}
	printf("inglese\t\t\t\t1\n");
	printf("analisi\t\t\t\t2\n");
	printf("programmazione\t\t\t3\n");
	printf("algebra e geometria\t\t4\n");
	printf("algoritmi e strutture dati\t5\n");
	printf("architettura degli elaboratori\t6\n");
	printf("inserire esame\n");
	while(scanf("%d",&es)==0||es<1||es>6)
	{
		printf("digita un intero compreso tra 1 e 6\t");
		fflush(stdin);
	}
	fflush(stdin);
	tmp2=tmp->stud;
	while(tmp2!=NULL)
	{
		k=0;
		trovato=0;
		while(k<tmp2->numesami)
		{
			if(tmp2->esami[k]!=es)
			{
				trovato++;
			}
			k++;
		}
		if(trovato==tmp2->numesami)
		{
			printf("matricola=%d\n",tmp2->matricola);
		}
		tmp2=tmp2->next;
	}
	
}
void visualizzatutto(struct anno*Tanno,struct anno*Canno)
{
	struct anno*tmp;
	struct studente*tmp2;
	int k=1;
	int z=0;
	tmp=Tanno;
	while(tmp!=NULL)//scorro tutti gli anni
	{
		printf("anno %d=%d/%d\n",k,tmp->datanno,tmp->datanno+1);
		tmp2=tmp->stud;
		z=1;
		while(tmp2!=NULL)//scorro tutti gli studenti di un anno
		{
			printf("\tstudente %d: matricola=%d\n",z,tmp2->matricola);
			tmp2=tmp2->next;
			z++;
		}
		k++;
		tmp=tmp->next;
	}
}
void maxanno(struct anno*Tanno,struct anno*Canno)//funzione che stampa l'anno accademico con la media voti più alta
{
	struct anno*tmp;
	struct studente*tmp2;
	float medianno=0;
	float mediastud=0;
	float maxmedia=0;
	int maxanno=0;
	int sommavotistud=0;
	int sommavotianno=0;
	int k=0;
	int z=0;
	tmp=Tanno;
	if(Tanno==NULL)
	{
		printf("lista vuota");
		return;
	}
	while(tmp!=NULL)
	{
		tmp2=tmp->stud;
		medianno=0;
		sommavotianno=0;
		z=0;
		while(tmp2!=NULL)
		{
			sommavotistud=0;
			mediastud=0;
			for(k=0;k<tmp2->numesami;k++)
			{
				sommavotistud+=tmp2->voti[k];
			}
			mediastud=sommavotistud/tmp2->numesami;
			sommavotianno+=sommavotistud;
			tmp2=tmp2->next;
			z++;
		}
		medianno=sommavotianno/z;
		if(medianno>=maxmedia)
		{
			maxmedia=medianno;
			maxanno=tmp->datanno;
		}
		tmp=tmp->next;
	}
	printf("l'anno con la media voti piu' alta e' l'anno %d/%d\n",maxanno,maxanno+1);
}
