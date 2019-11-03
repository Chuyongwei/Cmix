#include<stdio.h>
int main()
{
	void input(int (*p)[3],int n);
	void output(int (*p)[3],int n);
	int b[3][3];
	int (*p)[3];
	p = b;
	int j;
	for(j=0;j<3;j++)
	{
		input(p,j);
	}
	for(j=0;j<3;j++)
	{
		output(b,j);
		printf("\n");
	}
	return 0; 
}
void input(int (*a)[3],int n)
{
	int i = 0,j;
	for(;i<3;i++)
	    scanf("%d",a[n]+i);
}
void output(int (*a)[3],int n)
{
	int i;
	for(i = 0;i<3;i++) 
	printf("%5d",*(a[n]+i));
}
