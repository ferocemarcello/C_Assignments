#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct sdata//struttura che prevede 2 giorni, 2 mesi, due anni(mesi letti come interi)
{
	int giorno[2];
	int mese[2];
	int anno[2];
	
}data;
int main()
{
	char mese[10];//lunghezza del mese composto da più caratteri=9(settembre)
	char mese2[10];
	int a=0;
	int b=0;
	printf("Data 1:\nimmetti il giorno\n");
	scanf("%d",&data.giorno[0]);//legge il giorno
	fflush(stdin);//pulisce il buffer della tastiera
	printf("Data 1:\nimmetti il mese\n");
	scanf("%s",&mese[0]);//legge il mese
	fflush(stdin);
	printf("Data 1:\nimmetti l'anno\n");
	scanf("%d",&data.anno[0]);//legge l'anno
	data.mese[0]=0;
	if(strcmp(mese,"gennaio")==0)data.mese[0]=1;//assegna un intero alla variabile data.mese in base al mese letto
	if(strcmp(mese,"febbraio")==0)data.mese[0]=2;
	if(strcmp(mese,"marzo")==0)data.mese[0]=3;
	if(strcmp(mese,"aprile")==0)data.mese[0]=4;
	if(strcmp(mese,"maggio")==0)data.mese[0]=5;
	if(strcmp(mese,"giugno")==0)data.mese[0]=6;
	if(strcmp(mese,"luglio")==0)data.mese[0]=7;
	if(strcmp(mese,"agosto")==0)data.mese[0]=8;
	if(strcmp(mese,"settembre")==0)data.mese[0]=9;
	if(strcmp(mese,"ottobre")==0)data.mese[0]=10;
	if(strcmp(mese,"novembre")==0)data.mese[0]=11;
	if(strcmp(mese,"dicembre")==0)data.mese[0]=12;
	while(data.mese[0]==0)//controllo affinche il mese sia corretto
	{
		printf("reinserisci il mese, mese scorretto");
		scanf("%s",&mese[0]);
		if(strcmp(mese,"gennaio")==0)data.mese[0]=1;
		if(strcmp(mese,"febbraio")==0)data.mese[0]=2;
		if(strcmp(mese,"marzo")==0)data.mese[0]=3;
		if(strcmp(mese,"aprile")==0)data.mese[0]=4;
		if(strcmp(mese,"maggio")==0)data.mese[0]=5;
		if(strcmp(mese,"giugno")==0)data.mese[0]=6;
		if(strcmp(mese,"luglio")==0)data.mese[0]=7;
		if(strcmp(mese,"agosto")==0)data.mese[0]=8;
		if(strcmp(mese,"settembre")==0)data.mese[0]=9;
		if(strcmp(mese,"ottobre")==0)data.mese[0]=10;
		if(strcmp(mese,"novembre")==0)data.mese[0]=11;
		if(strcmp(mese,"dicembre")==0)data.mese[0]=12;
	}
	a=data.mese[0];//assegno due variabili a e b corrispondenti all'intero del mese e al giorno
	b=data.giorno[0];
	while(a==2&&(b<1 || b>28))//controlli sul numero di giorni del mese
	{
		printf("reinserisci il giorno, giorno scorretto");
		scanf("%d",&b);
	}
	while((a==4||a==6||a==9||a==11)&&(b<1||b>30))
	{
		printf("reinserisci il giorno, giorno scorretto");
		scanf("%d",&b);
	}
	while((a==1||a==3||a==5||a==7||a==8||a==10||a==12)&&(b<1||b>31))
	{
		printf("reinserisci il giorno, giorno scorretto");
		scanf("%d",&b);
	}
	data.giorno[0]=b;
	/////////////////////////////////////////////////////////////////////////////////////////////
	printf("Data 2:\nimmetti il giorno\n");
	scanf("%d",&data.giorno[1]);
	fflush(stdin);
	printf("Data 2:\nimmetti il mese\n");
	scanf("%s",&mese2[0]);
	fflush(stdin);
	printf("Data 2:\nimmetti l'anno\n");
	scanf("%d",&data.anno[1]);
	data.mese[1]=0;
	if(strcmp(mese2,"gennaio")==0)data.mese[1]=1;
	if(strcmp(mese2,"febbraio")==0)data.mese[1]=2;
	if(strcmp(mese2,"marzo")==0)data.mese[1]=3;
	if(strcmp(mese2,"aprile")==0)data.mese[1]=4;
	if(strcmp(mese2,"maggio")==0)data.mese[1]=5;
	if(strcmp(mese2,"giugno")==0)data.mese[1]=6;
	if(strcmp(mese2,"luglio")==0)data.mese[1]=7;
	if(strcmp(mese2,"agosto")==0)data.mese[1]=8;
	if(strcmp(mese2,"settembre")==0)data.mese[1]=9;
	if(strcmp(mese2,"ottobre")==0)data.mese[1]=10;
	if(strcmp(mese2,"novembre")==0)data.mese[1]=11;
	if(strcmp(mese2,"dicembre")==0)data.mese[1]=12;
	while(data.mese[1]==0)
	{
		printf("reinserisci il mese, mese scorretto");
		scanf("%s",&mese2[0]);
		if(strcmp(mese2,"gennaio")==0)data.mese[1]=1;
		if(strcmp(mese2,"febbraio")==0)data.mese[1]=2;
		if(strcmp(mese2,"marzo")==0)data.mese[1]=3;
		if(strcmp(mese2,"aprile")==0)data.mese[1]=4;
		if(strcmp(mese2,"maggio")==0)data.mese[1]=5;
		if(strcmp(mese2,"giugno")==0)data.mese[1]=6;
		if(strcmp(mese2,"luglio")==0)data.mese[1]=7;
		if(strcmp(mese2,"agosto")==0)data.mese[1]=8;
		if(strcmp(mese2,"settembre")==0)data.mese[1]=9;
		if(strcmp(mese2,"ottobre")==0)data.mese[1]=10;
		if(strcmp(mese2,"novembre")==0)data.mese[1]=11;
		if(strcmp(mese2,"dicembre")==0)data.mese[1]=12;
	}
	a=data.mese[1];
	b=data.giorno[1];
	while(a==2&&(b<1 || b>28))
	{
		printf("reinserisci il giorno, giorno scorretto");
		scanf("%d",&b);
	}
	while((a==4||a==6||a==9||a==11)&&(b<1||b>30))
	{
		printf("reinserisci il giorno, giorno scorretto");
		scanf("%d",&b);
	}
	while((a==1||a==3||a==5||a==7||a==8||a==10||a==12)&&(b<1||b>31))
	{
		printf("reinserisci il giorno, giorno scorretto");
		scanf("%d",&b);
	}
	data.giorno[1]=b;
	if(data.anno[0]<data.anno[1])//controlli per stabilire la data precedente
	{
		printf("la data che viene prima e' il %d %s %d",data.giorno[0],mese,data.anno[0]);
	}
	else
	{
		if(data.anno[0]>data.anno[1])
		{
			printf("la data che viene prima e' il %d %s %d",data.giorno[1],mese2,data.anno[1]);
		}
		else
		{
			if(data.mese[0]<data.mese[1])
			{
				printf("la data che viene prima e' il %d %s %d",data.giorno[0],mese,data.anno[0]);
			}
			else
			{
				if(data.mese[0]>data.mese[1])
				{
					printf("la data che viene prima e' il %d %s %d",data.giorno[1],mese2,data.anno[1]);
				}
				else
				{
					if(data.giorno[0]<data.giorno[1])
					{
						printf("la data che viene prima e' il %d %s %d",data.giorno[0],mese,data.anno[0]);
					}
					else
					{
						printf("la data che viene prima e' il %d %s %d",data.giorno[1],mese2,data.anno[1]);
					}
				}
			}
		}
	}
	return 0;
}
