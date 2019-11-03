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
	printf("�����������Ԫ�ظ���:\n");
	scanf("%d",&num);
	printf("�����������Ԫ��:\n");
	for(i=1;i<=num;i++){
		n=rand()%90+10;
		printf("%3d",n);
		EnList(L,i,n);
	}
	printf("\n");
}
int Search_Seq(SSTable L, int key){
//��˳��ST�в��ҹؼ��ֵ���key������Ԫ�ء�
   int i;
   L.elem[0]=key;
   for ( i =1;i<=L.length; i++ )
	   if(L.elem[i]==key){
		  printf("���ҳɹ���\n");
          return i;
	   }//����0�����ʧ��
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
{//�������ST���۰���ҹؼ���Ϊkey��Ԫ�� 
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
	printf("�����������Ԫ�ظ���:\n");
	scanf("%d",&num);
	printf("�������������������򣬵��ֲ������һ������:\n");
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
	printf("Ҫ��Ϊ���飿\n");
	scanf("%d",&n);
	if(n>L.length)
		printf("�޷��ֿ�\n");
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
	printf("������зֿ���ң�������Ҫ���ҵ���:\n");
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
	printf("�������˳����ң�������Ҫ���ҵ���:\n");
	scanf("%d",&key);
	i=Search_Seq(L, key);
	if(i==0)
		printf("����ʧ��!\n");
	else
		printf("����Ϊ��ĵ�%d����\n",i);
	printf("ð�������Ϊ:\n");
	sort(L);
	low=1;  high = L.length;
	printf("��������۰���ң�������Ҫ���ҵ���:\n");
	scanf("%d",&key);
	j=Search_Bin(L, key, low, high);
	if(j==0)
		printf("����ʧ��!\n");
	else
		printf("����Ϊ��ĵ�%d����\n",j);
	CreateList1( L2);
	i=Blocksearch( L2);
	if(i==0)
		printf("����ʧ��!\n");
	else
		printf("����Ϊ��ĵ�%d����\n",i);
	system("pause");
	return 0;
} 


//�۰�ݹ�

