#include<stdio.h>
#include<malloc.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERLOW -2
typedef int Status;
typedef int ElemType;
typedef ElemType* Triplet;
Status InitTriplet(Triplet & T,int v1,int v2,int v3){
T=(ElemType*)malloc(3*sizeof(ElemType));//申请内存
if(!T)return ERROR;
T[0]=v1;
T[1]=v2;
T[2]=v3;
return OK;
}
Status GetElem(Triplet T,int i,ElemType & e){
if(i<1||i>3)return ERROR;
e=T[i-1];
return OK;
}
Status Destroy(Triplet & T){
free(T);//释放空间
T=NULL;
return OK;
}
Status SetElem(Triplet & T,int i,ElemType e){
if(i<1||i>3)return ERROR;
T[i-1]=e;
return OK;
}
Status Max(Triplet T,ElemType & e){
e=T[0]>T[1]?T[0]:T[1];
e=e>T[2]?e:T[2];
return OK;
}
Status Min(Triplet T,ElemType & e){
e=T[0]<T[1]?T[0]:T[1];
e=e<T[2]?e:T[2];
return OK;
}

int main(){
printf("欢迎！\n现在我们将建立一个三元组，请输入三个元素：");
Triplet T;
ElemType v1,v2,v3;
scanf("%d%d%d",&v1,&v2,&v3);
if(InitTriplet(T,v1,v2,v3))printf("建立成功！\n");
else printf("建立失败！\n");
printf("现在我们将获取三元组的数值，请输入位置：");
int i;
ElemType e;
scanf("%d",&i);
if(GetElem(T,i,e))printf("%d\n",e);
else printf("获取失败！\n");
printf("现在我们将修改三元组的值：请输入位置及修改后的值：");
scanf("%d%d",&i,&e);
if(SetElem(T,i,e))printf("修改成功！\n");
else printf("修改失败！\n");
Max(T,e);
printf("三元组中的最大值为%d\n",e);
Min(T,e);
printf("三元组中的最大值为%d\n",e);
printf("现在将要销毁三元组，销毁中...\n");
if(Destroy(T))printf("销毁成功！\n");
else printf("销毁失败！\n");
system("pause");//用于暂停程序运行
return OK;
}


