#include <stdio.h>
#include <stdlib.h>
//CALCOLO del quadrato di un intero senza usare l'operazione di moltiplicazione, senza cicli iterativi, la funzione deve avere un solo parametro
//4^2=3^2+4+(4-1)
int quadrato(int misura)
{
	misura=misura<0?-misura:misura;
	if(misura<=1) return 1;
	else
	{
		return(quadrato(misura-1)+misura+misura-1);
	}
}
int main()
{
	int dato=0;
	printf("digita un numero\n");
	scanf("%d",&dato);
	printf("il quadrato e' %d",quadrato(dato));
	return 0;
}
