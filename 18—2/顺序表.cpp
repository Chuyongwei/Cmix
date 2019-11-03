#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define ERROR 0
#define TURE 1
#define OK 1
#define OVERFLOW -2
#define LIST_SIZE 100
#define LISTINCREAMENT 10
typedef int Status;
typedef int ElemType;
typedef struct
{
	ElemType *elem;
	int length;//���Ա�ĳ��� 
	int listsize;//��ǰ���䳤�� 
} Sqlist;

Status InitList(Sqlist &L)//����һ���ձ� 
{
	L.elem = (ElemType*)malloc(LIST_SIZE*sizeof(ElemType));
	if(!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_SIZE;
	return OK;
}

Status ListInsert(Sqlist &L,int i,ElemType e)//���Ա�Ĳ��� ,��i֮ǰ���� 
{
	ElemType *q,*p;
	if(i>L.length+1||i<1) return ERROR;
	if(L.length<L.listsize)
	{
	    L.elem = (ElemType*)realloc(L.elem,(L.listsize+LISTINCREAMENT)*sizeof(ElemType));
	    if(!L.elem) return OK;
		L.listsize+=LISTINCREAMENT; 
	}
	q = &L.elem[i-1];
	for(p = &(L.elem[L.length-1]);p>=q;p--)
	{
		*(p+1) = *p;
	} 
	*q = e;
	++L.length;
	return OK;
}

Status ListDelete(Sqlist &L,int i,ElemType &e)//˳����ɾ����������ֵ 
{
	ElemType *q,*p;
	if(i<1||i>L.length) return ERROR;
	e = L.elem[i-1];
	q = &L.elem[i-1];
	for(p = &L.elem[L.length-1];q<p;p++)
	{
		p[i-1] = p[i];
	}
	L.length--;
	return OK; 
} 

Status LocatElem(Sqlist L,ElemType e)//���� 
{
	ElemType p = L.elem[0];
	int i=1;
	while(L.elem[i-1]!=e&&i<=L.length)
	    i++; 
	if(i<=L.length)return i;
	else return 0;
}
 int main()
 {
 	Status i;
 	Sqlist L;
 	InitList(L);
 	for(i=0;i<20;i++)
 	{
 	  L.elem[i] = i;
 	  L.length++;
     }
 	ListInsert(L,10,60);
 	for(i=0;i<20;i++)
 	printf("%5d",L.elem[i]);
 	printf("%10d",L.length);
}
