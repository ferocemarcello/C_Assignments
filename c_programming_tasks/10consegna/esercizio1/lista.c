#include<stdio.h>
#include<stdlib.h>
#include"funzioni.h"//includo l'header file con le funzioni che mi servono per gestire la lista
int main()
{
	struct Cella*T;//dichiaro puntatore al nodo della lista(Cella) linkata(dinamica a strutture collegate),puntatore T alla testa
	struct Cella*C;//dichiaro puntatore al nodo della lista(Cella) linkata(dinamica a strutture collegate),puntatore C alla coda
	struct slista lis;//dichiaro variabile alla struttura slista, che è una lista statica
	int scelta=0;//variabile per la scelta nel menu
	int choice=0;//variabile per la scelta tra lista dinamica(linkata) o statica
	int val=0;//variabile che uso ogni volta che devo leggere o usare un valore
	int pos=0;//variabile per stabilire la posizione di un inserimento
	printf("vuoi lavorare con una lista statica o dinamica?\nrispondere con 1 per statica(dimensione %d) o con 0 per dinamica",N);
	while(scanf("%d",&choice)==0||(choice!=1&&choice!=0))//lettura e controllo sull'imput
	{
		printf("ridigita");
		fflush(stdin);
	}
	if(choice==0)//lista dinamica
	{
		din_initlista(&T,&C);//inizializzo i puntatori testa e coda a null
		printf("in questo momento l'archivio e' vuoto.\n");
		scelta=menu();//stampo il menu e richiedo la scelta dell'utente
		while(scelta!=8)//a seconda del valore restituito dalla funzione menu, eseguo una diversa funzione
		{
			switch(scelta)
			{
				case(1)://inserimento in testa
				{
					printf("digita il valore che vuoi inserire");
					while(scanf("%d",&val)==0)//lettura e controllo sull'imput
					{
						printf("ridigita");
						fflush(stdin);
					}
					fflush(stdin);
					din_inserisci_in_testa(&T,&C,val);break;//funzione per inserire in testa. notare come a questa funzione vengano assegnati
															// gli indirizzi di memoria di testa e coda.E' questa infatti un'operazione necessaria
															// quando c'è la necesità, come in questo caso ed altri a seguire, di modificare la lista
				}
				case(2):
				{
					printf("digita il valore che vuoi inserire");
					while(scanf("%d",&val)==0)//lettura e controllo sull'imput
					{
						printf("ridigita");
						fflush(stdin);
					}
					fflush(stdin);
					din_inserisci_in_coda(&T,&C,val);break;//funzione per inserire in coda
				}
				case(3):
				{
					printf("digita il valore che vuoi inserire");
					while(scanf("%d",&val)==0)//lettura e controllo sull'imput
					{
						printf("ridigita");
						fflush(stdin);
					}
					fflush(stdin);
					printf("digita la posizione dopo la quale vuoi inserire il valore");
					while(scanf("%d",&pos)==0||pos>=din_lunghezza(T))//lettura e controllo sull'imput
					{
						printf("ridigita");
						fflush(stdin);
					}
					fflush(stdin);
					din_inserisci_dopo_elem(&T,&C,pos,val);break;//inserisco val nella lista dopo la posizione pos
				}
				case(4):
				{
					if(din_lunghezza(T)<=0)//controllo se la lista è vuota. se lo è infatti non è possibile usare la funzione di eliminazione in testa
					{
						printf("lista vuota.");
						break;
					}
					din_cancella_in_testa(&T);break;
				}
				case(5):
				{
					if(din_lunghezza(T)<=0)//controllo se la lista è vuota. se lo è infatti non è possibile usare la funzione di eliminazione in coda
					{
						printf("lista vuota.");
						break;
					}
					din_cancella_in_coda(&T,&C,din_lunghezza(T));break;
				}
				case(6):
				{
					printf("digita il valore la cui prima ricorrenza vuoi eliminare");
					while(scanf("%d",&val)==0)//lettura e controllo sull'imput
					{
						printf("ridigita");
						fflush(stdin);
					}
					fflush(stdin);
					if(din_presenza(T,val)==1)//uso una funzione dalla quale posso sapere se un elemento è presente nella lista.
											// se è presente, vado avanti usando la funzione per cancellare la prima occorenza
											// di un elemento, altrimenti, non esegue la funzione
					{
						din_cancella_prima_occorrenza(&T,val);break;
					}
					else
					{
						printf("valore non trovato nella lista\n");break;
					}
				}
				case(7):
				{
					printf("digita il valore le cui ricorrenze vuoi eliminare");
					while(scanf("%d",&val)==0)//lettura e controllo sull'imput
					{
						printf("ridigita");
						fflush(stdin);
					}
					fflush(stdin);
					if(din_presenza(T,val)==1)//uso una funzione dalla quale posso sapere se un elemento è presente nella lista.
											// se è presente, vado avanti usando la funzione per cancellare tutte le occorenze
											// di un elemento, altrimenti, non esegue la funzione
					{
						din_cancella_tutte_occorenze(&T,&C,val);break;
					}
					else
					{
						printf("valore non trovato nella lista\n");break;
					}
				}
			}
			din_stampa(T,C);
			puts("");
			scelta=menu();
		}
	}
	if(choice==1)//lista statica
	{
		stat_initlista(&lis);//inizializzo la lista statica
		printf("in questo momento l'archivio e' vuoto.\n");
		scelta=menu();
		while(scelta!=8)//a seconda del valore restituito dalla funzione menu, eseguo una diversa funzione
		{
			switch(scelta)
			{
				case(1):
				{
					printf("digita il valore che vuoi inserire");
					while(scanf("%d",&val)==0)//lettura e controllo sull'imput
					{
						printf("ridigita");
						fflush(stdin);
					}
					fflush(stdin);
					stat_inserisci_in_testa(&lis,val);break;//inserisco in testa. anche qui fornisco l'indirizzo di memoria della variabile
															// di tipo struct slista lis, di modo da modificare la stessa
				}
				case(2):
				{
					printf("digita il valore che vuoi inserire");
					while(scanf("%d",&val)==0)//lettura e controllo sull'imput
					{
						printf("ridigita");
						fflush(stdin);
					}
					fflush(stdin);
					stat_inserisci_in_coda(&lis,val);break;//inserisco in coda
				}
				case(3):
				{
					printf("digita il valore che vuoi inserire");
					while(scanf("%d",&val)==0)//lettura e controllo sull'imput
					{
						printf("ridigita");
						fflush(stdin);
					}
					fflush(stdin);
					printf("digita la posizione dopo la quale vuoi inserire il valore");
					while(scanf("%d",&pos)==0||pos>=stat_lunghezza(&lis))//lettura e controllo sull'imput
					{
						printf("ridigita");
						fflush(stdin);
					}
					fflush(stdin);
					stat_inserisci_dopo_elem(&lis,pos,val);break;//inserisco l'elemto dopo una certa posizione
				}
				case(4):
				{
					if(stat_lunghezza(&lis)<=0)//se la lista è vuota, non eseguo la funzione per cancellare in testa
					{
						printf("lista vuota");
						break;
					}
					stat_cancella_in_testa(&lis);break;//cancello l'emento in testa
				}
				case(5):
				{
					if(stat_lunghezza(&lis)<=0)//se la lista è vuota, non eseguo la funzione per cancellare in testa
					{
						printf("lista vuota");
						break;
					}
					stat_cancella_in_coda(&lis);break;//cancello l'emento in coda
				}
				case(6):
				{
					printf("digita il valore la cui prima ricorrenza vuoi eliminare");
					while(scanf("%d",&val)==0)//lettura e controllo sull'imput
					{
						printf("ridigita");
						fflush(stdin);
					}
					fflush(stdin);
					if(stat_presenza(&lis,val)==1)//se l'elemteo è presente nella lista, eseguo la funzione per cancellare la sua prima occorrenza nella lista
					{
						stat_cancella_prima_occorrenza(&lis,val);break;
					}
					else
					{
						printf("valore non trovato nella lista\n");break;
					}
				}
				case(7):
				{
					printf("digita il valore le cui ricorrenze vuoi eliminare");
					while(scanf("%d",&val)==0)//lettura e controllo sull'imput
					{
						printf("ridigita");
						fflush(stdin);
					}
					fflush(stdin);
					if(stat_presenza(&lis,val)==1)//se l'elemteo è presente nella lista, eseguo la funzione per cancellare tutte le sue occorrenze nella lista
					{
						stat_cancella_tutte_occorenze(&lis,val);break;
					}
					else
					{
						printf("valore non trovato nella lista\n");break;
					}
				}
			}
			stat_stampa(&lis);
			puts("");
			scelta=menu();//ristampo ogni volta il menu fino a che l'utente non digita 8, per uscire
		}
	}
	return 0;
}
