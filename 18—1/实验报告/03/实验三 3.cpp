#include<stdio.h>
int main()
{
	long int i,b,sum,a=1,ture;
	for(i=0;i<30;i++)
	{
	 a=a*2;
    }
    printf("һ������%ld",a);
    printf("\n");
    b=1;
    sum=a/2;
    for(i=0;b<sum;i++)
    {
		b=b*2;
    }
    printf("����һ�뻨%d��",i-1);
    return 0;
    
}
