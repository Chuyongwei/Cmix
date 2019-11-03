/*
给定2到15个不同的正整数，你的任务是计算这些数里面有多少个数对满足：数对中一个数是另一个数的两倍。

比如给定1 4 3 2 9 7 18 22，得到的答案是3，因为2是1的两倍，4是2个两倍，18是9的两倍。
输入
一行，给出2到15个两两不同且小于100的正整数。最后用0表示输入结束。
输出
一个整数，即有多少个数对满足其中一个数是另一个数的两倍。
样例输入
1 4 3 2 9 7 18 22 0
样例输出
3
*/
/*
#include<iostream>
	int main()
	{
		using namespace std;
		int a[16];
		int i, sum = 0;
		for (i = 0; i<16; i++)
		{
			cin >> a[i];
			if (a[i] == 0) break;
		}
		if(i==1)
		{
		cout << "less 2";
		return 0; 
		}
		
		for (i = 0; i<16 && a[i] != 0; i++)
		{
			int j;
			for (j = i + 1; a[j] != 0; j++)
			{
				if (a[i] != a[j])
				{
					if (a[i] == a[j] * 2 || a[j] == a[i] * 2)
					{
						sum++;
						break;
					}
				}

			}
		}
		cout << sum;
		return 0;
}*/
/*描述
在一个正方形的灰度图片上，肿瘤是一块矩形的区域，肿瘤的边缘所在的像素点在图片中用0表示。其它肿瘤内和肿瘤外的点都用255表示。
现在要求你编写一个程序，计算肿瘤内部的像素点的个数（不包括肿瘤边缘上的点）。已知肿瘤的边缘平行于图像的边缘。
输入
只有一个测试样例。第一行有一个整数n，表示正方形图像的边长。其后n行每行有n个整数，取值为0或255。整数之间用一个空格隔开。已知n不大于1000。
输出
输出一行，该行包含一个整数，为要求的肿瘤内的像素点的个数。
样例输入*/

#include <iostream>
using namespace std;
int main()
{
	int n;
	int sum = 0;
	int sum0 = 0;
	cin>>n;
	//动态创建二维数组
	int **area = new int* [n];
	for(int i=0; i<n; i++)
	{
		area[i] = new int[n];
	}
	//输入肿瘤布局
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>area[i][j];
			if(area[i][j]==0)
			{
				sum0++;	//计算边界数量
			}
		}
	}
	//按行计算非肿瘤块数
	for(int i=0; i<n; i++)
	{
		int flag = 0;	//标记是否出现肿瘤边界，出现置1
		//计算边界前面非肿瘤像素个数
		for(int j=0; j<n; j++)
		{
			if(area[i][j]==0)
			{
				flag = 1;
				break;
			}
			else
			{
				sum++;
			}
		}
		//该行出现肿瘤边界，计算边界后面非肿瘤像素
		if(flag==1)
		{
			for(int j=n-1; j>=0; j--)
			{
			if(area[i][j]==0)
				{
					break;
				}
				else
				{
					sum++;
				}
			}
		}
	}
	cout<<n*n-sum0-sum;
	return 0;
}















