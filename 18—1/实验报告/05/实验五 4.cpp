#include<stdio.h>
int main()
{
	int a[6] = {1,2,3,4,5};
	int t,b,i;
	scanf("%d",&b);
	for(i = 5;i>0;i--)
	{
		a[i] = a[i-1];
	} 
	a[i] = b;
	for(i = 0;i<6;i++)
	{ 
	     printf("%d",a[i]);
	}
	return 0;
}
