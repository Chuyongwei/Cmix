#include<stdio.h>
int fun(int g,int h)
{
	return g+h;
}
int main()
{
	int a = 5,b =2,c = 3,d = 4,e = 5;
	printf("%d\n",fun((a+b,c+a,b+c),(d+e)));
}
