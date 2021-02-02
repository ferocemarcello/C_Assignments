#include<stdio.h>
#include<stdlib.h>
void inverti_ricorsiva(char* testo,int lung)
{
	if(lung>0)
	{
		printf("%c",*(testo+lung-1));
		lung--;
		inverti_ricorsiva(testo,lung);
	}
}
void inverti_iterativa(char*testo,int lung)
{
	for(lung;lung>0;lung--)
	{
		printf("%c",*(testo+lung-1));
	}
}
int main()
{
	char* frase;
	char c;
	int a=0;
	frase=(char*)malloc(sizeof(char));
	printf("digita una frase\n");
	c=getchar();
	while(c!='\n')
	{
		*(frase+a)=c;
		a++;
		frase=(char*)realloc(frase,(a+1)*sizeof(char));
		c=getchar();
	}
	printf("a=%d\n",a);
	printf("la serie di caratteri invertita con una funzione iterativa e':\n");
	inverti_iterativa(frase,a);
	printf("\nla serie di caratteri invertita con una funzione ricorsiva e':\n");
	inverti_ricorsiva(frase,a);
}
