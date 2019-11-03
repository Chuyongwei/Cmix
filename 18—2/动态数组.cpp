#include<stdio.h>
#include<malloc.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERLOW -2
typedef int Status;
typedef float ElemType;
typedef ElemType* Triplet;
Status InitTriplet(Triplet &T, ElemType v0, ElemType v1, ElemType v2)
{
	T=(Triplet)malloc(3*sizeof(ElemType));
	if(!T)
	  return ERROR;
	T[0] = v0;
	T[1] = v1;
	T[2] = v2;
	return OK;
}

Status DestroyTriplet(Triplet &T)
{
	free(T);
	T = NULL;
	return 0;
}

Status Get(Triplet T,int i,ElemType &e)
{
	if(i<1||i>3)
	  return ERROR;
	else e=T[i-1];
	  return OK;   
}

Status Put(Triplet &T,int i,ElemType e)
{
	if(i<1||i>3)
	  return ERROR;
     else
      T[i-1] = e;
     return OK;
}

Status Max(Triplet T,ElemType &e)
{
	if(T[0]>T[1])
	 e = T[0];
	else
	 e = T[1];
	if(T[2]>e)
	 e = T[2];
	return 0; 
}

Status Min(Triplet T,ElemType &e)
{
	if(T[0]<T[1])
	 e = T[0];
	else
	 e = T[1];
	if(T[2]<e)
	 e = T[2];
	return 0; 
}

int main()
{
	Triplet T;
	Status flag;
	ElemType v0,v1,v2,e;
	printf("请输入三个数：\n");
	scanf("%f%f%f",&v0,&v1,&v2);
	if(InitTriplet(T,v0,v1,v2))
	  printf("建立成功！\n");
	else 
	  printf("建立失败！\n");
	ElemType a,b,max,min;
	Status i;
	printf("替换第几个数字？");
	scanf("%d",&i); 
	printf("请选择替换的数字");
	scanf("%f",&a); 
	Put(T,i,a);
	printf("请选择显示第几个数字");
	scanf("%d",&i); 
	Get(T,i,b);
	printf("%f",b);
	Max(T,max);
	Min(T,min);
	printf("显示最大%f最小%f",max,min); 
	DestroyTriplet(T);
	return 0;
} 
