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
       printf("%d ",*(a+i));   //�������뷽ʽ֮һ��*��a+i������Ϊa���� ���ǵ�ַ 
    printf("\n");
    for(p=a;p<(a+10);p++)  //����ָ��pָ��a�ĵ�һ��Ԫ�� 
       printf("%d ",*p); 
    printf("\n");  
    return 0;
 }

