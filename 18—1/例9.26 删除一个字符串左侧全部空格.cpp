#include<stdio.h>
int main()
{
	char a[100],*q;
	char *ltrim(char *);
	
	gets(a);
	q = ltrim(a);
	printf("%s\n", q);
} 
char *ltrim(char *p)
{
	static char str[100];
	int i;
	
	while(*p==' ')
	{
		p++;
	}
	i = 0;
	while(*p!='\0')
	{
		str[i]=*p;
		p++;
		i++;
	}
	str[i] != '\0';
	return(str); 
}
