#include <stdio.h>
#include<stdlib.h>
int *Split(int k,int p,int r)
{
	
	int lung=(r+1)/k;
	int tmp,i=0;
	int* L;
	
	L=(int*)malloc((k+1)*sizeof(int));
	if(L==NULL)exit(1);
	
	L[0]=p;
	
	for(tmp=0;tmp<(k+1);tmp++)
	{
		L[tmp]=p;
		p+=lung;
		printf("%d\n", L[tmp]);		
	}	
	
	
	return(L);
}

void kmerge(int*A,int*L,int k, int p, int r)
{
	int q=(p+r)/k;
	int*B;
	B=(int*)(malloc((r-p+1)*sizeof(int)));
	int i=p;
	int j=q+1;
	int z=0;
	int x=0;
	int y=0;
	while(y<k+1)
	{
		z=L[y];
		x=L[y+1]-1;
		i=z;
		while(i<=x)
		{
			if(A[i]<A[x])
			{
				B[i]=A[i];
			}
			i++;	
		}
		y++;
	}
	for(y=p;y<=r;y++)
	{
		A[y]=B[y-p];
	}
	free(B);
	return;
	
}
void merge(int*A,int p, int q, int r)
{
	int i;
	int j;
	int k;
	int*B;
	B=(int*)(malloc((r-p+1)*sizeof(int)));
	i=p;
	j=q+1;
	k=0;
	while(i<=q && j<=r)
	{
		if(A[i]<A[j])
		{
			B[k]=A[i];
			i++;
		}
		else
		{
			B[k]=A[j];
			j++;
		}
		k++;
	}
	while(i<=q)
	{
		B[k]=A[i];
		i++;
		k++;
	}
	while(j<=r)
	{
		B[k]=A[j];
		j++;
		k++;
	}
	for(k=p;k<=r;k++)
	{
		A[k]=B[k-p];
	}
	free(B);
	return;
}

int main(){
	
	int k=5;
	int p=0;
	int r=15;
	int i;
	int* L;
	
	L=Split(k,p,r);
	
	getchar();
	
	return 0;
}
