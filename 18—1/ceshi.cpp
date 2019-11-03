#include<stdio.h>
int main()
{
	int i,a,j;
	scanf("%d",&a);
	i = 1;
	while(i<=a)
	{
		j = 0;
		while(j<=i)
		{
			printf("%d",a);
			j = j+1; 
		}
		printf("\n");
	}
	return 0;
} 
