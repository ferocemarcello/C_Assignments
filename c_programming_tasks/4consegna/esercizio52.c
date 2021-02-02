//marcello feroce primo anno ingegneria e scienze informatiche
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n=0,div,k; 
    int primo=1; /*primo e k sono due contatori*/
	float numero=0; 

    printf("Inserisci un numero intero positivo diverso da zero: ");
    scanf("%f", &numero);

    while(numero<0 || numero!=(int)numero)
		{
			printf("il numero digitato deve essere intero e non negativo\n");//controllo affinchè il valore di numero sia corretto
			printf("digita un altro numero");scanf("%f",&numero);
		}

    printf("i %d primi numeri primi a partire da 2 sono:\n",(int)numero);

    /*inizio un ciclo che incrementi i numeri primi fino al numero inserito*/
    while(n<numero)
	{ 
        primo++;
        div= 0;  /*se non azzerassi il divisore il ciclo si fermerebbe dopo la prima volta*/

        /*il for analizza tutti i numeri finchè la condizione del ciclo while non è verificata.
        incremento i divisori dei numeri e, se ne hanno solo due (1 e sè stessi, condizione per essere primi) li stampo
        */
        for(k=1;k<=primo;k++)
		{
            if(primo%k==0)
			{ /*se il resto tra num e k è zero, div è un divisore di numero.*/
            	div=div+1;
            }
        }
        if (div==2)
        {
            printf("%d\n",primo);
            n++;
        } 
   	}

    return 0;
}
