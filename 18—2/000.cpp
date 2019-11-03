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
T=(ElemType*)malloc(3*sizeof(ElemType));//�����ڴ�
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
free(T);//�ͷſռ�
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
printf("��ӭ��\n�������ǽ�����һ����Ԫ�飬����������Ԫ�أ�");
Triplet T;
ElemType v1,v2,v3;
scanf("%d%d%d",&v1,&v2,&v3);
if(InitTriplet(T,v1,v2,v3))printf("�����ɹ���\n");
else printf("����ʧ�ܣ�\n");
printf("�������ǽ���ȡ��Ԫ�����ֵ��������λ�ã�");
int i;
ElemType e;
scanf("%d",&i);
if(GetElem(T,i,e))printf("%d\n",e);
else printf("��ȡʧ�ܣ�\n");
printf("�������ǽ��޸���Ԫ���ֵ��������λ�ü��޸ĺ��ֵ��");
scanf("%d%d",&i,&e);
if(SetElem(T,i,e))printf("�޸ĳɹ���\n");
else printf("�޸�ʧ�ܣ�\n");
Max(T,e);
printf("��Ԫ���е����ֵΪ%d\n",e);
Min(T,e);
printf("��Ԫ���е����ֵΪ%d\n",e);
printf("���ڽ�Ҫ������Ԫ�飬������...\n");
if(Destroy(T))printf("���ٳɹ���\n");
else printf("����ʧ�ܣ�\n");
system("pause");//������ͣ��������
return OK;
}


