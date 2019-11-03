#include<stdio.h>
int main()
{
	char a[]="I love beijing!",b[20],*pa,*pb;
	pa = a;pb = b;
    for( ;*pa!='\0';pa++,pb++)
    *pb = *pa;
    *pb = '\0';
    printf("%s\n",a);
    printf("%s",b);
    return 0;
}
