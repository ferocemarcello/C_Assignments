#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void quicksort3(int*A,int p,int r)
{
	int i=0;
	int j=0;
	if(p<r)
	{
		TWP(A,p,r,&i,&j);
		quicksort3(A,p,i);
		quicksort3(A,j,r);
		
	}
	return;
}
void swap(int*A,int i,int j)
{
	int tmp;
	tmp=A[i];
	A[i]=A[j];
	A[j]=tmp;
}
int TWP(int*A,int p,int r, int*i, int*j)
{
	int pivot=A[Pivot(A,p,r)];
	int l=p;
	int m=p;
	int h=r;
	while (m<=h)
	{
		if(A[m]<pivot)
		{
			swap(A,m,l);
			m++;
			l++;
		}
		else
		{
			if(A[m]>pivot)
			{
				swap(A,m,h);
				h--;
			}
			else m++;
		}
	}
	(*i)=l-1;
	(*j)=h+1;
	return 0;
}
int Pivot(int*A,int p,int r)
{
	srand((unsigned) time(NULL));
	int x=0;
	x= p + rand()%(r-p);
	return x;
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
		arr[c]=rand() % 10000;
	}
	puts("");
	for(c=0;c<y;c++)
	{
		printf("%d\t",*(arr+c));
	}
	puts("");
	printf("quicksort\n");
	quicksort3(arr,0,y-1);
	for(c=0;c<y;c++)
	{
		printf("%d\t",*(arr+c));
	}
	return 0;
}
