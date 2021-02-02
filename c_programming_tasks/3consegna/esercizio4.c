//marcello feroce primo anno ingegneria e scienze informatiche matricola numero 0000730777
#include<stdio.h>
#include<stdlib.h>
int main()
{
	float stip_lordo,ali,stip_netto_mensile;
	printf("Digita il valore dello stipendio lordo(in euro)");
	scanf("%f",&stip_lordo);
	while(stip_lordo<0)
	{
		printf("il numero digitato deve essere non negativo\n");//controllo affinchè il valore dello stipendio lordo sia corretto
		printf("digita un altro valore dello stipendio lordo");scanf("%f",&stip_lordo);
	}
	if(stip_lordo<=10000)
	{
			ali=0.0;
	}
	if(stip_lordo>10000 && stip_lordo<=30000)
	{
		ali=0.2;
	}
	if(stip_lordo>30000)
	{
		stip_lordo=stip_lordo-10000;
		if(stip_lordo>30000)
		{
			ali=0.3;
		}
		else
		{
			ali=0.2;
		}
	}
	stip_netto_mensile=(stip_lordo-((stip_lordo-10000)*ali))/12;
	printf("\nlo stipendio netto mensile e' di %g euro",stip_netto_mensile);
	return 0;
}
