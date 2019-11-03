#include<stdio.h>
int main()
{
	int fab(int m);
	float com1(int n,int m,int (*p)());
	int m=1,n,i = 1;
	long fac;//i和j是循环体 
	double sum = 0; //sum是最后求和 
	scanf("%d",&n);
	double com;//com组合
	for(i = 1;m<=n;m++)
	{
		sum = sum+com1(n,m,fab);
	}
	printf("%f",sum);
}
int fab(int m)//阶乘 
{
	int i=1,fac;
	for(fac = 1;i<=m;i++)
	{
	   fac = fac*i;
    }
    return fac
}
float com1(int n,int m,int (*p)(int))
{
	int com
	com = (*p)(n)/(*p)(m)/(*p)(m-n);
	return (com);
}
