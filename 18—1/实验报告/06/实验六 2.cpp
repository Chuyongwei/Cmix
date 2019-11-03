#include<stdio.h>
int main()
{
	int gas(int a,int b);
	int a,b,c,d;
	scanf("%d%d",&a,&b);
	c = gas(a,b);
	d = a*b/c;
	printf("%5d%5d",c,d);
	
}
int gas(int a,int b)
{
	
    int c = a,t = b;
	if(a<b)
	c = b,b=a,a=c;
	do
	{
		t = a%b;
		a = b;
		b = t; 
	}
	while(t!=0);
	return(a);
}
