#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int *readlist(char *file, int *n)
{
	*n=0;//azzero il contatore di interi
	FILE *in;//puntatore a FILE
	int *list,x;//creo il puntatore che conterra tutti gli elementi letti; in x mettiamo il valore temporaneo letto dal file
	
	if((in=fopen(file,"r"))==NULL) return NULL;//controllo sull'istruzione
	while(fscanf(in,"%d",&x)!=EOF) (*n)++;//con n++aumento il numero di elementi del puntatore di ritorno, while fino a EOF(fine del file)
	if ((list = (int*)calloc(*n,sizeof(int)))==NULL) return NULL;//alloco le celle di memoria necessarie	
	rewind(in);//ci riporta all'inizio del file
	(*n)=0;//azzeriamo n, che è l'indice
	while(fscanf(in,"%d",&x)!=EOF) list[(*n)++]=x;//inserisco gli elementi
	fclose(in);//chiude il file
	return list;//restituisce un puntatore di interi
	
}
typedef struct NODE
{
	char name;
	int label;
	struct NODE*brother;
	struct NODE*children;
}NODE;
NODE*node_alloc(char name,int label)//il padre punta solo a un figlio, il figlio punta ai fratelli
{
	NODE*node=(NODE*)malloc(sizeof(NODE));
	if(node==NULL)return NULL;
	node->name=name;
	node->label=label;
	node->brother=NULL;
	node->children=NULL;
	return node;
}
NODE*randtree(int height,int children)
{
	static int X=0;
	if(height >0)
	{
		int i,n;
		NODE*T,*tmp;
		X=(X+1)%26;//da a a z
		T=node_alloc(X,rand()%10);
		n=rand()%( children +1);
		for(i=0;i<n; i ++)
		if((tmp=randtree(height-1,children))!= NULL)
		{
			tmp->brother=T->children;
			T->children=tmp;
		}
		return T;
	} else return NULL ;
}
int Height(NODE*T)
{
	int n=0;
	NODE*C;
	int x=0
	int y=0;
	if(T==NULL)return 0;
	else
	{
		n=0;
		C=T->children;
		while(C!=NULL)
		{
			while((C->brother->)brother!=NULL)
			n=Max(n;Heigth(C));
			C=C->children;
		}
		return n+1;
	}
}
function DeleteTree(NODE*T)//fratello figlio free
{
	NODE*C;
	NODE*TESTA;
	TESTA=T;
	if(TESTA!=NULL)
	{
		C=T->children
		while(TESTA->children!=NULL)
		{
			TMP=C->children;
			TESTA=TESTA->children;
			DeleteTree(C);
		}
	}
	Delete(T)
	end if
	end function
}
int Max(n1;n2)
{
	if(n1>n2)
	{
		return n1;
	}
	else return n2;
}
int main()
{
	return 0;
}
