#include<stdio.h>
#include<stdlib.h>
int*ottienipuntatore(char*doc,int n)
{
	int*punt;
	int*fp;
	int k=0;
	punt=(int*)malloc(n*sizeof(int));
	fp=fopen(doc,"r");
	for(k=0;k<n;k++)
	{
		fscanf(fp,"%d",&(punt[k]));
	}
	fclose(fp);
	return punt;
}
void main()
{
	int*vet;
	int k=0;
	vet=ottienipuntatore("numeri.txt",5);
	/*int vet[10];
	int k=0;
	FILE*fp;
	fp=fopen("numeri.txt","r");
	for(k=0;k<10;k++)
	{
		fscanf(fp,"%d",&(vet[k]));
	}
	fclose(fp);
	*/
	for(k=0;k<5;k++)
	{
		printf("%d\n",vet[k]);
	}
	//int*lista=readlist();
}
