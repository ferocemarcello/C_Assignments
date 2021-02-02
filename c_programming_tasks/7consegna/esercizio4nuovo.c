#include<stdio.h>
#include<stdlib.h>
int main()
{
	char c;
	int a=0;
	int b=0;
	int d=0;
	int e=0;
	int nparole=1;
	int lungparola=0;
	char **testo;
	char**frase;
	testo=(char**)malloc(40*sizeof(char*));
	testo[0]=(char*)malloc(lungparola*sizeof(char));
	printf("nparole=%d\n",nparole);
	printf("lungparola=%d\n",lungparola);
	printf("digita una frase\n");
	c=getchar();
	//testo[a][b]=c;
	//printf("testo[a][b]=%c\n",testo[a][b]);
	while(c!='\n')
	{
		printf("c=%c\n",c);
		printf("a=%d\n",a);
		printf("b=%d\n",b);
		if(c!=' ')
		{
			lungparola++;
			testo[a]=(char*)realloc(testo[a],lungparola*sizeof(char));
			testo[a][b]=c;
			printf("testo[%d][%d]=%c\n",a,b,testo[a][b]);
			b++;
		}
		else
		{
			lungparola=0;
			testo[a][b]='\0';
			a++;//incremento l'indicatore riga
			nparole++;
			//testo=(char**)realloc(testo,nparole*sizeof(char*));
			b=0;
		}
		
		printf("nparole=%d\n",nparole);
		printf("lungparola=%d\n",lungparola);
		c=getchar();
	}
	frase=(char**)malloc(nparole*sizeof(char*));
	frase[d]=(char*)malloc(lungparola*sizeof(char));
	for(d=0;d<nparole;d++)
	{
		while(testo[d][e]!='\0')
		{
			printf("%c",testo[d][e]);
			e++;
		}
		d++;
		printf(" ");
		
	}
	return 0;	
}
