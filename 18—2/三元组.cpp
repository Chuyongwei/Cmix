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
//��ʼ����Ԫ��
Status flage=InitTriplet(T, a, b, c);

Get(T, 1, &e);

Put(&T, 1, 5);

Max(T, &max);

Min(T, &min);

printf("��ǰԪ�ص�ֵΪ%d\n",e);

printf("��ǰ��Ԫ���е����ֵΪ%d\n", max);

printf("��ǰ��Ԫ���е���СֵΪ%d\n", min);
system("PAUSE");
getchar();
return 0;
}


//��ʼ����Ԫ��
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
//������Ԫ��
Status Destroy(Triplet *T) {

free(T);
return OK;
}

//�����±��ȡ��Ԫ���±��ֵ
Status Get(Triplet T, int i, int *e) {
if (i < 1 || i>3) {

return ERROE;

}
*e = *(T+i);

return *e;
}
//����Ԫ�����Ԫ��
Status Put(Triplet *T, int i, int e) {
if (i < 1 || i>3) {
return ERROE;
}
*(*T+i - 1) = e;
return OK;

}

//�ж���Ԫ���Ƿ�����������
Status IsAcending(Triplet T) {
if (*(T+0) < *(T+1) && *(T+1) < *(T+2)) {
return OK;
}
return ERROE;
}

//�ж���Ԫ���Ƿ��ǽ�������
Status IsDcending(Triplet T) {
if (*(T+0) > *(T+1) && *(T+1) > *(T+2)) {
return OK;
}
return ERROE;
}

//��ȡ��Ԫ���е����ֵ
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

//��ȡ��Ԫ���е���Сֵ
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
