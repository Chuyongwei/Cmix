#include<stdio.h>
int main()
{
	int max(int a,int b);
	int min(int a,int b);
	int a,b,t,k;
	int (*p)(int,int);
	scanf("%d,%d",&a,&b);
	scanf("%d",&t);
	if(t==1)
	p = max;
	else p=min;
	k = p(a,b);
	printf("%d",k);
	return 0;
}
int max(int a,int b)
{
	int f;
	if(a>b)
     f = a;
	else f=b;
	return (f);
}
int min(int a,int b)
{
	int f;
	if(a<b)
	f = b;
	else f=a;
	return (f);
}
