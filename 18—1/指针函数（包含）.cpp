#include<stdio.h>
int main()
{
	int max(int a,int b);
	int min(int a,int b);
	int sum(int,int);
    void fun(int x,int y, int (*p)(int,int));
	int a,b,t;
	int (*p)(int,int);
	scanf("%d,%d",&a,&b);
	scanf("%d",&t);
	if(t==1) fun(a,b,max);
	else if(t==2) fun(a,b,min);
	else if(t==3) fun(a,b,sum);
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
int sum(int a,int b)
{
	int f;
	f = a+b;
	return (f);
}
void fun(int a,int b,int(*p)(int,int))
{
	int l;
	l = (*p)(a,b); 
	printf("%d",l);
}
