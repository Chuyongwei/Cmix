#include<stdio.h>
int main()
{
	int a[6],i,j,t;
	for(i=0;i<6;i++)
	scanf("%d",&a[i]);
	for(i=0;i<6;i++)
	{
		for(j=0;j<6-i-1;j++)
		if(a[j]<a[j+1])
		{
			t = a[j];
			a[j] = a[j+1];
			a[j+1] = t;
		}
	}
	for(i=0;i<6;i++)
	printf("%5d",a[i]);
	return 0;
} 
