#include<stdio.h>
int main()
{
	char s[100];
	int v;
	int i = 0;

	while(1)
	{
		s[i]  = getchar();//��������ַ�����ֵ���ַ����С�
		if(s[i] == ',')//���������
		{
			s[i] = '\0';//��ֵ��������
			break;//�˳�ѭ����
		}
		i ++;
	}
	scanf("%d",&v);//�����������֡�
	printf("%s\n%d\n", s, v);//����õ��ı�����ÿ��һ��ֵ��

	return 0;
}
