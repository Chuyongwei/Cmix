#include<stdio.h>
#include<string.h>
int main()
{
	void reverse(char *,int);
	char a[20];
	gets(a);
	reverse(a,strlen(a));
	puts(a);
}
void reverse(char *a,int n)
{
	int i;
	char t;
	for(i = 0;i<n/2;i++)
	{
		t = *(a+i);
		*(a+i) = *(a+n-i-1);
		*(a+n-i-1) = t;
	}
}
