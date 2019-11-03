#include<stdio.h>
int main()
{
	int x,y,z,m,n;
	scanf("%d%d",&x,&y);
	m=x;
	n=y;
	while(y!=0)
	{
		z=x%y;
		x=y;
		y=z;
	}
	printf("%d",x);
	printf("%10d",m*n/x);
	return 0;
}
