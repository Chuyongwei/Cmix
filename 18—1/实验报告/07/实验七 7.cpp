#include<stdio.h>

int main()
{
	void cord(char *p);
	char a[128];
	gets(a);
	cord(a);
	return 0;
} 
void cord(char *p)
{
	int l[10],i;
	int j=0;
	for(char m='0';j<=9;j++)
	{
     l[j]=0;
	 for(i=0;i<128;i++)
	 if(*(p+i)==m)
	 l[j]=l[j]+1;
	 printf("a[%d] = %d",j,l[j]);
	 m = m+1;
	 printf("\n");
	 }
	 
}
