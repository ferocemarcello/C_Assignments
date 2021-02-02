#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	int key ;
	struct NODE * left ;
	struct NODE * right ;
}NODE;
NODE*NodeAlloc(int key )
{
	NODE*node=(NODE*)malloc(sizeof(NODE));
	if(node==NULL) return NULL;
	node->key=key;
	node->left=NULL;
	node->right=NULL;
	return node;
}
void InsKey(NODE*T,int key)
{
	if(key<(T->key))
	{
		if((T->left)==NULL)
		{
			T->left=NodeAlloc(key);
		}
		else
		{
			InsKey(T->left,key);
		}
	}
	else
	{
		if(key>(T->key))
		{
			if((T->right)==NULL)
			{
				T->right=NodeAlloc(key);
			}
			else
			{
				InsKey(T->right, key);
			}
		}
	}
}
NODE* CreateTree(int*A, int n)
{
	NODE*T;
	int i=0;
	T=NULL;
	if(n>1)
	{
		T=NodeAlloc(A[0]);
		for(i=0;i<n;i++)
		{
			InsKey(T,A[i]);
		}
	}
	return T;
}
void DeleteTree(NODE*T)
{
	if(T!=NULL)
	{
		DeleteTree(T->left);
		DeleteTree(T->right);
		free(T);
	}
}
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
void PreOrder(NODE*T)
{
	if(T!=NULL)
	{
		printf("%d\t",T->key);
		PreOrder(T->left);
		PreOrder(T->right);
	}
}
void InOrder(NODE*T)
{
	if(T!=NULL)
	{
		InOrder(T->left);
		printf("%d\t",T->key);
		InOrder(T->right);
	}
}
void PostOrder(NODE*T)
{
	if(T!=NULL)
	{
		PostOrder(T->left);
		PostOrder(T->right);
		printf("%d\t",T->key);
	}
}
NODE*Search(NODE*T,int key)
{
	if (T==NULL) return NULL;
	if((T->key)==key) return T;
	if(key<(T->key)) return Search(T->left, key);
	else
	return Search(T->right,key);
}
NODE*SearchMin(NODE*T)
{
	if (T==NULL) return NULL;
	else
	{
		if((T->left)==NULL) return T;
		else
		return SearchMin(T->left);
	}
}
NODE*SearchMax(NODE*T)
{
	if (T==NULL) return NULL;
	else
	{
		if((T->right)==NULL) return T;
		else
		return SearchMax(T->right);
	}
}
int main(int argc, char *argv[])
{
	int n=0;
	int a=0;
	int*arr=readlist(argv[1], &n);
	NODE*NODO;
	NODO=CreateTree(arr,n);
	printf("disordinato\n\n");
	for(a=0;a<n;a++)//stampa
	{
		
		printf("%d\t",arr[a]);
		
	}
	printf("\n\npreorder\n\n");
	PreOrder(NODO);
	printf("\n\ninorder\n\n");
	InOrder(NODO);
	printf("\n\npostorder\n\n");
	PostOrder(NODO);
	printf("digita il numero da cercare\n\n");
	scanf("%d",&a);
	printf("a=%d\n\n",a);
	if(Search(NODO,a)!=NULL)
	printf("il numero e' presente nell'albero\n\n");
	else printf("il numero non e' presente\n\n");
	printf("il numero minimo e' %d\n\n",(SearchMin(NODO)->key));
	printf("il numero massimo e' %d",(SearchMax(NODO)->key));
	return 0;
}

