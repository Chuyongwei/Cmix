#include<stdio.h>
int main()
{
    int sum=0,l=3,i;
    for(i=0;i<5;i++)
    {
      sum=l+sum;
      l=l*10+3;
      }
      printf("%d",sum);
      while (1);
      return 0;
      
}
