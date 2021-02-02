/* Esercizio 4, settimana 6
   Questo programma indica quale data tra le due inserite dall'utente viene prima nel calendario.
   Le date vengono memorizzate in una struttura.
   Autore: Nicola Cielo Lugaresi Secci (mat. 0000718887)
   Data: 30/10/2014
*/
#include <stdio.h>
#include <string.h>

void main()
{
     struct {
            int giorno,mese,anno;} giornoa,giornob;
     // giornoa e giornob sono strutture di dati, ognuna ha tre campi di tipo intero che conservano giorno, mese ed anno
     int ordine; // la variabile ordine assume valore negativo se giornoa precede giornob, positivo se giornob precede giornoa
     printf("Questo programma consente di inserire due date e indica quale delle due viene prima nel calendario.\n");
     do {
         printf("Inserisci la prima data nel formato gg/mm/aaaa: ");
         scanf("%d/%d/%d",&giornoa.giorno,&giornoa.mese,&giornoa.anno);
         fflush(stdin);}
     while (giornoa.giorno>31||giornoa.giorno<1||giornoa.mese>12||giornoa.mese<1||giornoa.anno<1);
     do {
         printf("Inserisci la seconda data nel formato gg/mm/aaaa: ");
         scanf("%d/%d/%d",&giornob.giorno,&giornob.mese,&giornob.anno);
         fflush(stdin);}
     while (giornob.giorno>31||giornob.giorno<1||giornob.mese>12||giornob.mese<1||giornob.anno<1);
     // ripete l'inserimento delle date quando viene inserito un valore privo di senso
     if ((ordine=giornoa.anno-giornob.anno)==0) // confronta gli anni
         if ((ordine=giornoa.mese-giornob.mese)==0) // se gli anni sono uguali confronta i mesi
              ordine=giornoa.giorno-giornob.giorno; // se i mesi sono uguali confronta i giorni
     if (ordine==0) // se la differenza è zero -> giorno mese e anno sono uguali
         printf("Hai inserito due giorni uguali.");
     else
         printf("Il %s giorno inserito viene prima dell'altro.",ordine<0?"primo":"secondo"); // indico quale giorno viene prima a seconda del valore contenuto in ordine
     getchar();
}
