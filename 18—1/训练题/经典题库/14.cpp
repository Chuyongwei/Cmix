#include<stdio.h>
int main()
{
	int i,a,b,c;
	for(i=100;i<999;i++)
	{
		a = i%10;
		b = (i%100-i%10)/10;
		c = i/100;
		if(i==a*a*a+b*b*b+c*c*c)
		printf("%5d",i);
	}
	return 0;
}
