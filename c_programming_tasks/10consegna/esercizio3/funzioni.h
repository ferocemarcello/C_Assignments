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
int din_isempty(struct Cella*);//restituisce 1 se la coda è vuota, 0 se non
void din_enqueue(struct Cella**,struct Cella**,int);//aggiunge un elemento come ultimo nella struttura coda
int din_dequeue(struct Cella**);//toglie il primo elemento e lo restituisce
int din_first(struct Cella*);//restituisce il primo elemento
int stat_isempty(struct slista*);//restituisce 1 se la coda è vuota, 0 se non
void stat_enqueue(struct slista*,int);//aggiunge un elemento come ultimo nella struttura coda
int stat_dequeue(struct slista*);//toglie il primo elemento e lo restituisce
int stat_first(struct slista*);//restituisce il primo elemento
void din_initlista(struct Cella**,struct Cella**);
int menu();
void stat_initlista(struct slista *);
