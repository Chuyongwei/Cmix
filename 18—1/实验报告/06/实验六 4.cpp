#include<stdio.h>
#include<stdio.h>
int main()
{
	int fac(int,int);
	int m;
	scanf("%d",&m);
	printf("%d",fac(m,0));	 
} 
int fac(int n,int sum)
{
	int i = 1,sum1 = 1;
	for( ;i<=n;i++)
	{
		sum1 = i*sum1;
	}
	sum = sum+sum1;
	if(n<=0)
	return (sum);
	else fac(n-1,sum);
}
