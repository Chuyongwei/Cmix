#include<stdio.h>
int main()
{
	void sawp(char a[],char b[]);
	char a[40] = {"jdhsk        88  "};
	char b[40] = {"ifshfhkhiofhi"};
	sawp(a,b);
	printf("%s\n",a);
	printf("%s",b);
	return 0;
} 
void sawp(char a[],char b[])
{
	char *b1,*b2;
	b1 = a,b2 = b;
	for(;*b1!='\0';b1++,b2++)
	*b1 = *b2;
}
