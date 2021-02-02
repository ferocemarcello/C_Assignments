#include<stdio.h>
#include<stdlib.h>
void main(int argc, char* argv[])
{
	int risultato;
	int a;int b;
	if(argc!=3)//un parametro in più
	{
		printf("errore");
		return;
	}
	a=atoi(argv[1]);
	b=atoi(argv[2]);
	risultato = a+b;
	printf("ri=%d",risultato);
	
	
		
}
