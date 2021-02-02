#include<stdio.h>
#include<stdlib.h>
int main()
{
	float dec;
	int resto=0;
	int c=0;
	int dec2=0;
	int d=0;
	
	printf("Inserire intero n\n");
	scanf("%f",&dec);
	while(dec!=(int)dec)
	{
		printf("il numero digitato deve essere intero\n");
		printf("digita un altro numero");scanf("%f",&dec);
	}
	dec2=dec;
	while((int)dec/2!=0)
	{
		dec=dec/2;
		c=c+1;
	}
	d=c;
	int bin[c];
	while (c>=0)
	{
		resto=dec2%2;
		dec2=dec2/2;
		bin[c]=resto;
		--c;
	}
	printf("il numero binario e'");
	for(c=0;d>=c;++c)
	{
		printf("%d",bin[c]);
	}
	return 0;
}
