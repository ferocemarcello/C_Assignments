#include<stdio.h>
#include<stdlib.h>
/*do{
	s=scanf("%c%c",&a,&n);
	
	
}while(s!=2 || n!='\n')*/
int main()
{
	int a,b,*pa;//dichiaro una variabile intero ed un puntatore ad intero
	char c,d,*pc;//dichiaro una variabile carattere ed un puntatore a carattere
	float f,*pf;//dichiaro una variabile float ed un puntatore a float
	char vet [3];
	pa=&a;//assegno al puntatore ad intero l'indirizzo di memoria della variabile intero
	pc=&c;//assegno al puntatore a carattere l'indirizzo di memoria della variabile intero
	pf=&f;//assegno al puntatore a float l'indirizzo di memoria della variabile float
	printf("Inserisci il valore dell'intero \n");
	b=scanf("%f",&f);
	fflush(stdin);
	while(b==0 || f!=(int)f)
	{
		printf("non e' un intero\ndigita un intero\n");
		b=scanf("%f",&f);
		fflush(stdin);
	}
	a=f;
	b=0;
	printf("\nInserisci un solo carattere\n");
	c=getchar();
	d=getchar();
	while(d!='\n')
	{
		d=getchar();
		if(d=='\n')
		{
			printf("hai scritto piu' di un carattere.riscrivi\n");
			c=getchar();
			d=getchar();
		}
	}
	fflush(stdin);
	printf("\ninserisci il valore del float: ");
	b=scanf("%f",&f);
	fflush(stdin);
	while(b==0)
	{
		printf("non e' un float\ndigita un float\n");
		b=scanf("%f",&f);
		fflush(stdin);
	}
	printf("\nil valore dell'intero e' : %d",*pa);//stampo il valore delle variabili attraverso i puntatori
	printf("\nil carattere e' : %c",*pc);
	printf("\nil valore del float e' : %g",*pf);
	return 0;
}
