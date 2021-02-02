#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
void mergesort2(int*A,int p,int r)
/*limitiamo il numero di chiamate ricorsive, applicando
direttamente un algoritmo in place (ad esempio, InsertionSort) su
sotto-array piu piccoli di una dimensione predenita K
*/
{
	int q;
	int k=10;
	if(r-p+1>k)
	{
		q=(p+r)/2;
		mergesort2(A,p,q);
		mergesort2(A,q+1,r);
		merge(A,p,q,r);
	}
	else
	insertionsort(A,p,r);
	return;
}
void insertionsort(int*A,int p,int r)
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
				A[i+1]=A[i];;
				i=i-1;
			}
			A[i+1]=key;
		}
	}
}
int main()
{
	int c=0;int y=0;
	srand((unsigned) time(NULL));
	printf("elementi array:\n");
	scanf("%d",&y);
	int*arr;
	arr=(int*)(malloc(y*sizeof(int)));
	for(c=0;c<y;c++)
	{
		arr[c]=rand() % 100;
	}
	puts("");
	for(c=0;c<y;c++)
	{
		printf("%d\n",*(arr+c));
	}
	puts("");
	printf("merge\n");
	puts("");
	mergesort2(arr,0, y-1);
	for(c=0;c<y;c++)
	{
		printf("%d\n",*(arr+c));
	}
	free(arr);
	return 0;
}
