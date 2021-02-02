#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>//header file necessario per la funzione Sleep();
#define NCOLS 110 //numero di colonne
#define NROWS 25 // numero di righe
#define S 50 //numero di millisecondi di pausa
int main()
{
	int a,b,i,g,k,k2,vivi,totvive=0;int c=0;
	int prima[NROWS][NCOLS];
	int seconda[NROWS][NCOLS];	
	srand((unsigned int) time(NULL));
	for(a=0;a<NROWS;a++)//inizializzo la matrice prima come composta da tutti 0,tutte celle morte
	{
		for(b=0;b<NCOLS;b++)
		{
			prima[a][b]=0;
		}
	}
	for(a=0;a<NROWS;a++)//inizializzo la matrice seconda come composta da tutti 0,tutte celle morte
	{
		for(b=0;b<NCOLS;b++)
		{
			seconda[a][b]=0;
		}
	}
	for(a=1;a<NROWS-1;a++)//stampa la matrice originale
	{
		for(b=1;b<NCOLS-1;b++)
		{
			prima[a][b]=rand()%3;//sono disbonibili solo 0,1,2
			if(prima[a][b]==0||prima[a][b]==1)
			{
				printf(" ");
			}
			else
			{
				printf("1");
			}
		}
		puts("");
	}
	k=a;k2=b;
	g=0;
	while(1>0)//in questo modo faccio andare all'infinito il programma
	{
		system("cls");//pulisco lo schermo
		for(a=1;a<NROWS-1;a++)//analizzo la matrice prima senza contare i bordi
		{
			for(b=1;b<NCOLS-1;b++)
			{
				c=0;//vivi nelle 9 celle
				vivi=0;//vivi nelle 9 celle meno quella centrale
				for(k=a-1;k<=a+1;k++)//con questi due for analizzo il quadrato attorno ad una cella
				{
					for(k2=b-1;k2<=b+1;k2++)
					{
						if(prima[k][k2]==1)c++;
					}
				}
				
				if(prima[a][b]==1)//calcolo del numero di celle vive intorno
				{
					vivi=c-1;
				}
				else
				{
					vivi=c;
				}
				
				//controlli per stabilire se deve nascere morire o rimanere una cella
				if(prima[a][b]==1 && (vivi==2 || vivi==3))
				{
					seconda[a][b]=1;
				}
				if(prima[a][b]==1 && (vivi<2 || vivi>3))
				{
					seconda[a][b]=0;
				}
				if(prima[a][b]==0 && (vivi==3))
				{
					seconda[a][b]=1;
				}
				if(prima[a][b]==0 && (vivi!=3))
				{
					seconda[a][b]=0;
				}
			}
		}
		
		for(a=0;a<NROWS;a++)//stampo la matrice risultante della generazione successiva
		{
			for(b=0;b<NCOLS;b++)
			{
				prima[a][b]=seconda[a][b];
				if(prima[a][b]==0)
				{
					printf(" ");
				}
				else
				{
					printf("1");
				}
				
			}
			puts("");	
		}
		totvive=0;
		for(a=0;a<NROWS;a++)//conto delle celle vive
		{
			for(b=0;b<NCOLS;b++)
			{
				if(prima[a][b]==1)
				{
					totvive++;
				}
			}
		}
		printf("\n\nnumero di celle vive=%d",totvive);
		g++;
		printf("\ngenerazione %d",g);//vedo a che generazione è il programma
		Sleep(S);
	}	
	return 0;
}
