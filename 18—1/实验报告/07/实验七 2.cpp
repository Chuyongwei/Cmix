#include<stdio.h>
int main()
{
	int a[10],*p,i,j,t;
	for(i=0;i<10;i++)
	scanf("%d",a[i]);
	for(i=0;i<10;i++)
	{
		for(j=0;j<10-i;j++)
		{
		if(a[j]>a[j+1])
		{
			t=a[j];
		a[j]=a[j+1];
		a[j+1]=t;	
		}
		}
	}
	p=a;
	for(i=0;i<10;p++,i++)
	printf("%d",*p);
	while (1);
    	return 0;
} 
