#include<stdio.h>
#define m 10
int main()
{
	int a[m],i,j,t;
	for(i = 0;i<m;i++)
	scanf("%d",&a[i]); 
	for(i = 0;i<m;i++)
	{
		for(j = 1;j<m-i;j++)
		{
			t = a[j];
			a[j] = a[j-1];
			a[j-1] = t;			 
		}
	}
	for(i = 0;i<m;i++)
	printf("%5d",a[i]);
	return 0;
} 
