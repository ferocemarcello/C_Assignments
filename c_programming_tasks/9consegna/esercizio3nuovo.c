#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int cellainizio=0;//indica la lunghezza del puntatore a studente, varia con l'inserimento e con l'eliminazione di studenti
typedef struct
{
	int matricola;
	char*nome;
	char*cognome;
	int nascita[3];//giorno mese anno
	char sesso;
	int esami[6];
	int voti[6];
	int numesami;//numero di esami
}studente;
studente *studenti;
void inserimento()//funzione per inserire nuovi studenti(incompleta)
{
	int k=0;//indicatore studente
	int n=0;//numero di studenti
	int s=0;//indicatore lettera nome
	int nesami=0;//numero di esami ciascun studente
	int z=0;//indicatore esame
	int es=0;//intero che indica l'esame
	char c;//carattere per leggere il nome ed il cognome
	printf("quanti studenti?\t");
	while(scanf("%d",&n)==0)//legge e controlla il numero di studenti
	{
		printf("digita un intero\t");
		fflush(stdin);
	}
	studenti=(studente*)realloc(studenti,n*sizeof(studente));
	if(studenti==NULL)//controllo sulla realloc
	{
		printf("spazio insufficente");
		free(studenti);
		exit(1);//esce dal programma
	}
	for(k=0;k<n;k++)//ripete il ciclo per ogni studente
	{
		printf("inserire matricola studente %d\n",k+cellainizio+1);//inizia a inserire dalla cella di indice cellainizio(lunghezza del puntatore)+k
		while(scanf("%d",&studenti[k+cellainizio].matricola)==0)
		{
			printf("digita un intero\t");
			fflush(stdin);
		}
		fflush(stdin);
		printf("inserire nome studente %d\n",k+cellainizio+1);
		s=0;
		studenti[k+cellainizio].nome=(char*)malloc(sizeof(char));
		if(studenti[k+cellainizio].nome==NULL)
		{
			printf("spazio insufficente");
			free(studenti[k+cellainizio].nome);
			exit(1);
		}
		c=getchar();
		while(c!='\n')//legge ogni carattere fino al ritorno a capo e lo inserisce nel puntatore a carattere
		{
			studenti[k+cellainizio].nome[s]=c;
			s++;
			studenti[k+cellainizio].nome=(char*)realloc(studenti[k+cellainizio].nome,(s+1)*sizeof(char));//rialloco lo spazio per un altro carattere,do spazio anche per il terminatore di stringa
			if(studenti[k+cellainizio].nome==NULL)
			{
				printf("spazio insufficente");
				free(studenti[k+cellainizio].nome);
				exit(1);
			}
			c=getchar();
		}
		studenti[k+cellainizio].nome[s]='\0';
		printf("inserire cognome studente %d\n",k+cellainizio+1);
		s=0;
		studenti[k+cellainizio].cognome=(char*)malloc(sizeof(char));
		if(studenti[k+cellainizio].cognome==NULL)
		{
			printf("spazio insufficente");
			free(studenti[k+cellainizio].cognome);
			exit(1);
		}
		c=getchar();
		while(c!='\n')
		{
			studenti[k+cellainizio].cognome[s]=c;
			s++;
			studenti[k+cellainizio].cognome=(char*)realloc(studenti[k+cellainizio].cognome,(s+1)*sizeof(char));
			if(studenti[k+cellainizio].cognome==NULL)
			{
				printf("spazio insufficente");
				free(studenti[k+cellainizio].cognome);
				exit(1);
			}
			c=getchar();
		}
		studenti[k+cellainizio].cognome[s]='\0';
		printf("inserire giorno del mese di nascita studente %d\n",k+cellainizio+1);
		while(scanf("%d",&studenti[k+cellainizio].nascita[0])==0 ||studenti[k+cellainizio].nascita[0]<1||studenti[k+cellainizio].nascita[0]>30 )
		{
			printf("digita un intero compreso tra 1 e 30\t");
			fflush(stdin);
		}
		fflush(stdin);
		printf("inserire mese di nascita in formato numerico studente %d\n",k+cellainizio+1);
		while(scanf("%d",&studenti[k+cellainizio].nascita[1])==0||studenti[k+cellainizio].nascita[1]<1||studenti[k+cellainizio].nascita[1]>12)
		{
			printf("digita un intero compreso tra 1 e 12\t");
			fflush(stdin);
		}
		fflush(stdin);
		printf("inserire anno di nascita studente %d\n",k+cellainizio+1);
		while(scanf("%d",&studenti[k+cellainizio].nascita[2])==0)
		{
			printf("digita un intero\t");
			fflush(stdin);
		}
		fflush(stdin);
		printf("inserisci sesso(se maschio m; se femmina f) studente %d\n",k+cellainizio+1);
		scanf("%c",&studenti[k+cellainizio].sesso);
		fflush(stdin);
		while(studenti[k+cellainizio].sesso!='m' && studenti[k+cellainizio].sesso!='f')
		{
			printf("inserisci il carattere per il sesso corretto\n");
			scanf("%c",&studenti[k+cellainizio].sesso);
			fflush(stdin);
		}
		printf("inserire numero di esami sostenuti studente %d\n",k+cellainizio+1);
		while(scanf("%d",&nesami)==0||nesami<0)
		{
			printf("digita un intero positivo\t");
			fflush(stdin);
		}
		fflush(stdin);
		studenti[k+cellainizio].numesami=nesami;
		printf("inglese\t\t\t\t1\n");
		printf("analisi\t\t\t\t2\nn");
		printf("programmazione\t\t\t3\n");
		printf("algebra e geometria\t\t4\n");
		printf("algoritmi e strutture dati\t5\n");
		printf("architettura degli elaboratori\t6\n");
		for(z=0;z<nesami;z++)
		{
			printf("inserire esame\n");
			while(scanf("%d",&es)==0||es<1||es>6)
			{
				printf("digita un intero compreso tra 1 e 6\t");
				fflush(stdin);
			}
			fflush(stdin);
			studenti[k+cellainizio].esami[z]=es;
			printf("\ninserisci voto esame\n");
			while(scanf("%d",&es)==0||es<0||es>30)
			{
				printf("digita un intero compreso tra 0 e 30\t");
				fflush(stdin);
			}
			fflush(stdin);
			studenti[k+cellainizio].voti[z]=es;
		}
	}
	cellainizio=cellainizio+k;//aumento la lunghezza del puntatore a studente a cellainizio+k
}
void cancellazione()
{
	int n=0;
	int k=0;
	int matr=0;
	int y=0;
	int u=0;//verifica se c'è almeno uno studente con quella matricola
	printf("quanti studenti?\t");//controllo se il numero in imput è maggiore del numero di studenti in archivio
	while(scanf("%d",&n)==0||n<0||n>cellainizio)
	{
		printf("digita un intero positivo minore uguale al numero di studenti gia presenti nel'archivio\t");
		fflush(stdin);
	}
	fflush(stdin);
	for(k=0;k<n;k++)
	{
		u=0;
		printf("digita la matricola dello studente che vuoi eliminare\n");
		while(scanf("%d",&matr)==0)
		{
			printf("digita un intero\t");
			fflush(stdin);
		}
		fflush(stdin);
		for(y=0;y<cellainizio;y++)
		{
			if(matr==studenti[y].matricola)
			{
				u=1;
				break;
			}
		}
		if(u==1)
		{
			studenti[y]=studenti[cellainizio-1];
		studenti=(studente*)realloc(studenti,(cellainizio-1)*sizeof(studente));
		cellainizio--;
		}
		else
		{
			printf("numero di matricola non trovato\n");
		}
	}	
}
void datistudente()
{
	int n=0;
	int k=0;
	int matr=0;
	int y=0;
	int u=0;
	printf("di quanti studenti vuoi conoscere i dati?\t");
	while(scanf("%d",&n)==0||n<0||n>cellainizio)
	{
		printf("digita un intero positivo minore uguale la numero di studenti\t");
		fflush(stdin);
	}
	fflush(stdin);
	for(k=0;k<n;k++)
	{
		printf("\ndigita la matricola dello studente\n");//richiedo la matricola per identificare lo studente
		while(scanf("%d",&matr)==0)
		{
			printf("digita un intero\t");
			fflush(stdin);
		}
		fflush(stdin);
		for(y=0;y<cellainizio;y++)
		{
			u=0;
			if(matr==studenti[y].matricola)//stampo matricola,nome, cognome, sesso
			{
				printf("matricola=%d\n",studenti[y].matricola);
				printf("nome=%s\n",studenti[y].nome);
				printf("cognome=%s\n",studenti[y].cognome);
				printf("data di nascita=%d/%d/%d\n",studenti[y].nascita[0],studenti[y].nascita[1],studenti[y].nascita[2]);
				printf("sesso=%c\n",studenti[y].sesso);
				u=1;
				break;//esco dal programma perchè la matricola è una chiave primaria
			}
		}
		if(u==0)
		{
			printf("numero di matricola non trovato");
		}
		
	}
}
void esamistudente()
{
	int n=0;
	int k=0;
	int matr=0;
	int y=0;
	int z=0;
	int u=0;
	printf("di quanti studenti vuoi conoscere gli esami sostenuti?\t");
	while(scanf("%d",&n)==0||n<0||n>cellainizio)
	{
		printf("digita un intero positivo minore uguale al numero di studenti\t");
		fflush(stdin);
	}
	fflush(stdin);
	for(k=0;k<n;k++)
	{
		printf("\ndigita la matricola dello studente\n");
		while(scanf("%d",&matr)==0)
		{
			printf("digita un intero\t");
			fflush(stdin);
		}
		fflush(stdin);
		for(y=0;y<cellainizio;y++)
		{
			u=0;
			if(matr==studenti[y].matricola)
			{
				for(z=0;z<studenti[y].numesami;z++)
				{
					printf("esame %d",studenti[y].esami[z]);
					switch(studenti[y].esami[z])//stampo l'esame corrispondente
					{
						case(1):
						{
							printf("\tinglese");break;
						}
						case(2):
						{
							printf("\tanalisi");break;
						}
						case(3):
						{
							printf("\tprogrammazione");break;
						}
						case(4):
						{
							printf("\talgebra e geometria");break;
						}
						case(5):
						{
							printf("\tarchitettura degli elaboratori");break;
						}
						case(6):
						{
							printf("\talgoritmi e strutture dati");break;
						}
					}
					printf("\tvoto:%d\n",studenti[y].voti[z]);//stampo il voto dell'esame
				}
				u=1;
				break;
			}
			if(u==0)
			{
				printf("numero di matricola non trovato");
			}
		}
		
	}
}
void studentinonesame()
{
	int es=0;
	int k=0;
	int y=0;
	int u=0;
	printf("inglese\t\t\t\t1\n");
	printf("analisi\t\t\t\t2\nn");
	printf("programmazione\t\t\t3\n");
	printf("algebra e geometria\t\t4\n");
	printf("algoritmi e strutture dati\t5\n");
	printf("architettura degli elaboratori\t6\n");
	printf("inserisci l'esame di cui vuoi verificare l'assenza nel curriculum degli studenti\n");
	while(scanf("%d",&es)==0|| es<1||es>6)
	{
		printf("digita un intero compreso tra 1 e 6\t");
		fflush(stdin);
	}
	fflush(stdin);
	for(k=0;k<cellainizio;k++)
	{		//se nell'array esami non è presente l'esame richiesto, stampa lo studente che non ha sostenuto quell'esame
			if(studenti[k].esami[0]!=es&&studenti[k].esami[1]!=es&&studenti[k].esami[2]!=es&&studenti[k].esami[3]!=es&&studenti[k].esami[4]!=es&&studenti[k].esami[5]!=es)
			{
				printf("lo studente %d con matricola %d non ha fatto l'esame\n",k+1,studenti[k].matricola);
				u=1;
			}
	}
	if(u==0)
	{
		printf("tutti gli studenti hanno sostenuto l'esame");
	}
}
int menu()//funzione che, dato un menu, restituisce la scelta che si vuole fare
{
	int scelta=0;
	printf("cosa vuoi fare?\n\n");
	printf("inserire studenti\t\t\t\t\t\t1\n");
	printf("visualizzare i dati anagrafici di uno o piu' studenti\t\t2\n");
	printf("visualizzare gli esami sostenuti da uno o piu' studenti\t\t3\n");
	printf("visualizzare gli studenti che non hanno sostenuto un esame\t4\n");
	printf("cancellare studenti\t\t\t\t\t\t5\n");
	printf("esci\t\t\t\t\t\t\t\t6\n");
	while(scanf("%d",&scelta)==0||scelta<1||scelta>6)
	{
		printf("digita un intero compreso tra 1 e 6\t");
		fflush(stdin);
	}
	fflush(stdin);
	return scelta;
}
int main()
{
	int k=0;
	int scelta=0;
	studenti=(studente*)malloc(sizeof(studente));
	if(studenti==NULL)
	{
		printf("spazio insufficente");
		free(studenti);
		exit(1);
	}
	printf("in questo momento l'archivio e' vuoto.\n");
	scelta=menu();
	while(scelta!=6)//a seconda del valore restituito dalla funzione menu, eseguo una diversa funzione
	{
		switch(scelta)
		{
			case(1):
			{
				inserimento();break;
			}
			case(2):
			{
				datistudente();break;
			}
			case(3):
			{
				esamistudente();break;
			}
			case(4):
			{
				studentinonesame();break;
			}
			case(5):
			{
				cancellazione();break;
			}
		}
		scelta=menu();
	}
	return 0;
}
