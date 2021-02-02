#include<stdio.h>
#include<stdlib.h>
typedef struct nodolista
{
int key;
struct nodolista*next;
}NODOLISTA;
void inserisci(NODOLISTA**root)
{
	NODOLISTA*temp;
	temp=(NODOLISTA*=malloc(sizeof(NODOLISTA));
	if(!temp)
	{
		exit(1);
	}
	temp->key=key;
	temp->next=*root;
	*root->next=temp;
}
void elimina(NODOLISTA**root)
{
	NODOLISTA*temp=*root;
	NODOLISTA*temp2;
	if(**root->key==key)
{
	*root=*root->next;
}
else
{
	while(temp->next!=NULL)
	{
		if(temp->next->key==key)
		{
			temp2=temp->next;
			temp->next=temp->next->next;
			free(temp2)
		}
	temp=temp->next;	

	}	
}

		
}
int main()
{
NODOLISTA *root=NULL;
int ris;
return 0;
}