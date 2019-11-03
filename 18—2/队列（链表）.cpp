#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
typedef int QElemType;
typedef int Status;
typedef struct QNode{
	QElemType data;
	struct QNode *next;
}Qnode,*QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q)//
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(Qnode));
	if(!Q.front)exit(OVERFLOW);
	Q.front->next=NULL;
	return OK;
}

Status DestroyQueue(LinkQueue &Q)//
{
	while(Q.front){
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
}

Status QueueEmpty(LinkQueue Q)//若队列为空队列，则返回TURE，否则返回FLAse 
{
	if(Q.front == Q.rear)
	return TRUE;
	else return FALSE;
} 

int QueueLength(LinkQueue Q)//返回Q的元素个数，即队列长度 
{
	QueuePtr p,q;
	int n=1;
	p= Q.front;
	while(p!=Q.rear)
	{
		n++;
		p->next;
	}
	return n;
}

Status GetHead(LinkQueue Q,QElemType &e)//若队列不空，则用e返回Q的对头元素，并返回OK;否则返回ERROR 
{
{
	if(Q.front!=Q.rear)
	{
	   e = Q.front->data;
	   return OK;
    }
    else
    return ERROR;
}

Status EnQueue(LinkQueue &Q,QElemType &e)
{
	QueuePtr p;
	if(!(p=(QueuePtr)malloc(sizeof(Qnode))))
	  exit(OVERFLOW);
	p->data = e;
	p->next = Q.rear->next;
	Q.rear->next = p;
	return OK;
}

Status DeQueue(LinkQueue &Q,QElemType &e)//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；否则返回ERROR 
{
	QueuePtr q;
	if(Q.front==Q.rear)
	return FLASE;
	else
	{
		q = Q.front;
		e = q->data;
		Q.front = Q.front->next;
		free(q);
		return OK;
	}
}

Status QueueTraverse(LinkQueue Q,)




















