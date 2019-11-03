/*将字符数组a初始化为"interesting"，键盘输入1个字符串赋给字符数组
      b（数组b的大小为30）；比较这两个字符串，如果a中字符串大于b中字符
      串，则将a中的字符串连接到字符串b后面，如果a中字符串小于b中字符串，
      则将a中的字符串复制给字符数组b；计算字符串b的长度存于整型变量n中
      并输出。*/
#include<stdio.h>
#include<string.h> 
int main()
{
	int n;
	char a[]="insteresting",b[30];
	gets(b);
	if(strcmp(a,b)>0)
	{strcat(b,a);}
	else
	{strcpy(b,a);}
	n = strlen(b);
	printf("n=%d\n",n);
	puts(a);
	printf("%s\n",b); 
	return 0;
}      
