typedef struct {
	int idCompagniaTrasporti;
	int idPaesePartenza;
	int numeroPacchi;
	time_t dataOraArrivo;
	int trasportoEccezionale;	//1 normale, 0 eccezionale
	Camion *next;
} Camion;

typedef struct {
	int idDogana;
	Camion *elenco;
	Dogana *next;
} Dogana;

int main() {
	Dogana *t = NULL;
	
	/* altro codice */
	
	return 0;
}


/**************/
/* FUNZIONE 1 */
/**************/
/*
la funzione restituisce:
-1 in caso di errore allocazione nuovo Camion
-2 in caso di errore allocazione nuovo Dogana
1 in caso di operazione conclusa correttamente
*/
int arrivoCamion(Dogana **t, int idDoganaArrivo, int idCompagniaTrasporti, int idPaesePartenza, int numeroPacchi, time_t dataOraArrivo, int trasportoEccezionale) {
	Camion *nuovoCamion;
	Dogana *tmpDogana;
	nuovoCamion = creaCamion(idCompagniaTrasporti, idPaesePartenza, numeroPacchi, dataOraArrivo, trasportoEccezionale);
	if (nuovoCamion == NULL) {
		return -1;
	}
	
	tmpDogana = trovaCreaDogana(t, idDoganaArrivo);
	if (tmpDogana == NULL) {
		return -2;
	}
	
	inerisciCamionInLista(&tmpDogana->elenco, nuovoCamion);
	
	return 1;
}

void inerisciCamionInLista(Camion **t, Camion *nuovoCamion) {
	Camion *tmpCamion, *precCamion;
	
	precCamion = NULL;
	tmpCamion = *t;
	while (tmpCamion != NULL) {
		if (nuovoCamion->trasportoEccezionale < tmpCamion->trasportoEccezionale || 
			(nuovoCamion->trasportoEccezionale == tmpCamion->trasportoEccezionale &&
				nuovoCamion->dataOraArrivo < tmpCamion->dataOraArrivo)) {
			nuovoCamion->next = tmpCamion;
			if (precCamion == NULL) {
				*t = nuovoCamion;
			}
			else {
				precCamion->next = nuovoCamion;
			}
			return;
		}
		else {
			precCamion = tmpCamion;
			tmpCamion = tmpCamion->next;
		}
	}
	
	if (*t == NULL) {
		*t = nuovoCamion;
	}
	else {
		precCamion->next = nuovoCamion;
	}
}


Camion* creaCamion(int idCompagniaTrasporti, int idPaesePartenza, int numeroPacchi, time_t dataOraArrivo, int trasportoEccezionale) {
	Camion *nuovo;
	nuovo = (Camion*)malloc(sizeof(Camion));
	if (nuovo == NULL) {
		return NULL;
	}
	nuovo->next = NULL;
	nuovo->idCompagniaTrasporti = idCompagniaTrasporti;
	nuovo->idPaesePartenza = idPaesePartenza;
	nuovo->numeroPacchi = numeroPacchi;
	nuovo->dataOraArrivo = dataOraArrivo;
	nuovo->trasportoEccezionale = trasportoEccezionale;
	return nuovo;
}

Dogana* trovaCreaDogana(Dogana **t, int idDogana) {
	Dogana* tmp;
	
	tmp = cercaDogana(*t, idDogana);
	if (tmp == NULL) {
		return creaDogana(idDogana);
	}
	return tmp;
}

Dogana* cercaDogana(Dogana *t, int idDogana) {
	Dogana* tmp;
	
	tmp = t;
	while (tmp != NULL) {
		if (tmp->idDogana == idDogana) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

Dogana* creaDogana(int idDogana) {
	Dogana *nuovo;
	nuovo = (Dogana*)malloc(sizeof(Dogana));
	if (nuovo == NULL) {
		return NULL;
	}
	nuovo->next = NULL;
	nuovo->elenco = NULL;
	nuovo->idDogana = idDogana;
	return nuovo;
}


/**************/
/* FUNZIONE 2 */
/**************/
/*
la funzione restituisce:
-1 se la Dogana non è stata trovato
il numero di pacchi diversamente
*/
int numeroPacchiDogana(Dogana *t, int idDogana) {
	Dogana* tmp;
	Camion* tmpCamion;
	int conta = 0;
	
	tmp = cercaDogana(t, idDogana);
	if (tmp == NULL) {
		return -1;
	}
	
	tmpCamion = tmp->elenco;
	while (tmpCamion != NULL) {
		conta += tmpCamion->numeroPacchi;
		tmpCamion = tmpCamion->next;
	}
	return conta;
}



/**************/
/* FUNZIONE 3 */
/**************/
/*
la funzione restituisce:
il numero di pacchi da un certo paese di partenza
*/
int numeroPacchiDoganaPartenza(Dogana *t, int idPaesePartenza) {
	Dogana* tmpDogana;
	Camion* tmpCamion;
	int conta = 0;
	
	tmpDogana = t;
	while (tmpDogana != NULL) {
		tmpCamion = tmpDogana->elenco;
		while (tmpCamion != NULL) {
			if (tmpCamion->idPaesePartenza == idPaesePartenza) {
				conta += tmpCamion->numeroPacchi;
			}
			tmpCamion = tmpCamion->next;
		}		
		tmpDogana = tmpDogana->next;
	}

	return conta;
}