#include<stdio.h>
#include<stdlib.h>
#define addsize 10
#define size 100
#define OK 1
typedef int Status;
typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}*BiTree,BiTNode;
typedef struct{
	BiTree *base;
    int sizestack;
	int top;
}St;

//Õ»
void InitStack(St &S)
{
	S.base = (BiTree*)malloc(size*sizeof(BiTree));
	if (!S.base) exit(-2);
	S.sizestack = size;
	S.top = 0;
	return ;
}

Status StackEmpty(St S)
{
	if (S.top == 0)
		return 1;
	else return 0;
}

void Push(St &S, BiTree e)
{
	if (S.sizestack <= S.top)
	{
		S.base = (BiTree*)realloc(S.base, (S.sizestack + addsize) * sizeof(BiTree));
		S.sizestack += addsize;
	}
	S.base[S.top++] = e;
	return ;
}

void Pop(St &S, BiTree &e)
{
	if (S.top == 0)return;
	e = S.base[--S.top];
	return ;
}

Status Top(St S, BiTree e)
{
	if (S.top == 0)
		return 0;
	e = S.base[S.top - 1];
	return OK;
}
//¶þ²æÊ÷±éÀúµÝ¹é
void CreateBiTree(BiTree &T)
{
	TElemType n;
	n = getchar();
	if (n == '#')
		T = NULL;
	else {
		T = (BiTree) malloc (sizeof(BiTNode));
		if (!T->data)exit(-1);
		T->data = n;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

void Visit(BiTree &T)
{
	printf("%c", T->data);
}

void PreOrderTraverse(BiTree T)
{
	if (T) {
		printf("%c\t", T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

void InOrderTraverse(BiTree T)
{
	if (T)
	{
		InOrderTraverse(T->lchild);
		printf("%c\t", T->data);
		InOrderTraverse(T->rchild);
	}
}

void PostOrderTraverse(BiTree T)
{
	if (T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c\t", T->data);
	}
}

void visit( char e )
{
	printf( "%c\t",e );
}

//·ÇµÝ¹é±éÀú
void PreOrderTraverse1(BiTree T)
{
	St S;
	BiTree p;
	if (T)
	{
		InitStack(S);
		Push(S, T);
		while (!StackEmpty(S))
		{
			while (Top(S, p)&&p)
			{
				visit(p->data);
				Push(S, p->lchild);
			}
			Pop(S, p);
			if(!StackEmpty(S))
			{
				Pop(S, p);
				Push(S, p->rchild);
			}
		}
	}
}

void InOrderTraverse1(BiTree T)
{
	St S;
	BiTree p;
	if (T)
	{
		InitStack(S);
		Push(S, T);
		while (!StackEmpty(S))
		{
			while (Top(S, p) && p)
				Push(S, p->lchild);
			Pop(S, p);
			if(!StackEmpty(S))
			{
				Pop(S, p);
				printf("%c", p->data);
				Push(S, p->rchild);
			}
		}
	}

}

void PostOrderTraverse1(BiTree T)
{
	St S;
	BiTree p, q;
	p = T;
	q = NULL;
	if (T)
	{
		InitStack(S);
		Push(S, NULL);
		while (!StackEmpty(S) || p)
		{
			if (p&&p != q)
			{
				Push(S, p);
				p = p->lchild;
			}
			else
			{
				Pop(S, p);
				if (!StackEmpty(S))
				{
					if(p->rchild&&p->rchild!=q)
					{
						Push(S, p);
						p = p->rchild;
					}
					else
					{
						printf("%c", p->data);
						q = p;
					}
				}
			}
		}	
	}
}


int main()
{
	BiTree T;
	CreateBiTree (T);
	PreOrderTraverse1(T);
	return 0;
}
