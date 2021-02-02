#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int voti[200];int a=0;
	int *ptr;
	srand((unsigned int) time(NULL));
	ptr=voti;
	for(a=0;a<200;a++)//prima modalità di inizializzazione
	{
		voti[a]=rand()%31;//inserisco il valore a random da 0 a 30
	}
	for(a=0;a<200;a++)//seconda modalità di inizializzazione
	{
		ptr[a]=rand()%31;
	}
	for(a=0;a<200;a++)//prima modalità di stampa
	{
		printf("voto studente %d=%d\n",a+1,ptr[a]);
	}
	system("pause");
	for(a=0;a<200;a++)//seconda modalità di stampa
	{
		printf("voto studente %d=%d\n",a+1,*(voti+a));
	}
	system("pause");
	for(a=0;a<200;a++)//terza modalità di stampa
	{
		printf("voto studente %d=%d\n",a+1,voti[a]);
	}
	system("pause");
	for(a=0;a<200;a++)//quarta modalità di stampa
	{
		printf("voto studente %d=%d\n",a+1,*(ptr+a));
	}
	free(ptr);
	return 0;
}
