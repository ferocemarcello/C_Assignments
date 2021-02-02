#include<stdio.h>
#include<stdlib.h>
#include<math.h>

static double salva;

double dimezza(double angle)
{
	double x=cos(angle);
	x=x/2;
	salva=x;
	return x;
}