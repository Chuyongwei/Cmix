#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef int ElemType;
typedef struct{
       ElemType  *elem;   
       int  length;                
} SSTable;
typedef struct{
	int head;
	int tail;
	int maxnum;
}Block;

void InitLink(SSTable &L){
	L.elem=(ElemType *)malloc(MAX*sizeof(ElemType));
	L.length=0;
}
void EnList(SSTable &L,int i,int n){
	L.elem[i]=n;
	L.length++;
}
void CreateList( SSTable &L){
	int num,n,i;
 
    InitLink(L);
	printf("请由输入表中元素个数:\n");
	scanf("%d",&num);
	printf("随机产生表中元素:\n");
	for(i=1;i<=num;i++){
		n=rand()%90+10;
		printf("%3d",n);
		EnList(L,i,n);
	}
	printf("\n");
}
int Search_Seq(SSTable L, int key){
//在顺序ST中查找关键字等于key的数据元素。
   int i;
   L.elem[0]=key;
   for ( i =1;i<=L.length; i++ )
	   if(L.elem[i]==key){
		  printf("查找成功！\n");
          return i;
	   }//返回0则查找失败
   return 0;
}

void sort(SSTable &L){
	int i,j,temp;
	for (j=1; j<=L.length-1; j++)
        for (i =1; i<=L.length-j; i++){
            if (L.elem[i] >L.elem[i + 1]){
               temp = L.elem[i]; 
               L.elem[i] = L.elem[i + 1]; 
               L.elem[i + 1] = temp;
			}
		}
	for (i=1; i<=L.length; i++){
        printf("%3d", L.elem[i]);
 } 
 printf("\n");
 }
int Search_Bin(SSTable L, int  key,int low,int high)
{//在有序表ST中折半查找关键字为key的元素 
	int mid;
    while (low <= high)
        {  mid = (low+high)/2; 
            if ( key == L.elem[mid])  return mid;
            else if (key < L.elem[mid])  high = mid-1;
            else low = mid+1;
         }
     return 0;
  }

void CreateList1( SSTable &L){
	int num;
    InitLink(L);
	printf("请由输入表中元素个数:\n");
	scanf("%d",&num);
	printf("请输入输入整组数无序，但局部有序的一组整数:\n");
	int i,n;
	for(i=1;i<=num;i++){
		scanf("%d",&n);
		EnList(L,i,n);
	}
}
int Max(SSTable L,int h,int t){
	int max,i;
	max=L.elem[h];
	for(i=h;i<=t;i++)
		if(max<L.elem[i])
			max=L.elem[i];
	return max;
}

int Blocksearch(SSTable &L){
	Block a[MAX];
	int i,j,k,n,m,x;
	printf("要分为几块？\n");
	scanf("%d",&n);
	if(n>L.length)
		printf("无法分块\n");
	j=1;
    if(L.length%n==0)
		for(i=1;i<=n;i++){
	        k=L.length/n;
            a[i].head=j;
		    a[i].tail=j+k-1;
		    a[i].maxnum=Max(L,j,j+k-1);
		    j=j+k;
		}
	else{
		m=L.length/n;
		for(i=1;i<=n-1;i++){
	        k=m+1;
            a[i].head=j;
		    a[i].tail=j+k-1;
		    a[i].maxnum=Max(L,j,j+k-1);
		    j=j+k;
		}
		    k=L.length-(n-1)*k;
            a[i].head=j;
		    a[i].tail=j+k-1;
		    a[i].maxnum=Max(L,j,j+k-1);
	}
	printf("下面进行分块查找，请输入要查找的数:\n");
	scanf("%d",&x);

	for(i=1;i<=n&&x>a[i].maxnum;i++);
	if(i>n)
		return 0;

	j=a[i].head; k=a[i].tail;
	for(i=j;i<=k;i++)
		if(L.elem[i]==x)
			return i;
	return 0;
}




int main(){
    SSTable L,L2;
	int key;
	int low,high;
	int i,j;
	int x;
	CreateList(L);
	printf("下面进行顺序查找，请输入要查找的数:\n");
	scanf("%d",&key);
	i=Search_Seq(L, key);
	if(i==0)
		printf("查找失败!\n");
	else
		printf("该数为表的第%d个数\n",i);
	printf("冒泡排序后为:\n");
	sort(L);
	low=1;  high = L.length;
	printf("下面进行折半查找，请输入要查找的数:\n");
	scanf("%d",&key);
	j=Search_Bin(L, key, low, high);
	if(j==0)
		printf("查找失败!\n");
	else
		printf("该数为表的第%d个数\n",j);
	CreateList1( L2);
	i=Blocksearch( L2);
	if(i==0)
		printf("查找失败!\n");
	else
		printf("该数为表的第%d个数\n",i);
	system("pause");
	return 0;
} 


//折半递归

