#include<stdio.h>
int main()
{
	int fac(int n);
	int xgm(int n,int(*p)(int));
	int m;
	scanf("%d",&m);
	printf("%d",xgm(m,fac));	 
} 
int fac(int n)
{
	int i = 1,sum = 1;
	for( ;i<=n;i++)
	{
		sum = i*sum;
	}
	return (sum);
}
int xgm(int n,int(*p)(int))
{
	int i = 1,sum = 0;
	for(;i<=n;i++)
	{
		sum = sum+(*p)(i);
	}
	return (sum);
}
