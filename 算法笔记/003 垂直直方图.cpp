/*描述
输入4行全部由大写字母组成的文本，输出一个垂直直方图，给出每个字符出现的次数。
注意：只用输出字符的出现次数，不用输出空白字符，数字或者标点符号的输出次数。

输入
输入包括4行由大写字母组成的文本，每行上字符的数目不超过80个。

输出
输出包括若干行。其中最后一行给出26个大写英文字母，这些字母之间用一个空格隔开。
前面的几行包括空格和星号，每个字母出现几次，就在这个字母的上方输出一个星号。
注意：输出的第一行不能是空行。

样例输入

THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.
THIS IS AN EXAMPLE TO TEST FOR YOUR
HISTOGRAM PROGRAM.
HELLO!

样例输出

                            *
                            *
        *                   *
        *                   *     *   *
        *                   *     *   *
*       *     *             *     *   *
*       *     * *     * *   *     * * *
*       *   * * *     * *   * *   * * * *
*     * * * * * *     * * * * *   * * * *     * *
* * * * * * * * * * * * * * * * * * * * * * * * * *
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z*/
#include <stdio.h>

int main()
{
	int cNum[26];	//初始化为0
	char str[1000];
	int maxLine = -1;
	int i;
	//初始化数组
	for (i = 0; i<26; i++)
	{
		cNum[i] = 0;
	}
	//输入四行大写字母,并统计字符
	for (i = 0; i<4; i++)
	{
		gets(str);	//输入一行，包括空格
		int j = 0;
		while (str[j] != '\0')
		{
			if (str[j] >= 'A'&&str[j] <= 'Z')
			{
				int k = str[j] - 'A';
				cNum[k]++;	//字母对应位置加一
							//记录最大行数
				if (cNum[k]>maxLine)
				{
					maxLine = cNum[k];
				}
			}
			j++;
		}
	}
	//输出,用直方图显示
	int line;
	for (line = maxLine; line>0; line--)
	{
		for (i = 0; i<26; i++)
		{
			if (cNum[i] >= line)
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}

	//最后一行输出字母
	for (i = 0; i<26; i++)
	{
		printf("%c ", char(i + 'A'));
	}
	printf("\n");
	return 0;
}
