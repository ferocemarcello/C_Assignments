/*MARCELLO FEROCE PRIMO ANNO INGEGEGNERIA E SCIENZE INFORMATICHE
*/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main()
{ 
char carattere='a';/*DICHIARAZIONE DELLA VARIABILE*/
signed char carattere_segnato='b';/*DICHIARAZIONE DELLA VARIABILE*/
unsigned char carattere_non_segnato='c';/*DICHIARAZIONE DELLA VARIABILE*/
short int corto_intero=2;/*DICHIARAZIONE DELLA VARIABILE*/
int intero=-500;/*DICHIARAZIONE DELLA VARIABILE*/
long int lungo_intero=32000;/*DICHIARAZIONE DELLA VARIABILE*/
unsigned short int corto_intero_non_segnato=21;/*DICHIARAZIONE DELLA VARIABILE*/
unsigned int intero_non_segnato=400;/*DICHIARAZIONE DELLA VARIABILE*/
unsigned long int lungo_intero_non_segnato=300000;/*DICHIARAZIONE DELLA VARIABILE*/
float reale=56.45;/*DICHIARAZIONE DELLA VARIABILE*/
double reale_doppio=65.54;/*DICHIARAZIONE DELLA VARIABILE*/
long double lungo_reale_doppio=7.4737;/*DICHIARAZIONE DELLA VARIABILE*/
char *dimensione;
printf("la variabile char carattere e' %c. Ha dimensione %lu byte\n",carattere,sizeof(carattere));/*STAMPO LA VARIABILE E LA SUA DIMENSIONE*/
dimensione="la variabile char carattere e' 1. Ha dimensione 1 byte";//assegno la riga in alto come valore stringa all'array di caratteri dimensione
int num=strlen(dimensione);//funzione che conta i caratteri
printf("numero caratteri=%d",num);puts("");

printf("la variabile signed char carattere_segnato e' %c. Ha dimensione %lu byte\n",carattere_segnato,sizeof(carattere_segnato));/*STAMPO LA VARIABILE E LA SUA DIMENSIONE*/
dimensione="la variabile signed char carattere_segnato e' 1. Ha dimensione 1 byte";
num=strlen(dimensione);
printf("numero caratteri=%d",num);puts("");

printf("la variabile unsigned char carattere_non_segnato e' %c. Ha dimensione %lu byte\n",carattere_non_segnato,sizeof(carattere_non_segnato));/*STAMPO LA VARIABILE E LA SUA DIMENSIONE*/
dimensione="la variabile unsigned char carattere_non_segnato e' 1. Ha dimensione 1 byte";
num=strlen(dimensione);
printf("numero caratteri=%d",num);puts("");

printf("la variabile short int corto_intero e' %d. Ha dimensione %lu byte\n",corto_intero,sizeof(corto_intero));/*STAMPO LA VARIABILE E LA SUA DIMENSIONE*/
dimensione="la variabile short int corto_intero e' 1. Ha dimensione 1 byte";
num=strlen(dimensione);
printf("numero caratteri=%d",num);puts("");

printf("la variabile int intero %d. Ha dimensione e' %lu byte\n",intero,sizeof(intero));/*STAMPO LA VARIABILE E LA SUA DIMENSIONE*/
dimensione="la variabile int intero e' 1. Ha dimensione 1 byte";
num=strlen(dimensione);
printf("numero caratteri=%d",num);puts("");

printf("la variabile long int lungo_intero e' %d. Ha dimensione %lu byte\n",lungo_intero,sizeof(lungo_intero));/*STAMPO LA VARIABILE E LA SUA DIMENSIONE*/
dimensione="la variabile long int lungo_intero e' 11111. Ha dimensione 1 byte";
num=strlen(dimensione);
printf("numero caratteri=%d",num);puts("");

printf("la variabile unsigned short int corto_intero_non_segnato e' %d. Ha dimensione %lu byte\n",corto_intero_non_segnato,sizeof(corto_intero_non_segnato));/*STAMPO LA VARIABILE E LA SUA DIMENSIONE*/
dimensione="la variabile unsigned short int corto_intero_non_segnato e' 11. Ha dimensione 1 byte";
num=strlen(dimensione);
printf("numero caratteri=%d",num);puts("");

printf("la variabile unsigned int intero_non_segnato e' %d. Ha dimensione %lu byte\n",intero_non_segnato,sizeof(intero_non_segnato));/*STAMPO LA VARIABILE E LA SUA DIMENSIONE*/
dimensione="la variabile unsigned int intero_non_segnato e' 1. Ha dimensione 111 byte";
num=strlen(dimensione);
printf("numero caratteri=%d",num);puts("");

printf("la variabile unsigned long int lungo_intero_non_segnato e' %d. Ha dimensione %lu byte\n",lungo_intero_non_segnato,sizeof(lungo_intero_non_segnato));/*STAMPO LA VARIABILE E LA SUA DIMENSIONE*/
dimensione="la variabile unsigned long int lungo_intero_non_segnato e' 111111. Ha dimensione 1 byte";
num=strlen(dimensione);
printf("numero caratteri=%d",num);puts("");

printf("la variabile float reale e' %.2f. Ha dimensione %lu byte\n",reale,sizeof(reale));/*STAMPO LA VARIABILE E LA SUA DIMENSIONE*/
dimensione="la variabile float reale e' 1. Ha dimensione 11111111 byte";
num=strlen(dimensione);
printf("numero caratteri=%d",num);puts("");

printf("la variabile double reale_doppio e' %.3f. Ha dimensione %lu byte\n",reale_doppio,sizeof(reale_doppio));/*STAMPO LA VARIABILE E LA SUA DIMENSIONE*/
dimensione="la variabile double reale_doppio e' 1. Ha dimensione 11111111 byte";
num=strlen(dimensione);
printf("numero caratteri=%d",num);puts("");

printf("la variabile long double lungo_reale_doppio e' %g. Ha dimensione %lu byte\n",lungo_reale_doppio,sizeof(lungo_reale_doppio));/*STAMPO LA VARIABILE E LA SUA DIMENSIONE*/
dimensione="la variabile long double lungo_reale_doppio e' 1111111111111. Ha dimensione 11111 byte";
num=strlen(dimensione);
printf("numero caratteri=%d",num);puts("");


return 0;
}
