#include<stdio.h>
#include<stdlib.h>
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
int Minimax(NODE*T;int player)
{
	if (T->children==NULL)
	{
		return best=Evaluate(T);
	}
	else
	{
		
	}
if player=TRUE then
best   1
for c 2 Children(T) do
best  Min(best,Minimax(c,FALSE))
end for
else
best   ..1
for c 2 Children(T) do
best  Max(best,Minimax(c,TRUE))
end for
end if
Label(T)   best
return best
end function
}
int main()
{
	return 0;
}
