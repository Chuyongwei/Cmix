#include<stdio.h>
int main()
{
	void sawp(char p[]);
	char a[20];
	gets(a);
	sawp(a);
	puts(a);
}
void sawp(char p[])
{
	int i;
	for(i = 0;p[i]!='\0';i++)
	{
		if(p[i]>='a'&&p[i]<='z')
		{
			p[i] = p[i]-32;
		}
	} 
}
