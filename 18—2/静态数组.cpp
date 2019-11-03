#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
typedef int Status;
typedef float ElemType;
typedef struct{
	ElemType e[3];
}Triplet;

Status InitTriplet(Triplet &T,ElemType v0,ElemType v1,ElemType v2)
{
	T.e[0] = v0;
	T.e[1] = v1;
	T.e[2] = v2; 
	return OK;
}

Status DestroyTriplet(Triplet &T)
{
	return 0;
}

Status Get(Triplet T,int i,ElemType &e)
{
	if(i<1||i>3)
	  return ERROR;
	else e=T.e[i-1];
	  return OK;   
}

Status Put(Triplet &T,int i,ElemType e)
{
	if(i<1||i>3)
	  return ERROR;
     else
      T.e[i-1] = e;
     return OK;
}

Status Max(Triplet T,ElemType &e)
{
	if(T.e[0]>T.e[1])
	 e = T.e[0];
	else
	 e = T.e[1];
	if(T.e[2]>e)
	 e = T.e[2];
	return 0; 
}

Status Min(Triplet T,ElemType &e)
{
	if(T.e[0]<T.e[1])
	 e = T.e[0];
	else
	 e = T.e[1];
	if(T.e[2]<e)
	 e = T.e[2];
	return 0; 
}

int main()
{
	Triplet T;
	Status flag;
	ElemType v0,v1,v2,e;
	printf("请输入三个数：\n");
	scanf("%f%f%f",&v0,&v1,&v2);
	flag=InitTriplet(T,v0,v1,v2);
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
}
