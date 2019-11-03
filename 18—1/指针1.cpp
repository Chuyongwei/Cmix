#include<stdio.h>
void Fun(int *par);
int main()
{
	int age = 1;
	printf("%d\n",age);
	Fun(&age);
	printf("%d\n",age);
	while(1);
	return 0;
	
}
void Fun(int *par)
{
	printf("%d\n",*par);
	*par = 2;
}

