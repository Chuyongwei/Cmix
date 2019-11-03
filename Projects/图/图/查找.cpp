/*算法1：采用顺序存储结构创建静态查找表，对查找表进行顺序查找和改进的顺序查找，并对其查找效率进行比较；
算法2：采用顺序存储结构创建静态查找表——有序表，对有序表进行二分查找；*/
#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
//- - 对数值型关键字
#define EQ(a,b) ((a) == (b))
#define LT(a,b) ((a) <  (b))
#define LQ(a,b) ((a) <= (b))
typedef int Status;
typedef int ElemType;
typedef int KeyType;
typedef struct {
	KeyType *elem;
	int length;
}SSTable;
void Create(SSTable &ST) {
	ST.elem = (KeyType*)malloc(LIST_INIT_SIZE * sizeof(KeyType));
	if (!ST.elem) exit(-1);
	ST.length = 0;
	
}

void input(SSTable &ST,int sum) {
	int i;//a[10] = { 45,33,45,63,67,46,43,85,67,84 };
	for (i = 1; i <= sum; i++)
	{
		ST.elem[i] = rand()%100;
		printf("%5d", ST.elem[i]);
		ST.length++;  
	}
}

void input2(SSTable &ST) {
	int i, a[10] = { 5,13,19,21,37,56,64,75,80,88};
	for (i = 1; i <= 10; i++)
	{
		ST.elem[i] = a[i - 1];
		printf("%5d", ST.elem[i]);
		ST.length++;
	}
}
int Search_seq(SSTable ST, KeyType key)//顺序查找法
{
	int i;
	ST.elem[0] = key;
	for(i=ST.length; !EQ(ST.elem[i], key);)
	{
		--i;
	}
	return i;
}

int Search_Bin(SSTable ST, KeyType key) {//折半查找法
	int mid;
	int low = 1,high = ST.length;
	while (low != high)
	{
		mid = (low + high) / 2;
		if (EQ(key, ST.elem[mid]))return mid;
		else if (LT(key, ST.elem[mid]))high = mid - 1;
		else low = mid + 1;
	}
	return 0;
}

int main()
{
	int key, n, sum,i;
	SSTable ST;
	Create(ST);
	printf("请选择查找方式\n1.顺序查找\n2.二分法\n");
	scanf("%d", &n);
	switch (n)
	{
	case 1:printf("需要多少数字");
	    scanf("%d",&sum);
	    input(ST,sum);
		printf("\n请输入要查找内容:");
		scanf("%d", &key);
		i = Search_seq(ST, key);
		if (i == 0){printf("\n不存在"); break;}
		printf("\n%d", ST.elem[i]); break;
	case 2:input2(ST);
		printf("\n请输入要查找内容:");
			scanf("%d", &key);
		i = Search_Bin(ST, key);
		if (i == 0) { printf("不存在"); break; }
		printf("%d", ST.elem[i]);
	default:
		break;
	}
}
