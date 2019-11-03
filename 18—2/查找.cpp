0/*算法1：采用顺序存储结构创建静态查找表，对查找表进行顺序查找和改进的顺序查找，并对其查找效率进行比较；
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
void Create(SSTable &ST, int n) {
	ST.elem = (KeyType*)malloc(LIST_INIT_SIZE * sizeof(KeyType));
	if (!ST.elem) exit(-1);//if(ST.elem == NULL)
	ST.length = 0;
	/* 
	int i,a[10] = { 45,33,45,63,67,46,43,85,67,84 };// scanf("%d"rand() % 100); 
	for (i = 0; i < 10; i++)
	{
		ST.elem[i] = a[i];
		ST.length++;
	}
	*/ 
}

int Search_seq(SSTable ST, KeyType key)//Search_seq(ST,key)
{//顺序查找 
	int i;
	ST.elem[0] = key;
	for(i=ST.length;!EQ(ST.elem[i],key);)
	{--i; }
	return i;
}

int Search_Bin(SSTable ST, KeyType key) {//折半查找 
	int mid;
	int low = 1,high = ST.length;
	while (low != high)
	{
		mid = (low + high) / 2;
		if (EQ(key, ST.elem[mid]))return mid;//if(key  == ST.elem)
		else if (LT(key, ST.elem[mid]))high = mid - 1;
		else low = mid + 1;
	}
	return 0;
}

int main(){
	int n,i,key;
	switch(n)
	{
		case 1:pritnf("请选择查找的数字：")；
		scanf("%d",&key);
	    i = Search_seq(ST,key);
		if(i!= 0)break;
	    case 2:printf("请选择查找的数字：");
	    scanf("%d",&key);
	    i = Search_Bin( ST,  key);
	    
	}
}
