#include<stdio.h>
int main()
{
	int a[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16},*p1,j,i,t,b[4];
		p1 = &a[0][0];
    for(i=0;i<4;i++)          		          
	{
		for(j=0;j<4;j++) 
	          printf("%5d",*(p1+i*4+j));
	    printf("\n");
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			t=*(p1+i*4+j);
		    if(*(p1+i*4+j)>*(p1+i*4+j+1))
		    {
			     t=*(p1+i*4+j);
		    }
		}
		b[i]=t;
	}
	p1=b;
	for(i=0;i<4;i++,p1++)
	printf("%d",*p1);
}
