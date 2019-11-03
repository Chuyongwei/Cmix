#include<stdio.h>
int main()
{
	int a = 2,*pa1, *pa2;
	float b = 2.3,*pb1;
	
	pa1 = &a;pa2 = pa1;
	pb1 = &b;
	printf("%x,%x,%x\n", &a, pa1, pa2);
	printf("%d,%d,%d\n", a, *pa1, *pa2);
	printf("%x,%x\n", &b, pb1);
	printf("%f,%f\n", b, *pb1);
} 
