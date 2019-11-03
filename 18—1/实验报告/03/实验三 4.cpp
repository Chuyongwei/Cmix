#include<stdio.h>
int main()
{
	int A,B,C,i,SUM,a=1,b=1,c=1;
	scanf("%d%d%d",&A,&B,&C);
	for(i=1;i<A;i++)
	{
		a=a*(a+1);
	}
	for(i=1;i<B;i++)
	{
		b=b*(b+1);
	}
	for(i=1;i<C;i++)
	{
		c=c*(c+1);
	}
	SUM=a+b+c;
	printf("%d",SUM);
	return 0;

}
