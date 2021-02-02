#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char testo[1000][100]={0};
	int c=0;//indicatore di colonna
	int r=0;//indicatore di riga
	int lun[1000]={0};//array per la lunghezza delle righe
	char d;
	int car=0;//numero caratteri totale
	int parole=0;//numero parole presenti nel testo
	int alfacar=0;//numero caratteri alfanumerici
	char alfanumerici[36]="abcdefghijklmnopqrstuvwxyz0123456789";
	int s=0;
	printf("inserisci un testo di massimo 1000 righe,ognuna lunga massimo 100 caratteri(inserisci la riga FINE per terminare l'inserimento\n)");
	for(r=0;r<1000;r++)//ciclo ripetuto per ogni riga(finche non si scrive "FINE")
	{
		d=getchar();//assegno ad una variabile d il valore del primo carattere
		while(d!='\n')//ciclo che analizza tutti i caratteri finche non si va a capo
		{
			testo[r][c]=d;//assegno alla cella(la prima ad essere analizzata e la cella[0][0]) il valore di d
			c++;//incremento l'indicatore di colonna di 1
			car++;//non andando a capo, incremento il numero dei caratteri di 1
			if(d==' ')//se però il carattere equivale ad uno spazio diminuisco il numero dei caratteri, e incremento il numero di parole di 1
			{
				parole++;
				car--;
			}
			d=tolower(d);//porto il carattere in formato minuscolo
			for(s=0;s<36;s++)//scorro tutto il vettore dei caratteri alfanumerici
			{
				if(d==alfanumerici[s])
				{
					alfacar++;
				}
			}
			d=getchar();//rilevo il valore di d
		}
		c=0;//azzero l'indicatore colonna
		lun[r]=strlen(testo[r]);//lunghezza della riga
		if(strcmp(testo[r],"FINE")==0)//usa la funzione strcmp() che confronta due stringhe e restiruisce 0 se sono uguali
		{
			printf("numero righe=%d\n",r);
			printf("numero caratteri =%d\n",car-4);
			printf("numero caratteri alfanumerici=%d\n",alfacar-4);
			printf("numero parole=%d\n",parole);
			exit(0);
		}
		parole++;//andando incremento di 1 il numero di parole(conto la parola della riga sopra)
	}
	return 0;
}
