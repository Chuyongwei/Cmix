#include<stdio.h>
int main()
{
    void partition(unsigned long c);
    unsigned long s;
    scanf("%x",&s);
    partition(s);
    return 0;
}
void partition(unsigned long c)
{
     unsigned short a,b;
     a = c/0x100;
     b = c%0x100;
     printf("%x",a);
     printf("%5x",b);
}
