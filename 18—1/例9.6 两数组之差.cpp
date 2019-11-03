#include<stdio.h>
int main()
{
	int a[10]={ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	int *p;
	
	for(p=a; p<a+10; p++)
	printf("%5d", *p);
} 
