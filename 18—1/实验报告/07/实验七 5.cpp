#include<stdio.h>
int main()
{
   void dele(int *p,int n);
   int a[10]={1,2,3,4,5,6,7,8,9,10};	
   dele(a,5);
   for(int i=0;i<9;i++)
   printf("%5d",a[i]);
   return 0; 
} 
void dele(int *p,int n)
{
	for(int i=n;i<10;i++)
	{
		*(p+i-1)=*(p+i);
	} 
} 
