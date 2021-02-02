#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void muovi(int n, char da, char a, char mez)
{
	//trasferisce ndischi dal paletto da al paletto a,usando mez come paletto temporaneo 
	if(n==0)
	return;
	else
	{
		/* sposta n-1 dischi dall’origine alla sosta temporanea */
		muovi(n-1,da,mez,a);
		/* sposta il disco n-esimo dall’origine alla destinazione */
		printf("Sposta il disco %d da %c a %c\n",n,da,a);
		/* sposta n-1 dischi dalla sosta temporanea alla destinazione*/
		muovi(n-1,mez,a,da);
	}
}
int main()
{
	int dischi=0;
	printf("di quanti dischi vuoi disporre per risolvere il gioco delle torri di Hanoi?\t");
	scanf("%d",&dischi);
	printf("\ndischi numerati ed impilati per ordine crescente di grandezza da 1 a %d(il disco piu grande sta in fondo ed e' il disco %d).\nA e' il paletto di sinistra, B il paletto al centro, C il paletto a destra\nnumero minimo di mosse= %g\n\nRISOLUZIONE:\n\n",dischi,dischi,(pow(2.0,dischi)-1));
	muovi(dischi,'A','C','B');
	return 0;
}
