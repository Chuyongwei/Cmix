#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*1.���������10���⣬ÿ��10�֣��������ʱ��ʾѧ���÷֣�
2.ȷ����ʽû�г���1~2�꼶��ˮƽ��ֻ�������50���ڵļӼ���������������֮�ͻ�֮���0~50�ķ�Χ���������ǲ�����ģ�
3.ÿ����ѧ�������λ�������𰸣���ѧ����������ʱ������ѧ���������룬������λ�������������ȷ�𰸣�
4.����ÿ���⣬ѧ����һ��������ȷ�𰸵�10�֣��ڶ���������ȷ�𰸵�7�֣�������������ȷ�𰸵�5�֣����򲻵÷֣�
5.�ܳɼ�90������ʾ��SMART��,80-90��ʾ��GOOD����70-80��ʾ��OK��,60-70��ʾ��PASS����60���¡�TRY AGAIN��
6.������ѧ���ɼ���������
7.��ѯѧ���Ĳ��Գɼ�
8.��ѧ���ɼ����зֶ�ͳ��
*/
typedef struct scare {
	int score;
	char m[10];
}scare;

int main()
{
	int i, n, s=0, a, b, c,c1,sum=0,mun;
	scare stu[10];
	printf("�����м�λͯЬ");
	scanf_s("%d", &mun);
	printf("���Կ�ʼ!\n���λͬѧ��10���ӷ���\nע�⣺�ûس���ʾ������������\n");
	for (; s < mun; s++)//��
	{
		printf("���%dλͬѧ�볡!\n",s+1);
		sum = 0;
		for (i = 0; i < 10; i++)//ti
		{
			c1 = 100;
			while (c1 > 50)
			{
				b = rand() % 50;
				a = rand() % 50;
				c1 = a + b;
			}
			printf("%d\t%d+%d=", i + 1, a, b);
			n = 0;
			c = 100;
			while (c!=c1&&n < 3)
			{
				scanf_s("%d",&c);
				getchar();
				n++;
			}
			switch (n)
			{
			case 0:sum += 10; break;
			case 1:sum += 7; break;
			case 2:sum += 5; break;
			default:
				break;
			}
		}
		if (sum > 90)
			strcpy_s(stu[s].m, "SMART");
		else if(sum>80)
			strcpy_s(stu[s].m, "GOOD");
		else if(sum>70)
			strcpy_s(stu[s].m, "OK");
		else if(sum>60)
			strcpy_s(stu[s].m, "PASS");
		else strcpy_s(stu[s].m, "TRY AGAIN");
	}
	printf("������λ�ɼ���");
	for (s = 0; s < mun; s++)
	{
		printf("��%dλ\t",s+1);
		puts(stu[s].m);
		printf("\n");
	}
	system("pause");
	return 0;
}