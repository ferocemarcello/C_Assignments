#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define r 2 //numero di righe
#define c 2 //numero di colonne
#define S 1000 //millisecondi di pausa
int main()
{
	int mat[r][c];
	int sommariga=0;int sommacolonna=0;int sommadiagonale1=0;int sommadiagonale2=0;int quadrato=0;/*<-condizione di realta del quadrato magico*/int k=0;int z=0;
	do
	{
		srand((int) time(NULL));
		for(k=0;k<r;k++)//stampa la matrice originale. k è l'indicatore riga
		{
			for(z=0;z<c;z++)//z è l'indicatore colonna
			{
				mat[k][z]=rand()%10;//sono disbonibili solo valori tra 0 e 9 in questo caso
				printf("%d",mat[k][z]);
			}
			puts("");
		}
		sommadiagonale1=0;
		for(k=0;k<r;k++)
		{	
			z=k;
			sommadiagonale1+=mat[k][z];//assegno il valore della somma di tutti i valori contenuti nella prima diagonale	
		}
		sommadiagonale2=0;
		for(k=0;k<r;k++)
		{	
			z=c-k-1;
			sommadiagonale2+=mat[k][z];//assegno il valore della somma di tutti i valori contenuti nella seconda diagonale	
		}
		if(sommadiagonale1==sommadiagonale2)quadrato=0;else quadrato=1;//se le diagonali sono uguali la variabile quadrato=0, altrimenti quadrato=1
		sommariga=0;
		for(z=0;z<c;z++)
		{
			sommariga+=mat[0][z];//assegno il valore della somma di tutti i valori contenuti nella prima riga	
		}
		sommacolonna=0;
		for(k=0;k<r;k++)
		{
			sommacolonna+=mat[k][0];//assegno il valore della somma di tutti i valori contenuti nella prima colonna	
		}
		for(k=1;k<r;k++)
		{
			if(sommariga==sommadiagonale1)//se sommariga=sommadiagonale1, assegno alla variabile sommariga1 il valore della somma dei valori della riga successiva
			{							//La condizione di uguaglianza si ripete per tutte le righe del quadrato
				sommariga=0;
				for(z=0;z<c;z++)
				{
					sommariga+=mat[k][z];	
				}
			}
			else {quadrato=1;break;}//se sommariga!=sommadiagonale1 assegno a quadrato,1. La condizione di realta del quadrato magico è quindi falsa
		}//successivamente esco dal ciclo con break;
		if(sommariga!=sommadiagonale1)quadrato=1;
		for(z=1;z<c;z++)
		{
			if(sommacolonna==sommadiagonale1)//se sommacolonna=sommadiagonale1, assegno alla variabile sommacolonna il valore della somma dei valori della colonna successiva
			{								//La condizione di uguaglianza si ripete per tutte le colonne del quadrato
				sommacolonna=0;
				for(k=0;k<r;k++)
				{
					sommacolonna+=mat[k][z];	
				}
			}
			else {quadrato=1;break;}//se sommacolonna!=sommadiagonale1 assegno a quadrato,1. La condizione di realta del quadrato magico è quindi falsa
		}//successivamente esco dal ciclo con break;
		if(quadrato==0)
		{
			printf("\nquadrato magico\n");
			system("pause");
		}
		else printf("non e' un quadrato magico\n");
		Sleep(S);//mette in pausa il programma per un tot di millisecondi
	}
	while(1>0);//ripete il ciclo all'infinito perchè è una condizione sempre vera
	return 0;
}
