#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
void NewickPrint(NODE*T, int type)
{
	if(T!=NULL)
	{
		PrintSubtree(T,type);
	}
	Print(';');
}
	procedure PrintSubtree(NODE*T;int type)
{
	NODE*c=T->children;
	NODE*b;
	if(T->children!=NULL)
	{
		Printf("('(')");
		while(c!=NULL)
			{
				b=c;
				while((b->brother)!=NULL)
				{
					PrintSubtree(b,type)
					if(b->brother!=NULL&&b->children!=NULL)
					{
						printf("(',')");
					}
					b=b->brother;
				}
				c=c->children;
			}
		Printf("(')')");
	}
	PrintData(T,type)
}

void PrintData(NODE*T,int type)//dafinire
{
	if(type==1)
	{
		if(IsLeaf(T))
		{
			printf("%d",T.label);
		}
	}
	else
	{
		if(type==2)
		{
			if(IsLeaf(T))
			{
				printf("%d",T.label);
			}
		}
	}
	Print(NLabel(T))
	end if
	print(':'+ELabel(T))
	else if type = 3 then
	Print(NLabel(T))
	else if type = 4 then
	Print(NLabel(T)+':'+ELabel(T))
	end if
}

int main()
{
	
}
