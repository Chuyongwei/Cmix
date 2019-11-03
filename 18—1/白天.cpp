#include<stdio.h>
int main()
{
	int a,b,c,i;
	int m[]={31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d%d",&a,&b);
	printf("\n");
	int j = b;
	for(i=a-1;j!=0;i++)
	{
		j = 100-m[i]-j;
		if(i>11)
		i = -1;
		if(j<m[i+1])
		break;
	} 
	printf("%5d%5d",i+1,j);
	return 0;
	
}
