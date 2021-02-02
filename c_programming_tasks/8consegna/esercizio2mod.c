#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef struct _Prod //struttura per il prodotto
{
    int idProd;//codice
    int qtaProd;//auantità
}Prod;
typedef struct _Vend //struttura per il venditore
{
    int idVend;//codice
    int mmGG;//data
    int totProd;//totale prodotti
    Prod *infoProd;//puntatore per i prodotti
} Vend;
int menu ()//stampa a video il menu di scelta e restituisce il valore corrispondente alla scelta
{
	int scelta;
	puts("scegli");
	puts("1 » PRODOTTI SINGOLO VENDITORE");
	puts("2 » PRODOTTI SINGOLO GIORNO");
	puts("3 » QUANTITA' SINGOLO GIORNO");
	puts("4 » PRODOTTI DI UN PERIODO");
	puts("5 » PRODOTTI GLOBALI");
    puts("6 » INSERISCI(altri id venditore)");
	puts("7 » ESCI");
	do {
		fflush(stdin);
		printf("			» ");
	} while (scanf("%d", &scelta) != 1 || scelta < 0 || scelta > 12);

	return scelta;
}
void inserimento(int num, Vend vettVend[])//funzione void che fa inserire all'utente tutte le informazioni necessarie relative ai prodotti e ai venditori
{
    int i,j;

    for(i = 0;i <num; i++)
	{

        printf("\n\n ID VENDITORE»");
        scanf("%d", &vettVend[i].idVend);
        fflush(stdin);

        printf("\nMese - Giorno VENDITA. numero mese numero giorno(es: 1 GENNAIO = 101)\t ");
        printf("        -->");
        scanf("%d", &vettVend[i].mmGG);
        fflush(stdin);
        
        while(vettVend[i].mmGG<101||vettVend[i].mmGG>1231)
		{
            printf("Data inserita in modo errato.reinserisci data\n");
            scanf("%d", &vettVend[i].mmGG);
        	fflush(stdin);
        }

        printf("QUANTITA' PRODOTTI»");
        printf("       »");
		scanf("%d", &vettVend[i].totProd);
		fflush(stdin);
        vettVend[i].infoProd=(Prod*)malloc(vettVend[i].totProd*sizeof(Prod));

        for(j = 0; j < vettVend[i].totProd; j++)
		{
            printf("\nID PRODOTTO");
            printf("       »");
        	scanf("%d", &vettVend[i].infoProd[j].idProd);


            printf("QTA VENDUTA");
            printf("       »");
            scanf("%d", &vettVend[i].infoProd[j].qtaProd);

        }
    }
}
void prodottiVenditore (int num, Vend vettVend[])//stampa le informazioni relative ad ogni singolo prodotto di un venditore
{
    int cod, i, j;
    printf("\n\n ID VENDITORE»");
    	printf("      »");
        fflush(stdin);
    	scanf("%d", &cod);

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
void prodottiGiorno (int num, Vend vettVend[])//stampa le informazioni relative ad ogni singolo prodotto di un giorno
{
    int i, j, data;
    printf("\nMese - Giorno VENDITA. numero mese numero giorno(es: 1 GENNAIO = 101)\t ");
    printf("        »");
    scanf("%d", &data);
    fflush(stdin);
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

void quantitaGiorno (int num, Vend vettVend[])//stampa a video la quantità venduta di un prodotto
{
    int i, j, idProd, somma;
    printf("\nID PRODOTTO");
    printf("       »");
    scanf("%d",&idProd);
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
void prodottiPeriodo(int num, Vend vettVend[])//stampa a video il numero di prodotti venduti in un singolo periodo
{

    int i, j, inizio, fine;
    printf("\nPRIMO GIORNO DEL PERIODO: Mese - Giorno VENDITA (es: 1 GENNAIO = 101)");
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

void quantitaProdotto (int num, Vend vettVend[])//stampa la quantità di ogni singolo prodotto
{
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
int main()
{
	int numVend;
	int scelta;
    printf("NUMERO VENDITORI?");
    scanf("%d", &numVend);//numero di venditori
    Vend *vettVend;//puntatore di venditori
    vettVend=(Vend*)malloc(sizeof(Vend)*numVend);//alloco un array di tipo Vend di dimensione numVend
    int esci = FALSE;
    inserimento(numVend, vettVend);//funzione che richiede un puntatore con la sua dimensione
	do 
	{
		fflush(stdin);
		scelta = menu();//

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
                esci = TRUE;//se l'utente richiede di uscire la condizione del ciclo while non è più verificabile e si esce dal ciclo
                break;
		}
	}while (esci == FALSE);
	return 0;
}
