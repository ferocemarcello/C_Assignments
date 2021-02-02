#include <stdio.h>
#include <stdlib.h>
#include<time.h>
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
	while(fscanf(in,"%d",&x)!=EOF) i++;
	*n=i;
	if((list = (int *)calloc(*n,sizeof(int)))==NULL)
		return NULL;
	rewind(in);
	i=0;
	while(fscanf(in,"%d",&x)!=EOF) list[i++]=x;
	fclose(in);
	return list;
}
int *kPartition(int*A,int k,int p,int r)
{
	srand((unsigned) time(NULL));
	int x;
	int pivot=k-1;
	int y=0;
	int* L;
	L=(int*)malloc((k)*sizeof(int));
	for(y=0;y<k;y++)
	{
		L[y]=0;
	}
	y=0;
	if(L==NULL)exit(1);
	while(y<pivot)
	{
		L[y]=p+rand()%(r-p);
		if(y>0)
		{
			while(L[y]<=L[y-1])
			{
				L[y]=p+rand()%(r-p);
			}
		}
		printf("L[%d]=%d\n",y,L[y]);
		y++;
	}
	/*y=0;
	while(y<r-p+1)
	{
		if(A[y]<)
	}*/
	return(L);
}

void kQuickSort(int*A,int k,int p,int r )
{
	int*L;
	int i;
	if(p<r)
	{
		L=kPartition(A,k,p,r);
		for(i=0;i<k;i++)
		{
			kQuickSort(A,k,L[i ],L[i+1]-1);			
		}
	}
}

/*
 * 
 * Implementazione della procedura di ordinamento.
 *
 */


int main(int argc, char *argv[]) {
	int *list,n,k;

	if(argc!=3) {
		fprintf(stderr,"Usage: ksort <list> <k>\n");
		return 1;
	}
	
	if((list=readlist(argv[1],&n))==NULL) {
		fprintf(stderr,"Error reading %s\n",argv[1]);
		return 1;
	}
	if((k=atoi(argv[2]))<2) {
		fprintf(stderr,"Error: the k parameter %d should be >= 2\n",k);
		return 1;	
	}
	//kQuickSort(list,k,0,15);
	kPartition(list,k,0,15);
	/*
	 * Richiamare la procedura di ordinamento.
   */
	printlist(list,n);
	free(list);

	return 0;
}
