#include<stdio.h>
#include<stdlib.h>

#define MAX 20
struct part{
int **codicev;
int quantita;
int *codicep;
}mercato[MAX];
void vendite(int periodo)
{
	
}
int main()
{
	int k=0;
	srand((unsigned int) time(NULL));
	for(k=0;k<MAX;k++)
	{
		
	}
	for(k=0;k<MAX;k++)
	{
		mercato[k].codicev=k;
		mercato[k].codicep=k;
		mercato[k].quantita=rand()%50;
		printf("codicev[%d]=%d\tcodicep[%d]=%d\tquantita[%d]=%d\n",k,mercato[k].codicev,k,mercato[k].codicep,k,mercato[k].quantita);
	}
	return 0;
}
