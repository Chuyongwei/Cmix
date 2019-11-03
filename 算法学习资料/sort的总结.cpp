# include <cstdio> //c++使用scanf和printf要加的头文件
# include <algorithm>  //使用sort要加的头文件
# include <cstring> //使用字符串比较函数strcmp要加的头文件

using namespace std; //c++的命名空间，格式

bool cmp(int x,int y)  //自己定义的比较函数
{
	return x > y;
}

struct node
{
	int id;
	char name[30];
	int grade;
	
}student[20] = {{2,"BB",90},{1,"DD",95},{3,"AA",80},{4,"CC",90}};


bool cmp_node_1(struct node x,struct node y)  //按id排序
{
	return x.id < y.id;
}

bool cmp_node_2(struct node x,struct node y) //按name排序
{
	return strcmp(x.name,y.name) < 0;
}

bool cmp_node_3(struct node x,struct node y) //按grade排序
{
	return x.grade < y.grade;
}

bool cmp_node_4(struct node x,struct node y)
{
	if(x.grade == y.grade)
		return strcmp(x.name,y.name) > 0;
	return x.grade < y.grade;
}

int main()
{
	int a[6] = {45,2,9,12,5,15};

	printf("\n从小到大排序输出：\n");
	sort(a,a+6);
	for(int i = 0;i < 6;i++)
	{
		if(i) printf(" ");
		printf("%d",a[i]);
	}
	puts("");
	
	printf("\n从大到小排序输出: \n");
	sort(a,a+6,cmp);
	//调用自己定义的比较函数实现想要的排序方式
	for(int i = 0;i < 6;i++)
	{
		if(i) printf(" ");
		printf("%d",a[i]);
	}
	puts("");
	
	printf("\n\n按结构体数组id排序：\n");
    sort(student,student+4,cmp_node_1);
	
	for(int i = 0;i < 4;i++)
	{
		if(i) puts("");
		printf("%d %s %d",student[i].id,student[i].name,student[i].grade);
	}
	
	printf("\n\n按结构体数组name排序：\n");
    sort(student,student+4,cmp_node_2);

	for(int i = 0;i < 4;i++)
	{
		if(i) puts("");
		printf("%d %s %d",student[i].id,student[i].name,student[i].grade);
	}
	
	printf("\n\n按结构体数组grade排序：\n");
    sort(student,student+4,cmp_node_3);

	for(int i = 0;i < 4;i++)
	{
		if(i) puts("");
		printf("%d %s %d",student[i].id,student[i].name,student[i].grade);
	}
	
	printf("\n\n按结构体数组grade排序,如果grade相同按name逆字典序排序：\n");
    sort(student,student+4,cmp_node_4);

	for(int i = 0;i < 4;i++)
	{
		if(i) puts("");
		printf("%d %s %d",student[i].id,student[i].name,student[i].grade);
	}
	return 0;
}

/*================================
#######数组的名字代表的是首地址，而数组首地址是a[0],
####### 所以数组名字地址从0下标开始 ################

    sort函数有三个参数，
    1. 第一个参数表示排序数组的起始地址
    2. 第二个参数表示排序数组的结束地址
    3. 第三个参数表示比较规则（可以省略），
	    但想要自己实现特定的比较方式就要自己定义一个返回bool值的比较函数

############排序后存放位置，是输入的起始地址和结束地址之间############

  sort函数不仅可以比较整数类型，还可以比较字符，结构体等等
  其内部是用快排实现，速度较快。
==================================*/

