#include<stdio.h>
#include<stdlib.h>
#define MAX 20
#define addsize 10
typedef int VertexType;
typedef struct ArcNode{//邻接点
	int adjvex;//指向指针的位置 
	struct ArcNode *nextarc;//指向下一条弧 
	//int *info;//该弧的相关信息 
}ArcNode,ArcPtr;

typedef struct VNode{//头结点 
	VertexType data;//顶点信息 
	ArcNode *firstarc;//指向第一条依附该点的弧的指针 
	int tag;//zhonglei
	
}VNode,AdijList[MAX];

typedef struct{//邻接表 
	int vexnum,arcnum;//节点数和边数 
	AdijList vertices;//头结点 
}ALGraph; 

//栈的函数 
typedef struct{
	ArcPtr *base;
	int top;
	int stacksize;
}St;

typedef struct{
	int *base;
	int top;
	int stacksize;
}St1;

void InitStack(St &S)
{
	S.base = (ArcPtr*)malloc(MAX*sizeof(ArcNode));
	S.stacksize = MAX;
	S.top = 0;
};

void InitStack1(St1 &S)
{
	
	S.base = (int*)malloc(MAX*sizeof(int));
	S.stacksize=MAX;
	S.top = 0;
}

int StackEmpty(St S)
{
	if(S.top==0)
	   return 1;
	else
	   return 0; 
}

int StackEmpty(St1 S)
{
	if(S.top==0)
	   return 1;
	else
	   return 0; 
}

void Push(St &S,ArcPtr p)
{
	if(S.top>=S.stacksize)
	{
	    S.base = (ArcPtr*)realloc(S.base,(S.stacksize+addsize)*sizeof(ArcNode));
	    S.stacksize+=addsize;
	}
	S.base[S.top++] = p;
}

void Push1(St1 &S,int p)
{
	if(S.top>=S.stacksize)
	{
		S.base = (int*)realloc(S.base,(S.stacksize+addsize)*sizeof(int));
		S.stacksize+=addsize;
	}
	S.base[S.top++] = p; 
}

void Pop(St S,ArcPtr &p)
{
	if(!StackEmpty(S))
	{
		p=S.base[S.top--];
	}
}

void Pop1(St1 S,int &p)
{
	if(!StackEmpty(S))
	{
		p=S.base[S.top--];
	}
}

//队列函数
 
 typedef struct{
 	ArcNode *base;
 	int front;
 	int rear;
 }SqQueue;

void InitQueue(SqQueue &Q)
{
	Q.base = (ArcNode*)malloc(MAX*sizeof(ArcNode));
	if(!Q.base) exit(0);
	Q.front = Q.rear = 0;
}

int QueueEmpty(SqQueue Q)
{
	if(Q.front == Q.rear)return 1;
	else return 0;
}

void EnQueue(SqQueue &Q,ArcNode e)
{
	if(((Q.rear+1)%MAX) == Q.front)exit(0);
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear+1)%MAX;
}

void DeQueue(SqQueue &Q,ArcNode &e)
{
	if((Q.rear%MAX) == Q.front)exit(0);
	e = Q.base[Q.rear];
	Q.rear  = (Q.rear-1)%MAX;
}

//图的操作
void CreatVex(ALGraph &G)
{//图的创建 
	int i,j,k;
	char
} 












































