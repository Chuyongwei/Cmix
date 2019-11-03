#include <stdio.h>
int main()
{  
int a[10];  int *p, i;
    printf("Enter 10 integer numbers:\n");
    for(i=0;i<10;i++) 
	   scanf("%d",&a[i]);
    for(i=0;i<10;i++) 
	   printf("%d ",a[i]); 
    printf("%\n");
    for(i=0;i<10;i++)
       printf("%d ",*(a+i));   //数组输入方式之一：*（a+i），因为a本身 就是地址 
    printf("\n");
    for(p=a;p<(a+10);p++)  //定义指针p指向a的第一个元素 
       printf("%d ",*p); 
    printf("\n");  
    return 0;
 }

