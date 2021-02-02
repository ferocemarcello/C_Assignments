#include<stdio.h>
#include<stdlib.h>
	
	int *Split(int k,int p,int r)
	{
		
		int lung=(r-p+1)/k;
		int tmp,i=0;
		int* L;
		L=(int*)malloc((k+1)*sizeof(int));
		if(L==NULL)exit(1);
		L[0]=p;
		for(tmp=0;tmp<(k+1);tmp++)
		{
			L[tmp]=p;
			p+=lung;	
		}
		return(L);
	}
	
	int main()
	{
		int A[]={1,10,12,20,2,3,15,21,5,8,13,19,24};
		int* L;
		int B[13];
		int k=3;
		int p=0;
		int r=12;
		int i;
		int lp=(r-p+1)/k; //lp è la lunghezza della partizione
		int j;
		int s=0;
		int x=0;

		int z=0;
		int w=0;
		int f=1;
		
		L=Split(k,p,r);
	
		int y=0;										//il ciclo di y parte da 0 dovrebbe arrivare a 4 (sono gli indici di L)
		while(y+1<k) //k+1 + la lunghezza di L
		{
				i=0;
				j=L[y+1]; //Al primo ciclo L[1]=2, per cui j parte da 2, al secondo ciclo l[2]=4, per cui j parte da 4, al terzo ciclo L[3]=6 ma j non parte perchè j+1<3
				z=0;
				w=0;
				s=0;
				
				while(z<f*lp && w<lp)
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
		
			
				while(z<f*lp) //(r-p+1)/k è la lunghezza della partizione secondo Marcello
				{
					B[s]=A[i];
					i++;
					z++;
					s++;
				}
				
				while(w<lp)
				{
					B[s]=A[j];
					j++;
					w++;
					s++;
				}
				
				f++;
				for(x=0;x<f*lp;x++)
				{
					A[x]=B[x];
				}
				
			y++;
		}
	
	for(x=0;x<f*lp;x++)
	{
		printf(" %d ",A[x]);
	}
				
	return 0;
	}


