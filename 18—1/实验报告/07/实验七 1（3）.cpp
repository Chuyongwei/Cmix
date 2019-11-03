#include <stdio.h>
int main()
{
	int a[3][4]={2,4,6,8,10,12,14,16,18,20,22,24};
	printf("%d,%d\n",a,*a); //输出a[0]的地址 
	printf("%d,%d\n",a[0],*(a+0)); 
	printf("%d,%d\n",&a[0],&a[0][0]); 
	printf("%d,%d\n",a[1],a+1); //输出a[1]的地址 
	printf("%d,%d\n",&a[1][0],*(a+1)+0); 
	printf("%d,%d\n",a[2],*(a+2));
	printf("%d,%d\n",&a[2],a+2); 
	printf("%d,%d\n",a[1][0],*(*(a+1)+0));
	printf("%d,%d\n",*a[2],*(*(a+2)+0)); 
	return 0;
}

