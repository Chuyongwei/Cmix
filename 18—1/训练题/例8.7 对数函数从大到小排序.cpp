/*���ַ�����a��ʼ��Ϊ"interesting"����������1���ַ��������ַ�����
      b������b�Ĵ�СΪ30�����Ƚ��������ַ��������a���ַ�������b���ַ�
      ������a�е��ַ������ӵ��ַ���b���棬���a���ַ���С��b���ַ�����
      ��a�е��ַ������Ƹ��ַ�����b�������ַ���b�ĳ��ȴ������ͱ���n��
      �������*/
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
