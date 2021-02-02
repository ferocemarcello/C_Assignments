//
//  Esecizio2.c
//
//  Creato da Alberto Giunta il 19/11/13.
//  Maticola: 0000691428

/*Riscrivere l’esercizio 3 della sesta settimana (per la gestione dell’archivio dei componenti presenti in un magazzino) organizzando il programma in funzioni*/


#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct _Prod {
    int idProd;
    int qtaProd;
}Prod;

typedef struct _Vend{
    int idVend;
    int mmGG;
    int totProd;
    Prod *infoProd;
} Vend;

/*prototipi funzioni*/
void inserimento(int num, Vend vettore[]);
void prodottiVenditore (int num, Vend vettore[]);
void prodottiGiorno (int num, Vend vettore[]);
void prodottiPeriodo(int num, Vend vettVend[]);
void quantitaGiorno (int num, Vend vettVend[]);
void quantitaProdotto (int num, Vend vettVend[]);
int menu();

int main()
{

	int numVend;

    printf("NUMERO VENDITORI ");
    do {
        printf("     »");
    } while (scanf("%d", &numVend) != 1);

    Vend *vettVend;
    vettVend=(Vend*)malloc(sizeof(Vend)*numVend);

    int esci = FALSE;

    inserimento(numVend, vettVend);

	do {
		fflush(stdin);
		int scelta = menu();

		switch (scelta) {

            case 1:
                prodottiVenditore(numVend, vettVend);
                break;
            case 2:
                prodottiGiorno(numVend, vettVend);
                break;
            case 3:
                quantitaGiorno(numVend, vettVend);
                break;
            case 4:
				prodottiPeriodo(numVend, vettVend);
                break;
            case 5:
                quantitaProdotto(numVend, vettVend);
                break;
            case 6:
                inserimento(numVend, vettVend);
                break;
            case 7:
                esci = TRUE;
                break;

		}
	}while (esci == FALSE);

	return 0;
}

int menu () {
	int scelta;

	puts("\n• • • • • M E N U STATICA• • • • •");
	puts("1 » PRODOTTI SINGOLO VENDITORE");
	puts("2 » PRODOTTI SINGOLO GIORNO");
	puts("3 » QUANTITA' SINGOLO GIORNO");
	puts("4 » PRODOTTI DI UN PERIODO");
	puts("5 » PRODOTTI GLOBALI");
    puts("6 » INSERISCI");
	puts("7 » ESCI");

	do {
		fflush(stdin);
		printf("			» ");
	} while (scanf("%d", &scelta) != 1 || scelta < 0 || scelta > 12);

	return scelta;
}

void inserimento(int num, Vend vettVend[]) {
    int i,j;

    for(i = 0;i < num; i++)
	{

        printf("\n\n ID VENDITORE»");
        do {
            fflush(stdin);
            printf("      »");
        } while (scanf("%d", &vettVend[i].idVend) != 1);

        printf("\nMese - Giorno VENDITA (es: 1 GENNAIO -> 101)\t ");
        do {
            fflush(stdin);
            printf("        »");
        }while (scanf("%d", &vettVend[i].mmGG) != 1);


        if(vettVend[i].mmGG<101||vettVend[i].mmGG>1231)
		{
            printf("Data inserita in modo errato\n");
            return;
        }

        printf("QUANTITA' PRODOTTI»");
        do {
            fflush(stdin);
            printf("       »");
        } while ( scanf("%d", &vettVend[i].totProd) != 1);

        vettVend[i].infoProd=(Prod*)malloc(vettVend[i].totProd*sizeof(Prod));

        for(j = 0; j < vettVend[i].totProd; j++)
		{
            printf("\nID PRODOTTO");
            do {
                printf("       »");
            }while (scanf("%d", &vettVend[i].infoProd[j].idProd) != 1);


            printf("QTA VENDUTA");
            do {
                printf("       »");
            } while (scanf("%d", &vettVend[i].infoProd[j].qtaProd) != 1);

        }
    }
}

void prodottiVenditore (int num, Vend vettVend[]) {
    int cod, i, j;
    printf("\n\n ID VENDITORE»");
    do {
        fflush(stdin);
        printf("      »");
    } while (scanf("%d", &cod) != 1);

    for(i = 0; i < num; i++)
    {
        if(cod == vettVend[i].idVend)
        {
            for(j = 0; j < vettVend[i].totProd; j++)
            {
                printf("ID prodotto : %d\n", vettVend[i].infoProd[j].idProd);
                printf("Quantità prodotto : %d\n", vettVend[i].infoProd[j].qtaProd);
            }
        }
    }
}

void prodottiGiorno (int num, Vend vettVend[]) {
    int i, j, data;

    printf("\nMese - Giorno VENDITA (es: 1 GENNAIO -> 101)\t ");
    do {
        fflush(stdin);
        printf("        »");
    }while (scanf("%d", &data) != 1);

    for(i = 0; i < num; i++)
    {
        if(data == vettVend[i].mmGG)
        {
            for(j = 0; j < vettVend[i].totProd; j++)
            {
                printf("Codice prodotto : %d\n", vettVend[i].infoProd[j].idProd);
                printf("Quantita' prodotto : %d\n", vettVend[i].infoProd[j].qtaProd);
            }
        }
    }
}

void quantitaGiorno (int num, Vend vettVend[]) {
    int i, j, idProd, somma;
    printf("\nID PRODOTTO");
    do {
        printf("       »");
    }while (scanf("%d",&idProd) != 1);

    somma = 0;
    for(i = 0; i < num; i++)
    {
        for(j = 0; j < vettVend[i].totProd; j++)
        {
            if(idProd == vettVend[i].infoProd[j].idProd)
            {
                somma += vettVend[i].infoProd[j].qtaProd;
            }
        }
    }
    printf("\nDel prodotto di ID %d sono state vendute %d unità\n", idProd, somma);

}

void prodottiPeriodo(int num, Vend vettVend[]) {

    int i, j, inizio, fine;

    printf("\nPRIMO GIORNO DEL PERIODO: Mese - Giorno VENDITA (es: 1 GENNAIO -> 101)");
    do {
        fflush(stdin);
        printf("        »");
    }while (scanf("%d", &inizio) != 1);

    if(inizio < 101|| inizio > 1231){
        printf("Valore errato\n");
        return;
    }

    printf("\nULTIMO GIORNO DEL PERIODOMese - Giorno VENDITA (es: 1 GENNAIO -> 101)");
    do {
        fflush(stdin);
        printf("        »");
    }while (scanf("%d", &fine) != 1);

    if(fine < 101|| fine > 1231){
        printf("Valore errato\n");
        return;
    }

    for(i = 0; i < num; i++)
    {
        if(vettVend[i].mmGG >= inizio && vettVend[i].mmGG <= fine)
        {
            for(j = 0; j < vettVend[i].totProd; j++)
            {
                printf("ID prodotto: %d\n", vettVend[i].infoProd[j].idProd);
                printf("Quantità prodotto: %d\n", vettVend[i].infoProd[j].qtaProd);
            }
        }
    }

}

void quantitaProdotto (int num, Vend vettVend[]) {
    int i, j;

    for(i = 0; i < num; i++)
    {
        for(j = 0; j < vettVend[i].totProd;j ++)
        {
            printf("\nID prodotto : %d\n", vettVend[i].infoProd[j].idProd);
            printf("Quantità prodotto : %d\n", vettVend[i].infoProd[j].qtaProd);
        }
    }
}

