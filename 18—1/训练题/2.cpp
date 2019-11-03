/*编写程序，从键盘输入2个长度不等的字符串分别存入字符数组
      s和t中（数组大小为50），比较两个字符串的大小，先将较小的
      字符串复制到一个新的字符数组m中（大小为50），然后将其与
      字符串"XYZ"连接后输出。*/
#include<stdio.h>
#include<string.h>
int main()
{
	char s[50],t[50],m[50];
	gets(s);
	gets(t);
	if(strcmp(s,t)>0)
	{strcpy(m,t);}
	else
	{strcpy(m,s);}
	strcat(m,"XYZ");
	puts(m);
	return 0;
} 
