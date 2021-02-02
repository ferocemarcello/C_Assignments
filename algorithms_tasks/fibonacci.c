#include<stdio.h>
#include<stdlib.h>
int fibonacci1(int n)//2^n
{
	if(n<=2)return 1;
	else return(fibonacci1(n-2)+fibonacci1(n-1));
}
int fibonacci2(int n)//lineare
{
	int a=0;int b=0; int c=0;int i=0;
	a=b=1;
	for(i=3; i<=n;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	return b;
}
int main(int argc, char*argv[0])
{
	int dato=0;
	scanf("%d",&dato);
	system("pause");
	printf("numero della serie di fibonacci iterativo=%d\n",fibonacci2(dato));
	system("pause");
	printf("numero della serie di fibonacci ricorsivo=%d",fibonacci1(dato));
	return 0;
}
