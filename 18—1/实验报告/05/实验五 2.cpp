#include<stdio.h>
#include<math.h>
int main()
{
	int det(int (*a)[3]);
	int b[3][3]={1,2,3,4,5,6,7,8,9};
	
	printf("%d",det(b));
}
int det(int (*a)[3])
{
	int i,j,t,t1;
	int mult,sum=0;
	for(t=0,i=0;t<3;t++)
	{
		i = 0;
		mult = 1;
		for(j=t,t1=0;t1<3;t1++,j++,i++)
		{
			if(i>2)i=0;
			if(j>2)j=0;
			mult=a[i][j]*mult;
        }
        sum = mult+sum;
	}
	for(t=0,i=0;t<3;i++,t++)
	{
		i = 0;
		mult =  1;
		for(j=2-t,t1=0;t1<3;t1++,i++,j--)
		{
			if(i>2)i=0;
			if(j<0)j=2;
			mult=a[i][j]*mult;
		}
		sum = sum-mult;
	}
	return (sum);
}
