#include <stdio.h>
#include <stdlib.h>
void printlist(int *A, int n) {
  int i;
  for(i=0; i<n; i++)
    printf("%d ",A[i]);
  printf("\n");
}
int *readlist(char *file, int *n) {
	FILE *in = fopen(file,"r");
	int *list,i,x;

	if(in==NULL) return NULL;
	i=0;
	while(fscanf(in,"%d",&x)!=EOF)
	{
		i++;
	}
	*n=i;
	if((list = (int *)calloc(*n,sizeof(int)))==NULL)
		return NULL;
	rewind(in);
	i=0;
	while(fscanf(in,"%d",&x)!=EOF) list[i++]=x;
	fclose(in);
	return list;
}
void kMerge(int*A,int*L,int k, int p,int r)//ordina k sequenze già singolarmente ordinate
{
	int*B;
	int i=0;
	int j=0;
	int x=0;
	int y=0;
	B=(int*)(malloc((r-p+1)*sizeof(int)));//vettore d'appoggio lungo r-p+1, che è la lunghezza dell'array, o del sottoarray
	while(y<k-1)//ciclo lungo come le partizioni-1
	{
		i=L[0];
		j=L[y+1];
		x=0;
		while(i<L[y+1] && j<L[y+2])//controllo la prima partizione con quella successiva
		{
			if(A[i]<A[j])
			{
				B[x]=A[i];
				i++;
			}
			else
			{
				B[x]=A[j];
				j++;
			}
			x++;
		}
		while(i<L[y+1])
		{
			B[x]=A[i];
			i++;
			x++;
		}
		while(j<L[y+2])
		{
			B[x]=A[j];
			j++;
			x++;
		}
		y++;
		for(i=0;i<x;i++)
		{
			A[i+p]=B[i];
		}
	}	
	free(B);
}
int *Split(int k,int p,int r)
{
	int lung=(r-p+1)/k;//lunghezza di una partizioni
	int svanzo=0;
	int tmp=0;
	int* L;
	svanzo=(r-p+1)-(lung*k);//lo svanzo è diverso da 0 se lunghezza non è divisibile per k(ad es k=3;10/3=3; svanzo=1
	L=(int*)malloc((k+1)*sizeof(int));
	if(L==NULL)exit(1);
	L[0]=p;
	for(tmp=0;tmp<(k+1);tmp++)
	{
		L[tmp]=p;
		if(tmp==k-1)
		{
			p+=lung+svanzo;
		}
		else
		{
			p+=lung;
		}	
	}
	return(L);
}
void insertion(int A[],int p,int r)
{
	int j=0;int i=0;int key=0;
	if(p<r)
	{
		for(j=p+1;j<=r;j++)
		{
			key=A[j];
			i=j-1;
			while(i>=p && A[i]>key)
			{
				A[i+1]=A[i];
				i=i-1;
			}
			A[i+1]=key;
		}
	}
}
void kMergeSort(int*A,int k,int p,int r )
{
	int*L;
	int i;
	if((r-p+1)/k>=1)
	{
		L=Split(k,p,r);
		for(i=0;i<k;i++)
		{
			kMergeSort(A,k,L[i],L[i+1]-1);
		}
		kMerge(A,L,k,p,r);
		free(L);
	}
	else
	{
		insertion(A,p,r);
	}
}
int main(int argc, char *argv[]) {
	int *list,n,k;
	int*L;

	if(argc!=3) {
		fprintf(stderr,"Usage: ksort <list> <k>\n");
		return 1;
	}
	
	if((list=readlist(argv[1],&n))==NULL) {
		fprintf(stderr,"Error reading %s\n",argv[1]);
		return 1;
	}
	if((k=atoi(argv[2]))<2) {
		fprintf(stderr,"Error: the k parameter %d should be >= 2 and <=n\n",k);
		return 1;	
	}
	if(k>n)
	{
		fprintf(stdout,"Mind! The parameter k is greater than array lenght\n");
	}
	kMergeSort(list,k,0,n-1);
	printlist(list,n);
	free(list);
	return 0;
}
