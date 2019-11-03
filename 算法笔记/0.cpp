#include<stdio.h>
int main()
{
	char s[100];
	int v;
	int i = 0;

	while(1)
	{
		s[i]  = getchar();//逐个输入字符并赋值到字符串中。
		if(s[i] == ',')//输入结束。
		{
			s[i] = '\0';//赋值结束符。
			break;//退出循环。
		}
		i ++;
	}
	scanf("%d",&v);//继续输入数字。
	printf("%s\n%d\n", s, v);//输出得到的变量，每行一个值。

	return 0;
}
