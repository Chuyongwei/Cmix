#include<stdio.h>
int main()
{
	int a[6] = {1,2,3,4,5,6};
	int p,i;
	scanf("%d",&p);
	for(i=p-1;i<5;i++)
	{
		a[i] = a[i+1];
	}
	a[i] = 0;
	for(i=0;i<5;i++)
	printf("%d",a[i]);
	return 0;
}
