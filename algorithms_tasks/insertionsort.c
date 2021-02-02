#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
	printf("elementi arraY:\n");
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
	insertion(arr,0,y);
	system("pause");
	for(c=0;c<y;c++)
	{
		printf("%d\n",*(arr+c));
	}
	puts("");
	int vet[]={2,3,6,2,7,1,8,9,11,14,4};
	for(c=0;c<11;c++)
	{
		printf("%d\n",vet[c]);
	}
	puts("");
	insertion(vet,0,10);
	for(c=0;c<11;c++)
	{
		printf("%d\n",vet[c]);
	}
	return 0;
}
