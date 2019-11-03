#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*1.电脑随机出10道题，每题10分，程序结束时显示学生得分；
2.确保算式没有超出1~2年级的水平，只允许进行50以内的加减法，不允许两数之和或之差超出0~50的范围，负数更是不允许的；
3.每道题学生有三次机会输入答案，当学生输入错误答案时，提醒学生重新输入，如果三次机会结束则输出正确答案；
4.对于每道题，学生第一次输入正确答案得10分，第二次输入正确答案得7分，第三次输入正确答案得5分，否则不得分；
5.总成绩90以上显示“SMART”,80-90显示“GOOD”，70-80显示“OK”,60-70显示“PASS”，60以下“TRY AGAIN”
6.对所有学生成绩进行排序
7.查询学生的测试成绩
8.对学生成绩进行分段统计
*/
typedef struct scare {
	int score;
	char m[10];
}scare;

int main()
{
	int i, n, s=0, a, b, c,c1,sum=0,mun;
	scare stu[10];
	printf("输入有几位童鞋");
	scanf_s("%d", &mun);
	printf("考试开始!\n请各位同学做10道加法题\n注意：用回车表示本题答题题结束\n");
	for (; s < mun; s++)//人
	{
		printf("请第%d位同学入场!\n",s+1);
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
	printf("公布各位成绩：");
	for (s = 0; s < mun; s++)
	{
		printf("第%d位\t",s+1);
		puts(stu[s].m);
		printf("\n");
	}
	system("pause");
	return 0;
}