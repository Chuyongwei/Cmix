#include<stdio.h> 
#include<stdlib.h> 
#define OK 1
#define ERROR 0
#define TRUE 1
#define OVERFLOW -1
#define MAXSIZE 100
typedef int Status;
typedef int QElemType;
typedef struct{
	QElemType *base;
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue &Q){
	//
	Q.base = (QElemType*)malloc(MAXSIZE*sizeof(QElemType));
	if(!Q.base)exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

Status QueueLength(SqQueue Q){
	//
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

Status EnQueue(SqQueue &Q,QElemType e){
	//
	if((Q.rear+1)%MAXSIZE==Q.front) return OK;
	Q.base[Q.rear+1] = e;
	Q.rear  = (Q.rear+1)%MAXSIZE;
	return OK;
}

Status DeQueue(SqQueue &Q,Status &e){
	//
	if(Q.front ==Q.rear) return OK;
	e = Q.base[Q.front];
	Q.front = (Q.front+1)%MAXSIZE;
	return OK;
} 












