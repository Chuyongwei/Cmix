#include<stdio.h>
int main()
{
	void cpye(char *,char *);
	char a[20],b[20];
	gets(a);
	cpye(b,a);
	puts(b);
	return 0;
} 
void cpye(char *pb,char *pa)
{
	int i = 0;
	char t;
	do
	{
	   pb[i]  = pa[i];
	   i++;
	}
	while(pa[i]!='\0');
	pb[i] = '\0';
}
