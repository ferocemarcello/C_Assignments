
#include<stdio.h>
#include<stdlib.h>
struct smazzo
{
	int valori[52][2];
	int lung;
};
struct sgiocatore
{
	int valori[5][2];
	float europeruno;
	float puntata;
	int punteggio;
	int volte[13];
};
int giocatori()
{
	int n=0;
	printf("quanti giocatori?\t");
	while(scanf("%d",&n)==0 || (n<2 || n>5))
	{
		printf("\ndigita un intero maggiore di 1 e minore di 6\t");
		fflush(stdin);
	}
	fflush(stdin);
	return n;
}

void initmazzo(struct smazzo*maz)
{
	int k=0;
	int y=1;
	int z=0;
	for(k=0;k<52;k++)
	{
		z++;
		(*maz).valori[k][0]=z;
		(*maz).valori[k][1]=y;
		if(k==12||k==25||k==38)
		{
			z=0;
			y++;
		}
	}
	(*maz).lung=52;
}
void stampaplayer(struct sgiocatore*players,int pos)
{
	int k=0;
	printf("\n\t\t\t\tgiocatore %d\n\n",pos+1);
	puts("");
	for(k=0;k<5;k++)
	{
		printf("carta %d=",k+1);
		switch(players[pos].valori[k][0])
		{
			case(1):
			{
				printf("Asso di");
				break;
			}
			case(2):
			case(3):
			case(4):
			case(5):
			case(6):
			case(7):
			case(8):
			case(9):
			case(10):
			{
				printf("%d di",players[pos].valori[k][0]);
				break;
			}
			case(11):
			{
				printf("Jack di");
				break;
			}
			case(12):
			{
				printf("Queen di");
				break;
			}
			case(13):
			{
				printf("King di");
				break;
			}
		}
		switch(players[pos].valori[k][1])
		{
			case(1):
			{
				printf(" Cuori");
				break;
			}
			case(2):
			{
				printf(" Quadri");
				break;
			}
			case(3):
			{
				printf(" Fiori");
				break;
			}
			case(4):
			{
				printf(" Picche");
				break;
			}
		}
		puts("");
	}
}
void cambia_carte(struct smazzo*maz,struct sgiocatore**players,int posgioc)
{
	int n=0;
	int k=0;
	int z=0;
	int scelta=0;
	int tmp=0;
	int tmp2=0;
	printf("quante carte?\t");
	while(scanf("%d",&n)==0||n<1||n>4)
	{
		printf("\nnumero di carte non valido.ridigita\t");
		fflush(stdin);
	}
	fflush(stdin);
	printf("quali carte?\n\n");
	printf("1\tcarta 1\n");
	printf("2\tcarta 2\n");
	printf("3\tcarta 3\n");
	printf("4\tcarta 4\n");
	printf("5\tcarta 5\n");
	puts("");
	for(k=0;k<n;k++)
	{
		printf("digita la carta\t");
		while(scanf("%d",&scelta)==0||scelta<1||scelta>5)//lettura e controllo sull'imput
		{
			printf("\ndigita un intero compreso tra 1 e 5\t");
			fflush(stdin);
		}
		puts("");
		tmp=(*players)[posgioc].valori[scelta-1][0];
		tmp2=(*players)[posgioc].valori[scelta-1][1];
		(*players)[posgioc].valori[scelta-1][0]=(*maz).valori[k][0];
		(*players)[posgioc].valori[scelta-1][1]=(*maz).valori[k][1];
		for(z=0;z<(*maz).lung-2;z++)
		{
			(*maz).valori[z][0]=(*maz).valori[z+1][0];
			(*maz).valori[z][1]=(*maz).valori[z+1][1];
		}
		(*maz).valori[((*maz).lung)-1][0]=tmp;
		(*maz).valori[((*maz).lung)-1][1]=tmp2;
	}
}
void stampa(struct smazzo maz)
{
	int k=0;
	for(k=0;k<maz.lung;k++)
	{
		printf("carta %d=",k+1);
		switch(maz.valori[k][0])
		{
			case(1):
			{
				printf("Asso di");
				break;
			}
			case(2):
			case(3):
			case(4):
			case(5):
			case(6):
			case(7):
			case(8):
			case(9):
			case(10):
			{
				printf("%d di",maz.valori[k][0]);
				break;
			}
			case(11):
			{
				printf("Jack di");
				break;
			}
			case(12):
			{
				printf("Queen di");
				break;
			}
			case(13):
			{
				printf("King di");
				break;
			}
		}
		switch(maz.valori[k][1])
		{
			case(1):
			{
				printf(" Cuori");
				break;
			}
			case(2):
			{
				printf(" Quadri");
				break;
			}
			case(3):
			{
				printf(" Fiori");
				break;
			}
			case(4):
			{
				printf(" Picche");
				break;
			}
		}
		puts("");
	}
}
void mescolatore(struct smazzo*maz)
{
	int k=0;
	int y=0;
	int z=0;
	int tmp=0;
	int tmp2=0;
	srand((unsigned int) time(NULL));
	for(k=0;k<52;k++)
	{
		y=rand()%52;
		z=rand()%52;
		tmp=(*maz).valori[k][0];
		tmp2=(*maz).valori[k][1];
		
		(*maz).valori[k][0]=(*maz).valori[y][0];
		(*maz).valori[k][1]=(*maz).valori[y][1];
		
		(*maz).valori[y][0]=tmp;
		(*maz).valori[y][1]=tmp2;
	}
}
void distributore(struct smazzo*maz,struct sgiocatore**players,int num)
{
	int k=0;
	int z=0;
	int c=0;
	int car=0;
	for(z=0;z<num;z++)
	{
		for(k=0;k<5;k++)
		{
			(*players)[z].valori[k][0]=(*maz).valori[c][0];
			(*players)[z].valori[k][1]=(*maz).valori[c][1];
			c++;
		}
	}
	car=num*5;
	for(k=car;k<(*maz).lung;k++)
	{
		(*maz).valori[k-car][0]=(*maz).valori[k][0];
		(*maz).valori[k-car][1]=(*maz).valori[k][1];
	}
	(*maz).lung=(*maz).lung-car;
}
void abbandono(struct smazzo*maz,struct sgiocatore**players,int posgioc)
{
	int k=0;
	for(k=0;k<5;k++)
	{
		(*maz).valori[k+(*maz).lung][0]=(*players)[posgioc].valori[k][0];
		(*maz).valori[k+(*maz).lung][1]=(*players)[posgioc].valori[k][1];
	}
	(*maz).lung+=5;
	(*players)[posgioc].valori[0][0]=-1;
	(*players)[posgioc].valori[0][1]=-1;
}
float puntata(struct sgiocatore**players,int posgioc)
{
	float puntata=0;
	printf("giocatore %d, quanto punti?\t",posgioc+1);
	while(scanf("%f",&puntata)==0||(puntata<1||puntata>(*players)[posgioc].europeruno))
	{
		printf("\ndigita un valore in euro positivo grande massimo quanto il patrimonio personale\t");
		fflush(stdin);
	}
	fflush(stdin);
	return puntata;
}
float puntmax(struct sgiocatore*players,int num)
{
	float puntmax=0;
	int k=0;
	for(k=0;k<num;k++)//trovo la puntata massima
	{
		if(players[k].valori[0][0]!=-1)
		{
			if(players[k].puntata>puntmax)
			{
				puntmax=players[k].puntata;
			}
		}
	}
	return puntmax;
}
int giocmax(struct sgiocatore*players,int num,float puntmax)
{
	int k=0;
	for(k=0;k<num;k++)//trovo la puntata massima
	{
		if(players[k].valori[0][0]!=-1)
		{
			if(players[k].puntata==puntmax)
			{
				return k;
			}
		}
	}
}
void vit_per_punti(struct sgiocatore**players,int num,float vinc)
{
	int k=0;
	int maxscore=0;
	int vincitore=0;
	for(k=0;k<num;k++)
	{
		(*players)[k].europeruno-=(*players)[k].puntata;
		if((*players)[k].valori[0][0]!=-1)
		{
			if((*players)[k].punteggio>maxscore)
			{
				maxscore=(*players)[k].punteggio;
				vincitore=k;
			}
		}
	}
	printf("\nil vincitore della mano e' il giocatore %d, che si aggiudica la vincita di %.2f euro",vincitore+1,vinc);
	(*players)[k].europeruno+=vinc;
}
void vit_per_abbandono(struct sgiocatore**players,int num,float vinc_iniz)
{
	int k=0;
	int vincitore=0;
	float vincita=0;
	for(k=0;k<num;k++)
	{
		vincita+=(*players)[k].puntata;
		(*players)[k].europeruno-=(*players)[k].puntata;
		if((*players)[k].valori[0][0]!=-1)
		{
			vincitore=k;
		}
	}
	vincita+=vinc_iniz;
	printf("il giocatore %d si aggiudica tutta la vincita:%.2f euro\n",vincitore+1,vincita);
	for(k=0;k<num;k++)
	{
		if((*players)[k].valori[0][0]==-1)
		{
			printf("al giocatore %d rimangono %.2f euro\n",k+1,(*players)[k].europeruno);
		}
	}
	(*players)[vincitore].europeruno=(*players)[vincitore].europeruno+vincita;
	printf("il giocatore %d ora ha %.2f euro\n",vincitore+1,(*players)[vincitore].europeruno);
}
void ord_carte(struct sgiocatore** players,int num)
{
	int k=0;
	int z=0;
	int x=0;
	int tmp=0;
	int tmp2=0;
	for(k=0;k<num;k++)
	{
		for(z=0;z<5;z++)
		{
			for(x=0;x<5;x++)
			{
				if((*players)[k].valori[z][0]>(*players)[k].valori[x][0]&&z<x)
				{
					tmp=(*players)[k].valori[x][0];
					tmp2=(*players)[k].valori[x][1];
					(*players)[k].valori[x][0]=(*players)[k].valori[z][0];
					(*players)[k].valori[x][1]=(*players)[k].valori[z][1];
					(*players)[k].valori[z][0]=tmp;
					(*players)[k].valori[z][1]=tmp2;
				}
			}
		}
	}
}
void punteggio(struct sgiocatore**players,int num)
{
	int k=0;
	int z=0;
	int x=0;
	int c=0;
	int pos=0;
	int interruzione=0;
	int coppia=0;
	int dopcoppia=0;
	int tris=0;
	int poker=0;
	int full=0;
	int colore=0;
	int scala=0;
	int fine=0;
	int somma=0;
	int maxscore=0;
	for(k=0;k<num;k++)
	{
		coppia=0;
		dopcoppia=0;
		tris=0;
		scala=0;
		full=0;
		colore=0;
		poker=0;
		fine=0;
		z=0;
		(*players)[k].punteggio=0;
		if((*players)[k].valori[0][0]!=-1)
		{	
			for(z=0;z<4;z++)
			{			
				if((*players)[k].valori[z][0]==(*players)[k].valori[z+1][0]-1)
				{
					scala++;
				}
				if((*players)[k].valori[z][1]==(*players)[k].valori[z+1][1])
				{
					colore++;
				}
			}
			if(scala==4)
			{
				scala=1;
				somma=(*players)[k].valori[4][0];
			}
			else
			{
				scala=0;
			}
			if(colore==4)
			{
				colore=1;
				somma=(*players)[k].valori[4][0];
			}
			else
			{
				colore=0;
			}
			for(z=0;z<13;z++)
			{
				(*players)[k].volte[z]=0;
			}
			for(z=0;z<5;z++)
			{
				for(x=0;x<13;x++)
				{
					if((*players)[k].valori[z][0]==x+1)
					{
						(*players)[k].volte[x]++;
					}
				}
			}
			for(z=0;z<13;z++)
			{
				if((*players)[k].volte[z]==2&&colore==0)
				{
					if(coppia==1)
					{
						coppia=0;
						dopcoppia=1;
						somma=z+1;
					}
					else
					{
						if(tris==1)
						{
							tris=0;
							full=1;
							somma=z+1;
						}
						else
						{
							coppia=1;
							somma=z+1;
						}
					}
				}
				if((*players)[k].volte[z]==3&&colore==0)
				{
					if(coppia==1)
					{
						full=1;
						coppia=0;
						somma=z+1;
					}
					else
					{
						tris=1;
						dopcoppia=0;
						somma=z+1;
					}
				}
				if((*players)[k].volte[z]==4)
				{
					poker=1;
					tris=0;
					coppia=0;
					dopcoppia=0;
					somma=z+1;
				}
			}
			if(coppia==1)
			{
				(*players)[k].punteggio=100;
			}
			if(dopcoppia==1)
			{
				(*players)[k].punteggio=200;
			}
			if(tris==1)
			{
				(*players)[k].punteggio=300;
			}
			if(scala==1)
			{
				(*players)[k].punteggio=400;
			}
			if(full==1)
			{
				(*players)[k].punteggio=500;
			}
			if(colore==1)
			{
				(*players)[k].punteggio=600;
			}
			if(poker==1)
			{
				(*players)[k].punteggio=700;
			}
			if((*players)[k].punteggio==0)
			{
				somma=(*players)[k].valori[4][0];
			}
			(*players)[k].punteggio+=somma;
		}
	}
}
int main()
{
	int n=0;
	int k=0;
	float denaro=0;
	float cheap=0;
	struct sgiocatore*players;
	struct smazzo mazzo;
	int scelta=0;
	float vincita=0;
	int z=0;
	int c=0;
	int fine;
	printf("\t\t\t-------GIOCO DEL POKER-------\n\n");
	n=giocatori();
	players=(struct sgiocatore*)malloc(n*sizeof(struct sgiocatore));
	if(players==NULL)
	{
		printf("spazio insufficiente");
		free(players);
		exit(0);
	}
	printf("quant'e' il denaro in euro che possiede ciascun giocatore?\t");
	while(scanf("%f",&denaro)==0||denaro<10)
	{
		printf("\ndigita un ammontare in euro maggiore di 9\t");
		fflush(stdin);
	}
	fflush(stdin);
	for(k=0;k<n;k++)
	{
		players[k].europeruno=denaro;
		players[k].punteggio=0;
	}
	vincita=0;
	while(fine==0)
	{
		vincita=0;
		printf("\t\t\t-------MANO DI POKER-------\n\n");
		c=0;
		for(k=0;k<n;k++)
	{
		if(players[k].europeruno>0)
		{
			cheap=(0.05)*players[k].europeruno;
			vincita+=cheap;
		}
	}
	initmazzo(&mazzo);
	mescolatore(&mazzo);
	distributore(&mazzo,&players,n);
	ord_carte(&players,n);
	system("cls");
	printf("\nla somma da versare obbligatoriamente all'inizio corrisponde al 5 percento del deposito personale di ogni giocatore=%.2f euro\n",cheap);
	printf("\nattualmente la vincita corrisponde a %.2f euro\n",vincita);
	for(k=0;k<n;k++)
	{
		players[k].europeruno-=cheap;
		players[k].puntata=0;
	}
	printf("\n\n");
	system("pause");
	system("cls");
	printf("\t\t\t\tPRIMO TURNO DI PUNTATA\n\n");
	for(k=0;k<n;k++)
	{
		if(players[k].valori[0][0]!=-1)
		{
			printf("\t");
			stampaplayer(players,k);
			printf("\nil suo patrimonio e' %.2f euro\n",players[k].europeruno);
			printf("\nabbandoni o punti una cifra?(1 per abbandono, 0 per puntata)\t");
			if(k!=0)
			{
				printf("\n\nRicorda! devi puntare una cifra pari o superiore a quella del giocatore precedente\t");
			}
			while(scanf("%d",&scelta)==0||(scelta!=1&&scelta!=0))
			{
				printf("\ndigita 1 o 0\t");
				fflush(stdin);
			}
			fflush(stdin);
			if(scelta==1)
			{
				printf("il giocatore %d abbandona\n",k+1);
				abbandono(&mazzo,&players,k);
				c++;
			}
			if(scelta==0)
			{
				printf("\nil giocatore %d punta una cifra\n",k+1);
				players[k].puntata=puntata(&players,k);
				while(players[k].puntata<puntmax(players,n))
				{
					printf("\nla puntata del giocatore %d e' minore di quella del giocatore %d.Ripunta\n",k+1,giocmax(players,n,puntmax(players,n))+1);
					players[k].puntata=puntata(&players,k);
				}
			}
			system("cls");
		}
		if(k==n-1)//ritorno al punto di partenza se uno dei giocatori non ha puntato quanto un altro
		{
			for(z=0;z<n;z++)
			{
				if(players[z].valori[0][0]!=-1)
				{
					if(players[z].puntata!=puntmax(players,n))
					{
						k=-1;
						printf("il giocatore %d deve rilanciare per poter continuare a giocare\n",z+1);
					}
				}
			}
		}
		if(c==n-1)
		{
			vit_per_abbandono(&players,n,vincita);
		}
	}
	if(c<n-1)
	{
		for(k=0;k<n;k++)
		{
			vincita+=players[k].puntata;
			players[k].europeruno-=players[k].puntata;
			players[k].puntata=0;
		}
		printf("\nattualmente la vincita corrisponde a %.2f euro\n",vincita);
		system("pause");
		system("cls");
		for(k=0;k<n;k++)//cambio carta
		{
			if(players[k].valori[0][0]!=-1)
			{
				stampaplayer(players,k);
				printf("\nvuoi cambiare la carte?(1 per si, 0 per no)\n");
				while(scanf("%d",&scelta)==0||(scelta!=1&&scelta!=0))
				{
					printf("digita 1 o 0\n");
					fflush(stdin);
				}
				fflush(stdin);
				if(scelta==1)
				{
					cambia_carte(&mazzo,&players,k);
					ord_carte(&players,n);
					printf("\n\t\t\t\tNUOVE CARTE\n");
					stampaplayer(players,k);
					system("pause");
					system("cls");
					puts("");
				}
				system("cls");
			}
		}
		printf("\t\t\t\tSECONDO TURNO DI PUNTATA\n\n");	
		for(k=0;k<n;k++)
		{
			if(players[k].valori[0][0]!=-1)
			{
				printf("\t");
				stampaplayer(players,k);
				printf("\nil suo patrimonio e' %.2f euro\n",players[k].europeruno);
				printf("\nabbandoni o punti una cifra?(1 per abbandono, 0 per puntata)\t");
				if(k!=0)
				{
					printf("\n\nRicorda! devi puntare una cifra pari o superiore a quella del giocatore precedente\t");
				}
				while(scanf("%d",&scelta)==0||(scelta!=1&&scelta!=0))
				{
					printf("\ndigita 1 o 0\t");
					fflush(stdin);
				}
				fflush(stdin);
				if(scelta==1)
				{
					printf("il giocatore %d abbandona\n",k+1);
					abbandono(&mazzo,&players,k);
					c++;
				}
				if(scelta==0)
				{
					printf("\nil giocatore %d punta una cifra\n",k+1);
					players[k].puntata=puntata(&players,k);
					while(players[k].puntata<puntmax(players,n))
					{
						printf("\nla puntata del giocatore %d e' minore di quella del giocatore %d.Ripunta\n",k+1,giocmax(players,n,puntmax(players,n))+1);
						players[k].puntata=puntata(&players,k);
					}
				}
				system("cls");
			}
			if(k==n-1)//ritorno al punto di partenza se uno dei giocatori non ha puntato quanto un altro
			{
				for(z=0;z<n;z++)
				{
					if(players[z].valori[0][0]!=-1)
					{
						if(players[z].puntata!=puntmax(players,n))
						{
							k=-1;
							printf("il giocatore %d deve rilanciare per poter continuare a giocare\n",z+1);
						}
					}
				}
			}
			if(c==n-1)
			{
				vit_per_abbandono(&players,n,vincita);
			}
		}
		if(c<n-1)
		{
			for(k=0;k<n;k++)
			{
				vincita+=players[k].puntata;
				players[k].europeruno-=players[k].puntata;
			}
			printf("attualmente la vincita corrisponde a %.2f euro\n",vincita);
			printf("si procede allo spoglio delle carte per determinare il vincitore\n");
			punteggio(&players,n);
			for(k=0;k<n;k++)
			{
				if(players[k].valori[0][0]!=-1)
				{
					stampaplayer(players,k);
					if(players[k].punteggio<100)
					{
						printf("\nil giocatore %d non ha fatto alcuna combinazione\n",k+1);
					}
					if(players[k].punteggio>=100&&players[k].punteggio<200)
					{
						printf("\nil giocatore %d ha fatto coppia\n",k+1);
					}
					if(players[k].punteggio>=200&&players[k].punteggio<300)
					{
						printf("\nil giocatore %d ha fatto doppia coppia\n",k+1);
					}
					if(players[k].punteggio>=300&&players[k].punteggio<400)
					{
						printf("\nil giocatore %d ha fatto tris\n",k+1);
					}
					if(players[k].punteggio>=400&&players[k].punteggio<500)
					{
						printf("\nil giocatore %d ha fatto scala\n",k+1);
					}
					if(players[k].punteggio>=500&&players[k].punteggio<600)
					{
						printf("\nil giocatore %d ha fatto full\n",k+1);
					}
					if(players[k].punteggio>=600&&players[k].punteggio<700)
					{
						printf("\nil giocatore %d ha fatto colore\n",k+1);
					}
					if(players[k].punteggio>=700)
					{
						printf("\nil giocatore %d ha fatto poker\n",k+1);
					}
				}
			}
			vit_per_punti(&players,n,vincita);
		}
	}	
		z=0;
		for(k=0;k<n;k++)
		{
			if(players[k].europeruno==0)
			{
				z++;
			}
		}
		if(z==n-1)
		{
			fine=1;
		}
	}
	free(players);
	return 0;
}
