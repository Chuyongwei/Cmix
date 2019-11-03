/*�㷨1������˳��洢�ṹ������̬���ұ��Բ��ұ����˳����Һ͸Ľ���˳����ң����������Ч�ʽ��бȽϣ�
�㷨2������˳��洢�ṹ������̬���ұ�����������������ж��ֲ��ң�*/
#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
//- - ����ֵ�͹ؼ���
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
int Search_seq(SSTable ST, KeyType key)//˳����ҷ�
{
	int i;
	ST.elem[0] = key;
	for(i=ST.length; !EQ(ST.elem[i], key);)
	{
		--i;
	}
	return i;
}

int Search_Bin(SSTable ST, KeyType key) {//�۰���ҷ�
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
	printf("��ѡ����ҷ�ʽ\n1.˳�����\n2.���ַ�\n");
	scanf("%d", &n);
	switch (n)
	{
	case 1:printf("��Ҫ��������");
	    scanf("%d",&sum);
	    input(ST,sum);
		printf("\n������Ҫ��������:");
		scanf("%d", &key);
		i = Search_seq(ST, key);
		if (i == 0){printf("\n������"); break;}
		printf("\n%d", ST.elem[i]); break;
	case 2:input2(ST);
		printf("\n������Ҫ��������:");
			scanf("%d", &key);
		i = Search_Bin(ST, key);
		if (i == 0) { printf("������"); break; }
		printf("%d", ST.elem[i]);
	default:
		break;
	}
}
