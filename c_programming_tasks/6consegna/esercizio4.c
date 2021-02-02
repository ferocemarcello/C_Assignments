#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct sdata
{
	int giorno[2];
	char mese[2][10];
	int anno[2];
	
}data;

int main()
{
	int a=0;
	int b=0;
	int contmese1=0;
	int contmese2=0;
	int ord[12]={1,2,3,4,5,6,7,8,9,10,11,12};
	int nummes1=0;
	int nummes2=0;
	char mesi[12][10]={"gennaio","febbraio","marzo","aprile","maggio","giugno","luglio","agosto","settembre","ottobre","novembre","dicembre"};
	printf("Data 1:\nimmetti la data secondo il formato giorno/mese/anno\n");
	scanf("%d/%s/%d",&data.giorno[0],&data.mese[0],&data.anno[0]);
	printf("%d/%s/%d",data.giorno[0],data.mese[0],data.anno[0]);
	for(a=0;a<12;a++)
	{
		mesi[a][strlen(mesi[a])-1]='\0';
	}
	for(a=0;a<2;a++)
	{
		data.mese[a][strlen(data.mese[a])-1]='\0';
	}
	if(strcmp(data.mese[0],"gennaio")==0){printf("e' gennaio");	}
	while(strcmp(data.mese[0],"gennaio")==1 && strcmp(data.mese[0],"febbraio")==1 && strcmp(data.mese[0],"marzo")==1 && strcmp(data.mese[0],"aprile")==1 && strcmp(data.mese[0],"maggio")==1 && strcmp(data.mese[0],"giugno")==1 && strcmp(data.mese[0],"luglio")==1 && strcmp(data.mese[0],"agosto")==1 && strcmp(data.mese[0],"settembre")==1 && strcmp(data.mese[0],"ottobre")==1 && strcmp(data.mese[0],"novembre")==1 && strcmp(data.mese[0],"dicembre")==1)
	{
		printf("mese non corretto, riscrivilo");
		scanf("%s",data.mese[0]);
	}
	while(data.mese[0]=="febbraio"&& (data.giorno[0]>28 ||data.giorno[0]<1))
	{
			printf("giorno del mese non disponibile, riscrivilo\n");
			scanf("%d",&data.giorno[0]);
	}
	while((data.mese[0]=="aprile"||data.mese[0]=="giugno"||data.mese[0]=="settembre"||data.mese[0]=="novembre")&& (data.giorno[0]>30 ||data.giorno[0]<1))
	{
			printf("giorno del mese non disponibile, riscrivilo\n");
			scanf("%d",&data.giorno[0]);
	}
	while((data.mese[0]=="gennaio"||data.mese[0]=="marzo"||data.mese[0]=="maggio"||data.mese[0]=="luglio"||data.mese[0]=="agosto"||data.mese[0]=="ottobre"||data.mese[0]=="dicembre")&& (data.giorno[0]>31 ||data.giorno[0]<1))
	{
			printf("giorno del mese non disponibile, riscrivilo\n");
			scanf("%d",&data.giorno[0]);
	}
	
	printf("Data 2:\nimmetti la data secondo il formato giorno/mese/anno\n");
	scanf("%d/%s/%d",&data.giorno[1],&data.mese[1],&data.anno[1]);
	b=0;
	for(a=0;a<12;a++)
	{
		if(strstr(mesi[a],data.mese[0])==NULL)
		{
			b++;
		}
	}
	while(b==12)
	{
		b=0;
		printf("mese non corretto, riscrivilo\n");
		scanf("%s",&data.mese[0]);
		for(a=0;a<12;a++)
		{
			if(strstr(mesi[a],data.mese[0])==NULL)
			{
				b++;
			}
		}
	}
	while(data.mese[1]=="febbraio"&& (data.giorno[1]>28 ||data.giorno[1]<1))
	{
			printf("giorno del mese non disponibile, riscrivilo\n");
			scanf("%d",&data.giorno[1]);
	}
	while((data.mese[1]=="aprile"||data.mese[1]=="giugno"||data.mese[1]=="settembre"||data.mese[1]=="novembre")&& (data.giorno[1]>30 ||data.giorno[1]<1))
	{
			printf("giorno del mese non disponibile, riscrivilo\n");
			scanf("%d",&data.giorno[1]);
	}
	while((data.mese[1]=="gennaio"||data.mese[1]=="marzo"||data.mese[1]=="maggio"||data.mese[1]=="luglio"||data.mese[1]=="agosto"||data.mese[1]=="ottobre"||data.mese[1]=="dicembre")&& (data.giorno[1]>31 ||data.giorno[1]<1))
	{
			printf("giorno del mese non disponibile, riscrivilo\n");
			scanf("%d",&data.giorno[1]);
	}
	if(data.anno[0]<data.anno[1])
	{
		printf("viene prima la data %d/%s/%d",data.giorno[0],data.mese[0],data.anno[0]);
	}
	if(data.anno[1]<data.anno[0])
	{
		printf("viene prima la data %d/%s/%d",data.giorno[1],data.mese[1],data.anno[1]);
	}
	contmese1=0;
	for(a=0;a<12;a++)
	{
		if(data.mese[0]!=mesi[a])
		{
			contmese1++;
		}
	}
	contmese2=0;
	for(a=0;a<12;a++)
	{
		if(data.mese[1]!=mesi[a])
		{
			contmese2++;
		}
	}
	if(data.anno[1]==data.anno[0])
	{
		if(contmese2<contmese1)
		{
			printf("viene prima la data %d/%s/%d",data.giorno[1],mesi[contmese2],data.anno[1]);
		}
	}
	if(data.anno[1]==data.anno[0])
	{
		if(contmese2>contmese1)
		{
			printf("viene prima la data %d/%s/%d",data.giorno[0],mesi[contmese1],data.anno[0]);
		}
	}
	if(data.anno[1]==data.anno[0])
	{
		if(contmese2==contmese1)
		{
			if(data.giorno[1]<data.giorno[0])
			{
				printf("viene prima la data %d/%s/%d",data.giorno[1],data.mese[0],data.anno[1]);
			}
			else
			{
				printf("viene prima la data %d/%s/%d",data.giorno[0],data.mese[0],data.anno[0]);
			}
		}
	}
	
	return 0;
}
