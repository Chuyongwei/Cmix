/*��д���򣬴Ӽ�������2�����Ȳ��ȵ��ַ����ֱ�����ַ�����
      s��t�У������СΪ50�����Ƚ������ַ����Ĵ�С���Ƚ���С��
      �ַ������Ƶ�һ���µ��ַ�����m�У���СΪ50����Ȼ������
      �ַ���"XYZ"���Ӻ������*/
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
