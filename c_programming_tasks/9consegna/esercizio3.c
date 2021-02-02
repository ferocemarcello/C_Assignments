#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct sstudente
{
	int matricola;
	char nome[30];
	char cognome[30];
	int nascita[3];//giorno mese anno
	char sesso;
	char**esami;
	int*voti;
	
}studente[5000];
int main()
{
	//studente:matricola,nome,cognome,data di nascita,sesso,esami sostenuti,voto esami
	int n=0;
	int nesami=0;
	int k=0;
	int z=0;
	char risposta;
	char c;
	int cellainizio=0;
	int lungesame=0;
	int nmatr=0;
	printf("in questo momento l'archivio e' vuoto.\n vuoi inserire dati relativi ad uno o piu' studenti?\n rispondere con un si o con un no\n");
	scanf("%c",&risposta);
	fflush(stdin);
	risposta=tolower(risposta);
	if(risposta=='s')
	{
		printf("quanti studenti?\n");
		scanf("%d",&n);
		fflush(stdin);
	}
	if(n!=0)
	{
		for(k=0;k<n;k++)
		{
			printf("inserire matricola studente %d\n",k+1);
			scanf("%d",&studente[k].matricola);
			fflush(stdin);
			printf("inserire nome studente %d\n",k+1);
			scanf("%s",&studente[k].nome);
			fflush(stdin);
			printf("inserire cognome studente %d\n",k+1);
			scanf("%s",&studente[k].cognome);
			fflush(stdin);
			printf("inserire giorno del mese di nascita studente %d\n",k+1);
			scanf("%d",&studente[k].nascita[0]);
			fflush(stdin);
			printf("inserire mese di nascita in formato numerico studente %d\n",k+1);
			scanf("%d",&studente[k].nascita[1]);
			fflush(stdin);
			printf("inserire anno di nascita studente %d\n",k+1);
			scanf("%d",&studente[k].nascita[2]);
			fflush(stdin);
			printf("inserisci sesso(se maschio m; se femmina f) studente %d\n",k+1);
			scanf("%c",&studente[k].sesso);
			fflush(stdin);
			printf("inserire numero di esami sostenuti studente %d\n",k+1);
			scanf("%d",&nesami);
			fflush(stdin);
			studente[k].esami=(char**)malloc(nesami*sizeof(char*));
			studente[k].voti=(int*)malloc(nesami*sizeof(int));
			for(z=0;z<nesami;z++)
			{
				printf("inserire nome esame %d\n",z+1);
				c=getchar();
				lungesame=1;
				studente[k].esami[z]=(char*)malloc(lungesame*sizeof(char));
				while(c!='\n')
				{
					studente[k].esami[z]=(char*)realloc(studente[k].esami[z],lungesame*sizeof(char));
					studente[k].esami[z][lungesame-1]=c;
					lungesame++;
					c=getchar();
				}
				printf("\ninserisci voto esame\n");
				scanf("%d",&studente[k].voti[z]);
				fflush(stdin);
			}
		}
		cellainizio+=k;
	}
	printf("vuoi inserire altri dati relativi ad uno o piu' studenti?\n rispondere con un si o con un no\n");
	scanf("%c",&risposta);
	fflush(stdin);
	risposta=tolower(risposta);
	while(risposta=='s')
	{
		printf("quanti studenti?\n");
		scanf("%d",&n);
		fflush(stdin);
		for(k=0;k<n;k++)
		{
			printf("inserire matricola studente %d\n",k+1);
			scanf("%d",&studente[k+cellainizio].matricola);
			fflush(stdin);
			printf("inserire nome studente %d\n",k+1);
			scanf("%s",&studente[k+cellainizio].nome);
			fflush(stdin);
			printf("inserire cognome studente %d\n",k+1);
			scanf("%s",&studente[k+cellainizio].cognome);
			fflush(stdin);
			printf("inserire giorno del mese di nascita studente %d\n",k+1);
			scanf("%d",&studente[k+cellainizio].nascita[0]);
			fflush(stdin);
			printf("inserire mese di nascita in formato numerico studente %d\n",k+1);
			scanf("%d",&studente[k+cellainizio].nascita[1]);
			fflush(stdin);
			printf("inserire anno di nascita studente %d\n",k+1);
			scanf("%d",&studente[k+cellainizio].nascita[2]);
			fflush(stdin);
			printf("inserisci sesso(se maschio m; se femmina f) studente %d\n",k+1);
			scanf("%c",&studente[k+cellainizio].sesso);
			fflush(stdin);
			printf("inserire numero di esami sostenuti studente %d\n",k+1);
			scanf("%d",&nesami);
			fflush(stdin);
			studente[k+cellainizio].esami=(char**)malloc(nesami*sizeof(char*));
			studente[k+cellainizio].voti=(int*)malloc(nesami*sizeof(int));
			for(z=0;z<nesami;z++)
			{
				printf("inserire nome esame %d\n",z+1);
				c=getchar();
				lungesame=1;
				studente[k+cellainizio].esami[z]=(char*)malloc(lungesame*sizeof(char));
				while(c!='\n')
				{
					studente[k+cellainizio].esami[z]=(char*)realloc(studente[k+cellainizio].esami[z],lungesame*sizeof(char));
					studente[k+cellainizio].esami[z][lungesame-1]=c;
					lungesame++;
					c=getchar();
				}
				printf("\ninserisci voto esame\n");
				scanf("%d",&studente[k+cellainizio].voti[z]);
				fflush(stdin);
			}
		}
		cellainizio+=k;
		printf("vuoi inserire altri dati relativi ad uno o piu' studenti?\n rispondere con un si o con un no\n");
		scanf("%c",&risposta);
		fflush(stdin);
		risposta=tolower(risposta);
	}
	printf("vuoi cancellare uno studente?\n rispondere con un si o con un no\n");
	scanf("%c",&risposta);
	fflush(stdin);
	risposta=tolower(risposta);
	while(risposta=='s')
	{
		printf("digita il suo numero di matricola\n");
		scanf("%d",&nmatr);
		fflush(stdin);
		for(k=0;k<cellainizio;k++)
		{
			if(nmatr==studente[k].matricola)
			{
				break;
			}
		}
		for(k;k<cellainizio;k++)
		{
			studente[k].matricola=studente[k+1].matricola;
			studente[k].nome=studente[k+1].nome;
			studente[k].cognome=studente[k+1].cognome;
			studente[k].nascita=studente[k+1].nascita;
			studente[k].sesso=studente[k+1].sesso;
			studente[k].esami=studente[k+1].esami;
			studente[k].voti=studente[k+1].voti;
		}
		cellainizio--;
		printf("vuoi cancellare un altro studente?\n rispondere con un si o con un no\n");
		scanf("%c",&risposta);
		fflush(stdin);
		risposta=tolower(risposta);
	}
	return 0;
}
