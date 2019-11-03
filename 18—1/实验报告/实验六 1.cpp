#include<stdio.h>
int main()
{
	int c,b,divisor(int a,int b);
	printf("%d",divisor(49,56));
	c =divisor(49,56);
	b=49/c*56;
	return 0;
}
int divisor(int a,int b)
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
