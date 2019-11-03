#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct{
	BiTree *base;
	int head;
	int tail;
}SqQueue;

void InitBiTree(BiTree &bt)
{
	char ch;
	ch=getchar();

	if(ch=='#')
		bt=NULL;
	else
	{
		bt=(BiTree)malloc(sizeof(BiTNode));
		bt->data=ch;
		InitBiTree(bt->lchild);
		InitBiTree(bt->rchild);
	}
}

void InitQueue(SqQueue &q)
{
	q.base=(BiTree*)malloc(MAX*sizeof(BiTree));
	if(!q.base)
		return;
	q.head=q.tail=0;
}

void EnQueue(SqQueue &q,BiTree bt)
{
	q.base[q.tail++]=bt;	
}

void DeQueue(SqQueue &q,BiTree &bt)
{
	if(q.head==q.tail)
		return;
	bt=q.base[q.head++];
}

int BiTHight(BiTree bt)
{
	SqQueue q;
	BiTree p;
	int hight=0;
	int flag=1;

	if(bt){
		InitQueue(q);
		EnQueue(q,bt);
		while(q.head<q.tail)
		{
			DeQueue(q,p);
			if(p->lchild)
				EnQueue(q,p->lchild);
			if(p->rchild)
				EnQueue(q,p->rchild);
			if(q.head==flag)
			{
				hight++;
				flag=q.tail;
			}
		}
		return hight;
	}
	else
		return 0;
}

int main()
{
	BiTree bt;
	int hight;

	printf("请按先序遍历的方法输入一串字符，来建立该二叉树的二叉链表：\n");
	InitBiTree(bt);
	hight=BiTHight(bt);
	printf("该二叉树的高度为:%d\n",hight);
	return 0;
}
