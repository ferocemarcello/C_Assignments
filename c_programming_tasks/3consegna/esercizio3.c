//marcello feroce primo anno ingegneria e scienze informatiche matricola numero 0000730777
#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("digita il numero degli studenti\n");
	float numero_studenti;
	float voto_tot;
	float voto_singolo;
	int k;
	float media;
	scanf("%f",&numero_studenti);
	while(numero_studenti<0 || numero_studenti!=(int)numero_studenti)
	{
		printf("il numero digitato deve essere intero e non negativo\n");//controllo affinchè il valore del numero degli studenti sia corretto
		printf("digita un altro numero");scanf("%f",&numero_studenti);
	}
	k=1;
	for(k;k<=numero_studenti;k++)//ciclo for che si ripete per un numero di volte pari a la variabile int numero_studenti
	{
		printf("voto dello studente %d?\t\n",k);scanf("%f",&voto_singolo);//richiede il voto di un particolare studente
		while(voto_singolo<0 || voto_singolo>10)//controllo che il voto sia compreso tra 0 e 10
		{
			printf("il voto digitato deve essere compreso tra 0 e 10\n");
			printf("digita un altro valore per il voto\n");scanf("%f",&voto_singolo);
		}
	voto_tot=voto_tot+voto_singolo;
	}
	media=voto_tot/numero_studenti;
	printf("\nla media voto e' %g\n",media);
	voto_tot=0;
	k=1;
	while(k<=numero_studenti)//ciclo for che si ripete per un numero di volte pari a la variabile int numero_studenti
	{
		printf("voto dello studente %d?\t\n",k);scanf("%f",&voto_singolo);//richiede il voto di un particolare studente
		while(voto_singolo<0 || voto_singolo>10)//controllo che il voto sia compreso tra 0 e 10
		{
			printf("il voto digitato deve essere compreso tra 0 e 10\n");
			printf("digita un altro valore per il voto\n");scanf("%f",&voto_singolo);
		}
		voto_tot=voto_tot+voto_singolo;k=k+1;
	}
	media=voto_tot/numero_studenti;
	printf("\nla media voto e' %g",media);
	return 0;
}
