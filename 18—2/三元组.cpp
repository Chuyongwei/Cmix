#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define OK 1
#define ERROE 0
typedef int Status;
typedef int *Triplet;
int main()
{
	Status InitTriplet(Triplet &T, int v1, int v2, int v3);
	Status Get(Triplet T, int i, int *e);
	Status Put(Triplet *T, int i, int e);
	Status Min(Triplet T, int *e);
	Status Max(Triplet T, int *e);
	Triplet T;
int a = 1, b = 2, c = 3, e=0, max, min;
//初始化三元组
Status flage=InitTriplet(T, a, b, c);

Get(T, 1, &e);

Put(&T, 1, 5);

Max(T, &max);

Min(T, &min);

printf("当前元素的值为%d\n",e);

printf("当前三元组中的最大值为%d\n", max);

printf("当前三元组中的最小值为%d\n", min);
system("PAUSE");
getchar();
return 0;
}


//初始化三元组
Status InitTriplet(Triplet *T, int v1, int v2, int v3) 
{
    T =(Triplet*)malloc(3*sizeof(int));
if (*T == NULL) 
{
exit(0);
}
*(*T) = v1;
*(*T+1) = v2;
*(*T+2) = v3;

return OK;

}
//销毁三元组
Status Destroy(Triplet *T) {

free(T);
return OK;
}

//根据下标获取三元组下标的值
Status Get(Triplet T, int i, int *e) {
if (i < 1 || i>3) {

return ERROE;

}
*e = *(T+i);

return *e;
}
//向三元组添加元素
Status Put(Triplet *T, int i, int e) {
if (i < 1 || i>3) {
return ERROE;
}
*(*T+i - 1) = e;
return OK;

}

//判断三元组是否是升序排列
Status IsAcending(Triplet T) {
if (*(T+0) < *(T+1) && *(T+1) < *(T+2)) {
return OK;
}
return ERROE;
}

//判断三元组是否是降序排列
Status IsDcending(Triplet T) {
if (*(T+0) > *(T+1) && *(T+1) > *(T+2)) {
return OK;
}
return ERROE;
}

//获取三元组中的最大值
Status Max(Triplet T, int *max) {

*max = *(T+0);
for (int i = 1; i <3; i++)
{
if (*max < *(T+i)) {
*max = *(T+i);
}
}
return OK;

}

//获取三元组中的最小值
Status Min(Triplet T, int *min) {
*min = *(T+0);
for (int i = 0; i <3; i++)
{
if (*min > *(T+i)) {
*min = *(T+i);
}

}

return OK;


}
