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
int din_isempty(struct Cella*);//restituisce 1 se la pila è vuota, 0 se non
void din_push(struct Cella**,struct Cella**,int);//inserisce elemento alla testa
int din_pop(struct Cella**);//cancella l'elemneto testa dalla pila e lo restituisce
int din_top(struct Cella*);//restituisce testa pila
int stat_isempty(struct slista*);//restituisce 1 se la pila è vuota, 0 se non
void stat_push(struct slista*,int);//inserisce elemento alla testa
int stat_pop(struct slista*);//cancella l'elemneto testa dalla pila e lo restituisce
int stat_top(struct slista*);//restituisce testa pila
void din_initlista(struct Cella**,struct Cella**);
int menu();
void stat_initlista(struct slista *);
