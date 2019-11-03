#include<stdio.h>
int main()
{
	int a,i,j,n;
	scanf("%d",&a);
	n = 1;
	i=0;
	while(i<=a)
	{
		j = 0;
		while(j<=i)
		{
			printf("%5d",n);
			j++;
			n++;
		}
		printf("\n");
		i++;
	}
}
