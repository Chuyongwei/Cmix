#include<stdio.h>
int main()
{
	int i=1000,j = 0;
	for(;i<=2100;i++)
	{
		if(i%100!=0&&i%4==0||i%400==0)
		printf("%5d",i);
		j++;
		if(j%15==0)
		printf("\n"); 
	}
} 
