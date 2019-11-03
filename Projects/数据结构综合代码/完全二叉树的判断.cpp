#include<stdio.h>
#include<stdlib.h>
#define MAX 20
#define INCREMENT 10
typedef char TElemType; 

typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree &bt)
{
	char ch;
	ch=getchar();
	if(ch=='#')
		bt=NULL;
	else
	{
		bt=(BiTree)malloc(sizeof(BiTNode));
		bt->data=ch;
		CreateBiTree(bt->lchild);
		CreateBiTree(bt->rchild);
	}
}

int Judge(BiTree bt)
{
	int head=0;
	int rear=0;
	int flag1=1;
	int flag2=1;
	BiTNode *judge[MAX],*p;

	if(bt!=NULL)
	{
		rear++;
		judge[rear]=bt;
		while(head!=rear)
		{
			head++;
			p=judge[head];
			if(p->lchild==NULL)
			{
				flag2=0;
				if(p->rchild!=NULL)
					flag1=0;
			}
			else
			{
				if(flag2==1)
				{
					rear++;
					judge[rear]=p->lchild;
					if(p->rchild==NULL)
						flag2=0;
					else
					{
						rear++;
						judge[rear]=p->rchild;
					}
				}
			else
				flag1=0;
			}
		}
	return flag1;
	}
return  1;
} 

int main()
{
	BiTree bt;
	printf("以先序遍历输入一串字符，建立二叉树的二叉链表：\n");
	CreateBiTree(bt);
	if(Judge(bt))
		printf("该二叉树是一棵完全二叉树！\n");
	else
		printf("该二叉树不是一棵完全二叉树！\n");	
	return 0;
}

