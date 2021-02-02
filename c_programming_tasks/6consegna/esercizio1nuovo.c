#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a,*pa;//dichiaro una variabile intero ed un puntatore ad intero
	char c, *pc;//dichiaro una variabile carattere ed un puntatore a carattere
	float f,*pf;//dichiaro una variabile float ed un puntatore a float
	char vet [3];
	pa=&a;//assegno al puntatore ad intero l'indirizzo di memoria della variabile intero
	pc=&c;//assegno al puntatore a carattere l'indirizzo di memoria della variabile intero
	pf=&f;//assegno al puntatore a float l'indirizzo di memoria della variabile float
	a=10;
	c='t';
	f=43.221;
	printf("\nil valore dell'intero e' : %d",*pa);//stampo il valore delle variabili attraverso i puntatori
	printf("\nil carattere e' : %c",*pc);
	printf("\nil valore del float e' : %g",*pf);
	return 0;
}
