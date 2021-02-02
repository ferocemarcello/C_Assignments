#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define r 2 //numero di righe
#define c 2 //numero di colonne
#define S 1000 //millisecondi di pausa
int main()
{
	int mat[r][c];
	int sommariga1,sommariga2,sommacolonna1,sommacolonna2,sommadiagonale1,sommadiagonale2,k,z,quadrato=0;
	do
	{
		quadrato=1;
		srand((int) time(NULL));
		for(k=0;k<r;k++)//stampa la matrice originale. k è l'indicatore riga
		{
			for(z=0;z<c;z++)//z è l'indicatore colonna
			{
				mat[k][z]=rand()%2;//sono disbonibili solo valori tra 0 e 9 in questo caso
				printf("%d",mat[k][z]);
			}
			puts("");
		}
	
	
		sommariga1=0;
		for(z=0;z<c;z++)
		{
			sommariga1+=mat[0][z];//assegno il valore della somma di tutti i valori contenuti nella prima riga	
		}
		
		sommariga2=0;
		for(z=0;z<c;z++)
		{
			sommariga2+=mat[1][z];//assegno il valore della somma di tutti i valori contenuti nella seconda riga	
		}
		
		
		for(k=2;k<r;k++)
		{
			if(sommariga1==sommariga2)//se tutte le somme di tutte le righe sono diverse esce dal ciclo
			{
				sommariga1=sommariga2;//assegno alla riga precedente la riga successiva
				sommariga2=0;
				for(z=0;z<c;z++)
				{
					sommariga2+=mat[k][z];	
				}
			}
			else
			{
				quadrato=0;
				break;
			}
		}
		sommacolonna1=0;
		for(k=0;k<r;k++)
		{
			sommacolonna1+=mat[k][0];//assegno il valore della somma di tutti i valori contenuti nella prima colonna	
		}
		sommacolonna2=0;
		for(k=0;k<r;k++)
		{
			sommacolonna2+=mat[k][1];//assegno il valore della somma di tutti i valori contenuti nella seconda colonna	
		}
		for(z=2;z<c;z++)
		{
			if(sommacolonna1==sommacolonna2)//se tutte le somme di tutte le colonne sono diverse esce dal ciclo
			{
				sommacolonna1=sommacolonna2;
				sommacolonna2=0;
				for(k=0;k<r;k++)
				{
					sommacolonna2+=mat[k][z];	
				}
			}
			else
			{
				quadrato=0;
				break;
			}
		}
		sommadiagonale1=0;
		k=0;
		for(k=0;k<r;k++)
		{	
			z=k;
			sommadiagonale1+=mat[k][z];//assegno il valore della somma di tutti i valori contenuti nella prima diagonale
			
		}
		sommadiagonale2=0;
		k=0;
		for(k=0;k<r;k++)
		{	
			z=c-k-1;
			sommadiagonale2+=mat[k][z];//assegno il valore della somma di tutti i valori contenuti nella seconda diagonale
			
		}
		if(sommacolonna2==sommariga2 && sommariga2==sommadiagonale1 && sommadiagonale1==sommadiagonale2 && quadrato!=0)
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
