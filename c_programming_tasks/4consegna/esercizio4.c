//marcello feroce primo anno ingegneria e scienze informatiche
#include<stdio.h>
#include<stdlib.h>

int main()
{
	float num;
	int migliaia,centinaia,decine,unita;//definisco come interi il numero delle migliaia, centinaia, decine, unità
	printf("inserisci un numero intero");
	scanf("%f",&num);
	while(num!=(int)num)
	{
		printf("il numero digitato deve essere intero\n");//controllo affinchè il valore di num sia corretto
		printf("digita un altro numero");scanf("%f",&num);
	}
	num=abs(num);//funzione per il valore assoluto di un numero
	migliaia=(int)num/1000;//calcolo il numero delle migliaia
	num=(int)num-migliaia*1000;//al numero iniziale sottraggo la parte che eccede il valore di 1000(migliaia*1000)
	centinaia=(int)num/100;//calcolo il numero delle centinaia
	num=(int)num-centinaia*100;//al numero iniziale sottraggo la parte che eccede il valore di 100(centinaia*100)
	decine=(int)num/10;//calcolo il numero delle decine
	num=(int)num-decine*10;//al numero iniziale sottraggo la parte che eccede il valore di 10(decine*10)
	unita=(int)num/1;//calcolo il numero delle unità
	printf("\nmigliaia:%d",migliaia);//stampo il valore delle migliaia
	printf("\ncentinaia:%d",centinaia);//stampo il valore delle centinaia;
	printf("\ndecine:%d",decine);//stampo il valore delle decine
	printf("\nunita':%d",unita);//stampo il valore delle unità
	return 0;
}
