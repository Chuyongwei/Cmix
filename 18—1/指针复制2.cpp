#include<stdio.h>
int main()
{
	char a[] = {"I love Beijing!"},b[] = {"I love China!"},*b1,*b2;
	b1 = a,b2 = b;
	for( ;*b1!='\0';b1++,b2++)
	*b1 = *b2;
	*b1 = '\0' ;
	printf("%s\n",a);
	printf("%s",b);
	return 0;
} 
