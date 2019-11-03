#include<stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR  0
typedef int ElemType;
typedef int Status;
typedef struct DuLNode{
	ElemType data;
	struct DuLNode *next;
	struct DuLNode *prior;
} DuLNode,*DuLinkList;

Status InitList(DuLinkList &L,int i)//chuangjian
{
	DuLinkList p,q;
	int j=0;
	p = (DuLinkList)malloc(sizeof(DuLNode));
	L=p;
	p->next=NULL;
	p->prior=NULL;
	while(j<i)
	{
		q = (DuLinkList)malloc(sizeof(DuLNode));
		q->next = p->next;
		p->next = q;
		q->prior = p;
		p=q;
		j++;
	} 
	p->next = NULL;
	return OK;
} 
Status ListInsert(DuLinkList &L,int i,ElemType e)//²åÈë 
{
	DuLinkList q,p;
	int j=0;
	q=L;
	if(!(p=(DuLinkList)malloc(sizeof(DuLNode)))) return 0;
	p->data = e;
	while(j<i)
	{
		q = q->next;
		j++;
	}
	p->prior = q->prior;
	q->prior->next = p;
	p->next = q;
	q->prior = p; 
	return OK;
}

Status GetList(DuLinkList &L,int i,ElemType e)//ÊäÈë 
{
	DuLinkList p=L;
	int j=0;
	while(j<i)
	{
	p = p->next;
	j++;
	}
	p->data=e;
	return OK;
}

Status PutList(DuLinkList L,int i,ElemType &e)//Êä³ö 
{
	DuLinkList p=L;
	int j=0;
	while(j<i)
	{
		p = p->next;
		j++;
	}
	e = p->data;
	return OK;
}

Status DeleteList(DuLinkList &L,int i,ElemType &e)//É¾³ý 
{
	int j=0;
	DuLinkList p,q;
	p=L; 
	while(j<i)
	{
		p = p->next;
		j++;
	}
	e = p->data;
	q = p->next;
	q->prior = p->prior;
	p->prior->next = q; 
	free(p);
	return OK;
} 
Status main()
{
	int i,e;
	DuLinkList L;
	InitList(L,5);
	for(i=0;i<5;i++)
	{
		GetList(L,i+1,i);
	}
		for(i=0;i<5;i++)
	{
		PutList(L,i+1,e);
		printf("%d",e);
	}
	return 0;
}

