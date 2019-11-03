/*补充函数编程题,程序功能要求：已知一个元素均为三位数的数组，
      包括正整数和负整数，在程序中调用函数output_s把所有数组元素
      顺序输出，调用函数reverse_s将数组中所有元素反序存放并输出，
      最后调用函数calculate_s输出数组元素中个位数是3的元素。请将
      函数补充完整。*/
#include<stdio.h>
#include<string.h>
void output_s(int a[],int j);
void reverse_s(int a[],int j);
void calculate_s(int a[],int j);
main()
{ 
	int b[10]={387,234,432,432,34,232,454,322,432,372},l;
	l = 10;
	printf("/n正序排序/n")
	output_s(b,l);
	printf("/n逆向排序/n")
	reverse_s(b,l);
	printf("/n个位数是三点的数/n")
	calculate_s(b[10],l);
	return 0;
} 
void output_s(int a[],int j)
{
	for(int i=0;i<j;i++)
	printf("%d",a[i]);
}
void reverse_s(int a[],int j)
{
	for(int i=j-1;i>=0;i++)
	printf("%d",a[i]);
}
void calculate_s(int a[],int j)
{
	for(int i=0;i<j;i++)
	{
		if(a[i]>0)
		c = a[i]-a[i]/10*10;
		else
		c = a[i]/10*10-a[i];
		if(c=3)
		printf("%d",a[i]);
	}
}
