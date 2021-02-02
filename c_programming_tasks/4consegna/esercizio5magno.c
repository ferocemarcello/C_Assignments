




#include<stdio.h>
#include<stdlib.h>
//il numero massimo è 520650

int main()
{
	
	char test;
	float max;
	int p = 1;
	int rest;
	int var = 0;
	int pos;
	
	do{
			fflush(stdin);
			printf("\ninserisci un valore intero positivo:\n");
			scanf("%f", &max);
			test = getchar();
			if(test!='\n')																//controlla che sia stato inserito esclusivamente un numero
				printf("\nATTENZIONE: inserire solo un numero!\n\n");
			else{
				if(max<0)																//controlla che il numero inserito non sia negativo
					printf("\nATTENZIONE: il valore inserito e\' negativo!\n\n");
				if(max != (int)max)													//controlla che il numero inserito sia un intero
					printf("\nATTENZIONE: il valore inserito non e\' un intero!\n\n");
				if(max==0)															//controlla che il numero inserito non sia 0
					printf("\nATTENZIONE: il valore non puo\' essere 0\n\n");
			}
		}while(max<=0 || max != (int)max || test!='\n');							//ripete il ciclo se il numero inserito non è un numero positivo diverso da 0
		
	int primi[(int)max+1];
	primi[0]=2;
		
	for(; var<max-1; p++)
	{
		for(pos=0, rest=0; pos<=var; pos++)
		{
			rest = p%primi[pos];
			if(rest!=0)
				continue;
			else
				break;
			
		}
		
		if(p==1)
			printf("i primi %g numeri primi sono: ", max);
		
		if(rest!=0 && p!=1 || p==2)
		{
			if(p!=2){
				primi[pos] = p;
				var++;
			}
			printf("%d ", p);
			
		}
			
	}
	
	puts("\n");
	
	return 0;
}

