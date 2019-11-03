# include <cstdio> //c++ʹ��scanf��printfҪ�ӵ�ͷ�ļ�
# include <algorithm>  //ʹ��sortҪ�ӵ�ͷ�ļ�
# include <cstring> //ʹ���ַ����ȽϺ���strcmpҪ�ӵ�ͷ�ļ�

using namespace std; //c++�������ռ䣬��ʽ

bool cmp(int x,int y)  //�Լ�����ıȽϺ���
{
	return x > y;
}

struct node
{
	int id;
	char name[30];
	int grade;
	
}student[20] = {{2,"BB",90},{1,"DD",95},{3,"AA",80},{4,"CC",90}};


bool cmp_node_1(struct node x,struct node y)  //��id����
{
	return x.id < y.id;
}

bool cmp_node_2(struct node x,struct node y) //��name����
{
	return strcmp(x.name,y.name) < 0;
}

bool cmp_node_3(struct node x,struct node y) //��grade����
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

	printf("\n��С�������������\n");
	sort(a,a+6);
	for(int i = 0;i < 6;i++)
	{
		if(i) printf(" ");
		printf("%d",a[i]);
	}
	puts("");
	
	printf("\n�Ӵ�С�������: \n");
	sort(a,a+6,cmp);
	//�����Լ�����ıȽϺ���ʵ����Ҫ������ʽ
	for(int i = 0;i < 6;i++)
	{
		if(i) printf(" ");
		printf("%d",a[i]);
	}
	puts("");
	
	printf("\n\n���ṹ������id����\n");
    sort(student,student+4,cmp_node_1);
	
	for(int i = 0;i < 4;i++)
	{
		if(i) puts("");
		printf("%d %s %d",student[i].id,student[i].name,student[i].grade);
	}
	
	printf("\n\n���ṹ������name����\n");
    sort(student,student+4,cmp_node_2);

	for(int i = 0;i < 4;i++)
	{
		if(i) puts("");
		printf("%d %s %d",student[i].id,student[i].name,student[i].grade);
	}
	
	printf("\n\n���ṹ������grade����\n");
    sort(student,student+4,cmp_node_3);

	for(int i = 0;i < 4;i++)
	{
		if(i) puts("");
		printf("%d %s %d",student[i].id,student[i].name,student[i].grade);
	}
	
	printf("\n\n���ṹ������grade����,���grade��ͬ��name���ֵ�������\n");
    sort(student,student+4,cmp_node_4);

	for(int i = 0;i < 4;i++)
	{
		if(i) puts("");
		printf("%d %s %d",student[i].id,student[i].name,student[i].grade);
	}
	return 0;
}

/*================================
#######��������ִ�������׵�ַ���������׵�ַ��a[0],
####### �����������ֵ�ַ��0�±꿪ʼ ################

    sort����������������
    1. ��һ��������ʾ�����������ʼ��ַ
    2. �ڶ���������ʾ��������Ľ�����ַ
    3. ������������ʾ�ȽϹ��򣨿���ʡ�ԣ���
	    ����Ҫ�Լ�ʵ���ض��ıȽϷ�ʽ��Ҫ�Լ�����һ������boolֵ�ıȽϺ���

############�������λ�ã����������ʼ��ַ�ͽ�����ַ֮��############

  sort�����������ԱȽ��������ͣ������ԱȽ��ַ����ṹ��ȵ�
  ���ڲ����ÿ���ʵ�֣��ٶȽϿ졣
==================================*/

