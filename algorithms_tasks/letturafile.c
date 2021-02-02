#include<stdio.h>
#include<stdlib.h>
int*readlist(char*file, int*n)
{
	FILE*in;
	int *list,x;
	
	if((in=fopen(file,"r"))==NULL) return NULL;
	while(fscanf(in,"%d",&x)!=EOF) (*n)++;
	if((list=(int*)calloc(*n,sizeof(int)))==NULL)
	return NULL;
	rewind(in);
	(*n)=0;
	while(fscanf(in,"%d",&x)!=EOF) list[(*n)++]=x;
	fclose(in);
	return list;
}
void main()
{
	//int*lista=readlist();
}
