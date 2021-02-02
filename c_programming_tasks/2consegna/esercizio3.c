//Marcello Feroce primo anno ingegneria e scienze informatiche matricola 0000730777 esercizio3
#include<stdio.h>
#include<stdlib.h>
#include <math.h> 
int main()
{
	float D;/*dichiarazione di D*/
	float a;/*area del quadrato di lato D*/
	float b;/*area del cerchio di diametro D*/
	float c;/*area del triangolo equilatero di lato D*/
	printf("digita il valore di D\n");
	scanf("%f",&D);
	a=pow(D,2);
	b=((D/2)*(D/2))*M_PI ;
	c=((D*D)*sqrt(3))/4;
	printf("L'area del quadrato di lato D e' %f\n",a);
	printf("L'area del cerchio di diametro D e' %f\n",b);
	printf("L'area del triangolo equilatero di lato D e' %f",c);
	return 0;
}
