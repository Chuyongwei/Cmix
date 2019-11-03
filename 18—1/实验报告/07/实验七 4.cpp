#include<stdio.h>
int main()
{
	void fun(int (*p)[10],int n);
	int a[10][10]={};
	fun(a,10);
	return 0;
}
void fun(int (*p)[10],int n)
{
	int a = 1,i,j;
	for(i=0;i<n;i++)
	{
	*(*(p+i)+0)=1;
	*(*(p+i)+i)=1;
	}
	for(i=0;i<n;i++)
	  for(j=1;j<i;j++)
	    p[i][j] = p[i-1][j-1]+p[i-1][j];
    for(i=0;i<n;i++)
     {
      for(j=0;j<=i;j++)
        printf("%5d",p[i][j]);
      printf("\n");
	  }   
}
