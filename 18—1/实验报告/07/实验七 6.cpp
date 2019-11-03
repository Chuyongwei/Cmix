#include<stdio.h>
int main()
{
	int swit2(int a);
	int s= 123456;
	swit2(s);
	return 0;
} 
void swit2(int a)
{
	int i=0,t=a;
	char p[20]; 
	for(i=0;t!=0;i++)
	{
		t=t/2;
		p[i] = t%2+'0';
	}
	for(i=20;i>=0;i--)
	printf("%c",p[i]);
}
