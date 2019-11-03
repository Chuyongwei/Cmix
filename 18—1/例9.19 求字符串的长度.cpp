#include<stdio.h>
int main()
{
	int slen(char []);
	char s[100];
	int len;
	
	gets(s);
	len=slen(s);
	printf("%d\n",len);
	
} 

int slen(char c[])
{
	int i = 0;
	
	while(c[i] != '\0')
	 i++;
	return i;
}

