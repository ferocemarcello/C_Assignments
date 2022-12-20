#include<stdio.h>
#include<stdlib.h>
#define N_MAT 5
#define MAX_STUD 50
#define VOTOMIN 1
#define VOTOMAX 11
#define SUFF 6
#define TRUE 1
#define FALSE 0

//studenti
struct
{
	char cognome[50];
	char nome[50];
	int matricola;
	int anno_di_corso;
	float voto[N_MAT];//elenco dei voti dello studente nelle diverse materie
}studi[MAX_STUD];
	
//materie
struct smateria
{
	int codice;
	char descr[50];
	char docente[50];
}materia[N_MAT]={{1,"lettere","rossi"},{2,"matematica","monti"},{3,"inglese","smith"},{4,"diritto","bianchi"},{5,"fisica","verdi"}};

struct smateria programmazione;
int main()
{
	float media,somma;
	char next,trovato;
	int i,j,nstud,matricola,num_insuff;
	//inizializzazione dimensioni
	do
		{
			printf("quanti studenti max%d)?",MAX_STUD);
			scanf("%d",&nstud);
		}
	while(nstud>MAX_STUD||nstud<=0);
	//inserimento studenti e voti
	printf("\n\ninserimento studenti e voti...\n");
	for(i=0;i<nstud;i++)
	{
		printf("\nstudente[%d]:\n",i);
		printf("matricola: ");
		scanf("%d",&nstud[i].matricola);
		printf("nome: ");
		scanf("%s",nstud[i].nome);
		printf("cognome: ");
	}
	
	return 0;	
}
	
	

