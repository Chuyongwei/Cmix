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

Status QueueEmpty(LinkQueue Q)//������Ϊ�ն��У��򷵻�TURE�����򷵻�FLAse 
{
	if(Q.front == Q.rear)
	return TRUE;
	else return FALSE;
} 

int QueueLength(LinkQueue Q)//����Q��Ԫ�ظ����������г��� 
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

Status GetHead(LinkQueue Q,QElemType &e)//�����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK;���򷵻�ERROR 
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

Status DeQueue(LinkQueue &Q,QElemType &e)//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR 
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




















