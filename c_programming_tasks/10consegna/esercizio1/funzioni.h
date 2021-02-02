#define N 10
struct Cella //lista dinamica
{
	int valore;
	struct Cella*next;
};
struct slista //lista statica
{
	int last;
	int valori[N];
};
void din_inserisci_in_testa(struct Cella**,struct Cella**,int);
void din_inserisci_in_coda(struct Cella**,struct Cella**,int);
void din_inserisci_dopo_elem(struct Cella**,struct Cella**,int,int);
void din_cancella_in_testa(struct Cella**);
void din_cancella_in_coda(struct Cella**,struct Cella**,int);
void din_cancella_prima_occorrenza(struct Cella**,int);
void din_cancella_tutte_occorenze(struct Cella**,struct Cella**,int);
void din_stampa(struct Cella*,struct Cella*);
int din_lunghezza(struct Cella*);
void din_initlista(struct Cella**,struct Cella**);
int din_presenza(struct Cella*,int);
int menu();
void stat_initlista(struct slista*);
void stat_inserisci_in_coda(struct slista *,int);
void stat_inserisci_in_testa(struct slista *,int);
void stat_inserisci_dopo_elem(struct slista *,int,int);
void stat_cancella_in_testa(struct slista *);
void stat_cancella_in_coda(struct slista *);
void stat_cancella_prima_occorrenza(struct slista *,int);
void stat_cancella_tutte_occorenze(struct slista *,int);
void stat_stampa(struct slista *);
int stat_lunghezza(struct slista*);
int stat_presenza(struct slista*,int);
