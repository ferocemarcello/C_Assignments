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
void mergesort(int*A,int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		mergesort(A,p,q);
		mergesort(A,q+1,r);
		merge(A,p,q,r);
	}
	return;
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
	mergesort(arr,0, y-1);
	for(c=0;c<y;c++)
	{
		printf("%d\n",*(arr+c));
	}
	free(arr);
	return 0;
}
