#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void quicksort(int*A,int p,int r)
{
	int q;
	if(p<r)
	{
		q=partition(A,p,r);
		quicksort(A,p,q);
		quicksort(A,q+1,r);
		
	}
	return;
}
int Pivot(int*A,int p,int r)
{
	srand((unsigned) time(NULL));
	int x=0;
	x= p + rand()%(r-p);
	return x;
}
void swap(int*A,int i,int j)
{
	int tmp;
	tmp=A[i];
	A[i]=A[j];
	A[j]=tmp;
	return;
}
int partition(int*A,int p,int r)
{
	int i;
	int j;
	int q;
	int pivot;
	i=p;
	j=r;
	q=Pivot(A,p,r);
	swap(A,q,p);
	pivot=A[p];
	while(i<j)
	{
		while(j>p&&pivot<=A[j])
		{
			j--;
		}
		while(i<r && pivot>A[i])
		{
			i++;
		}
		if(i<j)
		{
			swap(A,i,j);
			
		}
	}
	swap(A,p,j);
	return j;
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
	printf("quicksort\n");
	quicksort(arr,0,y-1);
	for(c=0;c<y;c++)
	{
		printf("%d\n",*(arr+c));
	}
	return 0;
}
