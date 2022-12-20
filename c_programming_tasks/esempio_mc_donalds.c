/*
all'interno di un mc donalds devono essere gestite le persone in fila per ogni cassa disponibile.
Il numero di casse non è indicato a priori, così come il numero massimo di persone che possono rimanere in fila.
Per ogni persona memorizzare il nome e l'età. Per ogni cassa il codice e l'elenco delle persone in fila.
Condiderando che la fila delle persone DEVE essere gestita con una coda, implementare le seguenti funzioni:
inserimento: che presa una pesona e il codice di una cassa inserisca la persona in fila nella cassa
calcolaMinimo: che trova la prima persona con età minima in fila considerando tutte le casse disponibili
svuotaCasse: che elimina tutte le persone in fila e tutte le relative casse
*/

typedef struct Persona {
	char nome[30];
	int eta;
	struct Persona *next;
} Persona;

typedef struct Coda {
	Persona *primo;
	Persona *ulrimo;
} Coda;

typedef struct Cassa {
	int codice;
	Coda fila;
	struct Cassa *next;
} Cassa;

int main() {
	Cassa *testa = NULL;
	
	/*... altro codice ...*/
	
	return 0;
}

/*
cerca una cassa con un certo codice all'interno della lista,
la funzione restituisce il puntatore alla cassa trovata
NULL altrimenti
*/
Cassa *cercaCassa(Cassa *t, int codice) {
	while (t != NULL) {
		if (t->codice == codice) {
			return t;
		}
		t = t->next;
	}
	return NULL;
}

int inserimento(Cassa **t, int codiceCassa, char nome[30], int eta) {
	Persona *nuovaPersona = creaPersona(nome, eta);
	if (nuovaPersona == NULL) {
		return 0;
	}
	
	Cassa *tmp = cercaCassa(*t, codiceCassa);
	if (tmp == NULL) {
		tmp = creaCassa(codiceCassa);
		if (tmp == NULL) {
			return 0;
		}
		inserisciCassa(t, tmp);
	}
	return push(&(tmp->fila), nuovaPersona);
}

Persona *pop(Coda *c) {
	if (c->primo == NULL) {
		return NULL;
	}
	Persona *tmp = c->primo;
	c->primo = c->primo->next;
	if (c->primo == NULL) {
		c->ultimo = NULL;
	}
	tmp->next = NULL;
	return tmp;
}

int push(Coda *c, Persona *nuovo) {
	if (nuovo == NULL) {
		return 0;
	}
	if (c->ulrimo == NULL) {
		c->primo = nuovo;
	}
	else {
		c->ultimo->next = nuovo;
	}
	c->ultimo = nuovo;
	return 1;
}

int inserisciCassa(Cassa **t, Cassa *nuovo) {
	if (nuovo == NULL) {
		return 0;
	}
	nuovo->next = *t;
	*t = nuovo;
	return 1;
}

Persona *creaPersona(char nome[30], int eta) {
	Persona *nuovo = (Persona*)malloc(sizeof(Persona));
	if (nuovo == NULL) {
		return NULL;
	}
	strcpy(nuovo->nome, nome);
	nuovo->eta = eta;
	nuovo->next = NULL;
	return nuovo;
}

Cassa *creaCassa(int codice) {
	Cassa *nuovo = (Cassa*)malloc(sizeof(Cassa));
	if (nuovo == NULL) {
		return NULL;
	}
	nuovo->fila.primo = NULL;
	nuovo->fila.ulrimo = NULL;
	nuovo->codice = codice;
	nuovo->next = NULL;
	return nuovo;
}

Persona* calcolaMinimoInCoda(Coda *c) {
	Persona *tmp, *minimo = NULL, *primo;

	primo = c->primo;
	if (primo == NULL) {
		return NULL;
	}
	
	do {
		tmp = pop(c);
		if (minimo == NULL || tmp->eta < minimo->eta) {
			minimo = tmp;
		}
		push(c, tmp);
	}
	while (c->primo != primo);
	
	return minimo;
}

Persona* calcolaMinimo(Cassa *t) {
	Persona *minimo = NULL;
	while (t != NULL) {
		Persona *tmp = calcolaMinimoInCoda(t->fila);
		if (tmp != NULL && 
			(minimo == NULL || tmp->eta < minimo->eta)) {
			minimo = tmp;
		}
		t = t->next;
	}
	return minimo;
}


void svuotaCoda(Coda *c) {
	Persona *tmp;
	while (c->primo != NULL) {
		tmp = pop(c);
		free(tmp);	
	}
}

void svuotaCasse(Casse **t) {
	Cassa *elimina;
	while (*t != NULL) {
		elimina = *t;
		*t = (*t)->next;
		svuotaCoda(&(elimina->fila));
		free(elimina);
	}
}
