#include<stdio.h>
int main()
{
	int i,a=2,b=1;
	float sum = 0; 
	for(i=1;i<10;i++)
	{sum=sum+a/b;
	a=a+i;
	b=b*2;
	printf("%d/%d\n",a,b);}
	printf("ÇóºÍ%f",sum);
	return 0;
}
