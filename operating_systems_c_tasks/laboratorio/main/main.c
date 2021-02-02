#include<stdio.h>
#include<stdlib.h>
#include "quadrato.h"
#include "dimezza.h"
static double salva;
int main()
{
	salva=quadrato(dimezza(13.17));
	printf("salva=%f\n",salva);
return 0;
}