#include<stdio.h>
int main()
{
	int m=1,n,i = 1;
	long fac;//i��j��ѭ���� 
	double sum = 0; //sum�������� 
	scanf("%d",&n);
	double com;//com��� 
	for(i = 1;m<=n;m++)
	{
	    for(fac = 1;i<=m;i++)
		    fac = fac*i;
		com = fac;
	    for(fac = 1,i = 1;i<=n;i++)
	        fac = fac*i;
	    com = fac/com;
	    for(fac = 1,i = 1;i<=(m-n);i++)
	        fac = fac*i;
	    com = com/fac;
	    sum = com+sum;
    }
    printf("%lf",sum);
    return 0;
}
