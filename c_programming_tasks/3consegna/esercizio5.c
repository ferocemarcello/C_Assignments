//marcello feroce primo anno ingegneria e scienze informatiche matricola numero 0000730777
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
	char carattere;
	int ascii;
	printf("digita un singolo carattere\n");
	carattere=getchar();
	while(getchar()!='\n')
	{
		fflush(stdin);//liberiamo il buffer. in questo caso stdin
		printf("errore!inserisci solo un carattere\n");
		printf("scrivi un altro carattere\n");
		carattere=getchar();
	}
	
	ascii=(int)carattere;
	printf("l'ascii e' %d\n",ascii);
	if((ascii>=48 && ascii<=57) || (ascii>=65 && ascii<=90) || (ascii>=97 && ascii<=122))
	{
		if(ascii>=48 && ascii<=57)
		{
			printf("il carattere e' un numero\n");
		}
	
	
		if(ascii>=65 && ascii<=90)
		{
			switch(ascii)
			{
				case(65):
				case(69):
				case(73):
				case(79):
				case(85):printf("il carattere e' una lettera vocale in formato maiuscolo\n");break;
				default:printf("il carattere e' una lettera consonante in formato maiuscolo\n");
		
			}
			carattere=tolower(carattere);
			printf("carattere convertito=%c",carattere);
		}
	
		if(ascii>=97 && ascii<=122)
		{
			switch(ascii)
			{
				case(97):
				case(101):
				case(105):
				case(111):
				case(117):printf("il carattere e' una lettera vocale in formato minuscolo\n");break;
				default:printf("il carattere e' una lettera consonante in formato minuscolo\n");
	
			}
			carattere=toupper(carattere);
			printf("carattere convertito=%c",carattere);
		}

	}
	else{printf("il carattere e' un carattere speciale");}
	return 0;
}
