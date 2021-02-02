#include<stdio.h>
#include<stdlib.h>
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
void printlist(int *A, int n) {
  int i;
  for(i=0; i<n; i++)
    printf("%d ",A[i]);
  printf("\n");
}
void kMerge(int*A,int*L,int k, int p,int r)
{
	int*B;
	int i=0;
	int j=0;
	int x=0;
	int y=0;
	B=(int*)(malloc((r-p+1)*sizeof(int)));
	while(y<k-1)
	{
		i=L[0];
		j=L[y+1];
		printf("L[y+1]=%d\t",j);
		x=0;
		while(i<L[y+1] && j<L[y+2])
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
/*void kMerge(int*A,int*L,int k, int p,int r)
{
		int*B;
		int lp=(r-p+1)/k; //lp è la lunghezza della partizione
		int svanzo=0;
		svanzo=(r-p+1)-(lp*k);
		B=(int*)(malloc((r-p+1)*sizeof(int)));
		int i;
		int j;
		int s=0;
		int x=0;
		int z=0;
		int w=0;
		int f=1;
		int y=0;
		printf("%d\n",r);										//il ciclo di y parte da 0 dovrebbe arrivare a 4 (sono gli indici di L);
		while(y+1<k) //k+1 + la lunghezza di L
		{
				i=0;
				j=L[y+1]; //Al primo ciclo L[1]=2, per cui j parte da 2, al secondo ciclo l[2]=4, per cui j parte da 4, al terzo ciclo L[3]=6 ma j non parte perchè j+1<3
				z=0;
				w=0;
				s=0;
				if(f==k-1)
				{
					svanzo=(r-p+1)-(lp*k);
				}
				else
				{
					svanzo=0;
				}
				while(z<f*lp+svanzo && w<lp+svanzo)
				{
					if(A[i]<A[j])
					{
						B[s]=A[i];
						i++;
						z++;
					}
					else
					{
						B[s]=A[j];
						j++;
						w++;
					}
				s++;
				}
				while(z<f*lp+svanzo) //(r-p+1)/k è la lunghezza della partizione secondo Marcello
				{
					B[s]=A[i];
					i++;
					z++;
					s++;
				}		
				while(w<lp+svanzo)
				{
					B[s]=A[j];
					j++;
					w++;
					s++;
				}
				//f++;
				
				
				
				for(x=0;x<f*lp+svanzo;x++)
				{
					printf("%d  ",B[x]);
					A[x]=B[x];
				}
				puts("");
				f++;
			y++;
		}
free(B);
}*/
int *Split(int k,int p,int r)
{
	
	int lung=(r-p+1)/k;
	int svanzo=0;
	printf("lung=%d\n",lung);
	svanzo=(r-p+1)-(lung*k);
	printf("svanzo=%d\np=%d\nr=%d\n",svanzo,p,r);
	int tmp,i=0;
	int* L;
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
int main(int argc, char *argv[])
{
	int a;
	int n=0;
	int*list;
	int*L;
	list=readlist(argv[1],&n);
	a=atoi(argv[2]);
	printlist(list,n);
	L=Split(a,0,n-1);
	printlist(L,a+1);
	kMerge(list,L,a,0,n-1);
	printlist(list,n);
	return 0;
}
