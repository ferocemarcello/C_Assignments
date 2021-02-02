struct studente
{
	int matricola;
	char*nome;
	char*cognome;
	int nascita[3];//giorno mese anno
	char sesso;
	int esami[6];
	int voti[6];
	int numesami;//numero di esami
	struct studente*next;
};
struct anno
{
	int datanno;
	int numero_programmato;//numero degli studenti per il numero programmato, se previsto
	int numstud;
	struct studente*stud;
	struct anno*next;
};
void nuovoanno(struct anno**,struct anno**);
void nuovostudente(struct anno**,struct anno**);
void initlista(struct anno**,struct anno**);
void cancellastud(struct anno**,struct anno**);
void visualizzatutto(struct anno*,struct anno*);
void visualizzastud(struct anno*,struct anno*);
void nonesame(struct anno*,struct anno*);
void maxanno(struct anno*,struct anno*);
int menu();
