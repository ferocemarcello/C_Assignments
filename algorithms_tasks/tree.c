# define BASE 65
#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	unsigned short **griglia;
	struct NODE*brother;
	struct NODE*son;
}NODE;


static unsigned short **ushort_matrix_alloc(int row, int col) {
  unsigned short **m=NULL;
  int i;

  if((m=(unsigned short **)calloc(row,sizeof(unsigned short *)))!=NULL) {
    if((m[0]=(unsigned short *)calloc(row*col,sizeof(unsigned short)))==NULL) {
      free(m);
      m=NULL;
    } else {
      for(i=1; i<row; i++)
        m[i]=&m[i-1][col];
    }
  }
  return m;
}


NODE*node_alloc(int M,int N)//il padre punta solo a un figlio, il figlio punta ai fratelli
{
	NODE*node=(NODE*)malloc(sizeof(NODE));
	if(node==NULL)return NULL;
	node->griglia=ushort_matrix_alloc(M,N);
	node->brother=NULL;
	node->son=NULL;
	return node;
}
NODE* init_radice(int M,int N)
{
	NODE*radice;
	radice=node_alloc(M,N);
	(radice->griglia)[0][0]=1;
	radice->brother=NULL;
	radice->son=NULL;
	return radice;
}
NODE* create_son(NODE*padre,int M,int N)
{
	NODE*figlio;
	figlio=node_alloc(M,N);
	padre->son=figlio;
	while(padre->brother)
	return figlio;
}
void stampanodo(NODE*nodo,int M,int N)
{
	int i=0;
	int j=0;
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d\t",nodo->griglia[i][j]);
		}
		puts("");
	}
}
int stampaalbero(NODE*nodo,int M,int N)
{
	int i=0;
	int j=0;
	if(nodo->son==NULL)
	{
		return NULL;
	}
	NODE*tmp=nodo;
	while(tmp!=NULL)
	{
		stampanodo(tmp,M,N);
		if(tmp->brother!=NULL)
		{
			tmp=tmp->brother;
		}
		else
		{
			tmp=tmp->son;
		}
	}
}
int z=0;
	NODE * randtree (int M,int N,int k)
	{
	//static z=0;	
	int j;
	int i=0;
	int s=0;
	NODE *T, *tmp ;
		T=node_alloc(M,N);
		if(M >0 && N >0 && k >0&&M*N-z>0)
		{
			printf("test");
				for (s=0; s<M*N-z; s++)
				{
					if (( tmp=randtree ( M,N,k))!= NULL )
					{
						for(i=0;i<M;i++)
						{
							for(j=0;j<N;j++)
							{
								tmp->griglia[i][j]=-1;
							}
						}
						tmp->brother =T->son ;
						T->son=tmp;
					}
				}
				z++;	
			return T;
		}
		else return NULL ;
}
int main()
{
	int i=0, j=0;
	NODE*testa=NULL;
	//testa=randtree(2,2,3);
	testa=node_alloc(3,3);
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			testa->griglia[i][j]=-1;
			
		}
	}
	printf("%d\n",testa->griglia[0][0]);
	//stampanodo(testa,2,2);
	return 0;
}
