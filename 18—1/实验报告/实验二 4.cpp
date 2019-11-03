#include<stdio.h>
int main()
{
	int a,i,j,m;
	int t[5];
	scanf("%d",&t[5]);
	for(j=1;j<4;j++)
	{
	for(i=4;i<j;i++)
	{
		if(t[i-1]>=t[i])
		{
			m=t[i];
			t[i]=t[i-1];
			t[i-1]=m; 
		
		}
			printf("%d",t[i-1]);	
	}
} 
          return 0;
}
