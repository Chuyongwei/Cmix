#include<stdio.h>
#include<string.h>
void output_s(int *a,int j);
void reverse_s(int *a,int j);
void calculate_s(int *a,int j);
main()
{ 
	int b[10]={387,234,432,432,34,232,454,322,432,372},l;
	l = 10;
	printf("/n正序排序/n"); 
	output_s(b,10);
	printf("/n逆向排序/n");
	reverse_s(b,l);
	printf("/n个位数是三点的数/n");
	calculate_s(b,l);
	return 0;
} 
void output_s(int *a,int j)
{
	for(int i=0;i<j;i++,a++)
	printf("%5d\n",*a);
}
void reverse_s(int *a,int j)
{
	int t;
	for(int i=0;i<j/2;i++)
	{
	t = a[i];
	a[i] = a[j-1-i];
    a[j-i-i] = t;
	}
	for(int i=0;i<j;i++,a++)
	printf("%5d\n",*a);
}
void calculate_s(int *a,int j)
{
	int t;
	for(int i=0;i<j;i++,a++)
	{
		t = a[i]%10;
		if(t==3)
		printf("%5d\n",*a);
	}
}
