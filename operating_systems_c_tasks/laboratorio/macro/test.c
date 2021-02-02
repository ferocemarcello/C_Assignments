#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include "macro.h"

int main()
{

int32_t* vaff;
int i;
CIAO(vaff);
for(i=0;i<10;i++)
{
	printf("%d\n",*(vaff+i));
}
for(i=0;i<10;i++)
{
	*(vaff+i)=19+i;
}
for(i=0;i<10;i++)
{
	printf("%d\n",*(vaff+i));
}
return 0;
}
