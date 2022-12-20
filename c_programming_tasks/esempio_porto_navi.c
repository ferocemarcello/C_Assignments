/*
Il porto di Ravenna ha la necessità di gestire l'attracco delle navi presso le diverse banchine disponibili.
Ogni banchina ha la possibilità di far attraccare un numero indefinito di navi. 
Ogni nave è caratterizzata da un nome e da un intero che ne definisce la dimensione a partire dal valore 1.
Più il numero è grande e più la nave risulta grande. Ogni banchina ha la possibilità di far attraccare navi
fino ad una certa dimensione. Quindi se una banchina ha come dimensione massima consentita 4, potranno attraccare
in questa banchina SOLO le navi con dimensione <= a 4.
Definire le strutture dati necessarie per gestire i dati del problema e implementare la funzione di inserimento
che permette di far attraccare una nave secondo la seguente logica:
- la nave deve essere attraccata nella banchina (con capacità >= alla dimensione della nave) con numero minore di 
navi attraccate in quel momento
- nel caso esistano più banchine con lo stesso numero minimo di navi, si deve considerare la banchina che ha
capacità inferiore (ma comunque con capacità >= alla dimensione della nave)
*/

#define MAX 10

typedef struct Nave {
	char nome[30];
	int dimensione;
	struct Nave *next;
} Nave;

typedef struct Banchina {
	int capacita;
	Nave *listaNavi;
} Banchina;

int main() {
	int i;
	Banchina porto[MAX];
	
	for (i = 0; i < MAX; i++) {
		porto[MAX].listaNavi = NULL;
		/*... altro codice per inizializzare la capacità per ogni banchina...*/
	}
	
	/*... altro codice ...*/
	
	return 0;
}

/*
la funzione restituisce:
l'indice della banchina all'interno dell'array porto se l'inserimento va a buon fine
-1 se non è stata trovata una banchina con capacità suff
-2 se non è stato possibile allocare la memoria
*/
int inserisci(Banchina porto[MAX], int dimNave, char nomeNave[30]) {
	int pos_min = trovaBanchina(porto, dimNave);
	if (pos_min < 0) {
		return -1;
	}
	Nave *nuovo = creaNave(dimNave, nomeNave);
	if (nuovo == NULL) {
		return -2;
	}
	return pos_min;
}

/*
alloca la struttura nave e inizializza le relative proprietà
restituisce il puntatore alla nuova cella allocata
NULL in caso di errore di allocazione
*/
Nave *creaNave(int dimNave, char nomeNave[30]) {
	Nave *nuovo = (Nave*)malloc(sizeof(Nave));
	if (nuovo == NULL) {
		return NULL;
	}
	strcpy(nuovo->nome, nomeNave);
	nuovo->dimensione = dimNave;
	nuovo->next = NULL;
	return nuovo;
}

/*
trova la banchina dove inserire la nave secondo le regole indicate
la funzione restituisce l'indice della banchina all'interno dell'array se trovata
-1 altrimenti
*/
int trovaBanchina(Banchina porto[MAX], int dimNave) {
	int i, minimo, pos_min, conta;

	minimo = -1;
	pos_min = -1;
	for (i = 0; i < MAX; i++) {
		if (porto[i].capacita >= dimNave) {
			conta = contaNavi(porto[i].listaNavi);
			if (pos_min == -1 ||
				conta < minimo ||
				(conta == minimo && porto[i].capacita < porto[pos_min].capacita)) {
				minimo = conta;
				pos_min = i;
			}
		}
	}
	return pos_min;
}

/*
restituisce il numero di navi presenti in una lista
*/
int contaNavi(Nave *t) {
	int conta = 0;
	while (t != NULL) {
		conta++;
		t = t->next;
	}
	return conta;
}