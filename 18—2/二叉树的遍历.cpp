#include <stdio.h>
#include <stdlib.h>
#define Max 100
#define Plus 10

typedef struct Tree
{
	char data;
	struct  Tree *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct
{
	BiTree *base;
	int top;
	int stacksize;
}SqStack;


typedef struct
{
	BiTree *base;
	int  front;
	int  rear;
}LinkQueue;

void visit( char e )
{
	printf( "%c\t",e );
}
void InitStack( SqStack &S )
{
	S.base = ( BiTree* )malloc( Max * sizeof( BiTree ) );
	if( !S.base )
		exit( 0 );
 	S.top = 0;
	S.stacksize = Max;
	return;
}

int StackEmpty( SqStack S )
{
	if( S.top == 0 )
		return 1;
    return 0;
}

void Push( SqStack &S,BiTree e )
{
	if( S.top >= S.stacksize )
	{
		S.base = ( BiTree* )realloc( S.base,( S.stacksize + Plus ) * sizeof( BiTree ) );
		if( !S.base )
			exit( 0 );
		S.stacksize += Plus;
	}
	S.base[ S.top++ ] = e;
	return;
}

void Pop( SqStack &S,BiTree &e )
{
	if( StackEmpty( S ) )
		exit( 0 );
	e = S.base[--S.top];
	return;
}

int GetTop( SqStack s,BiTree &e )
{
	if( s.top == 0 )
	{
		printf( "it is error!\n" );
		return 0;
	}
	e = s.base[ s.top - 1 ];
	return 1;
}

void InitQueue( LinkQueue &Q )
{
	Q.base = ( BiTree* )malloc( sizeof( BiTree ) );
	if( !Q.base )
		exit( 0 );
	Q.front = Q.rear = 0;
	return;
}

void EnQueue( LinkQueue &Q,BiTree e )
{   
	if( ( Q.rear + 1 ) % Max == Q.front )
	{
		printf( "It is error!!!\n" );
		return;
	}
	Q.base[ Q.rear ] = e;
	Q.rear = ( Q.rear + 1 ) % Max;
	return;
}

void DeQueue( LinkQueue &Q,BiTree &e )
{
	if( Q.front == Q.rear )
		return;
	e = Q.base[ Q.front ];
	Q.front = ( Q.front + 1 ) % Max;
	return;
}

int QueueLength( LinkQueue Q )
{
	return ( Q.rear - Q.front + Max ) % Max;
}

void CreateTree1( BiTree &bt , char Pre[], char In[],int n )
{//已知先序和中序的字符串，建立二叉链表
	int ls,rs,i,j;
	char Inl[Max],Prel[Max];
	char Inr[Max],Prer[Max];
	i = j = 0;
	if( n <= 0 )
		bt = NULL;
	else
	{
		bt = ( BiTree )malloc( sizeof( BiTNode ) );
		bt-> data = Pre[0];
		i = 0;
		while( In[i] != Pre[0] )
			i++;
		ls = i;rs = n-i;
		for( j = 0 ; j < i ; i++ )
		{
			Prel[j] = Pre[j+1];
			Inl[j] = In[j];
		}
		for( j = i+1 ; j < n ; j ++ )
		{
			Prer[ j-i-1 ] = Pre[j];
			Inr[ j - i - 1 ] = In[j];
		}
		if( ls > 0 )
			CreateTree1( bt->lchild,Prel,Inl,ls );
		else
			bt->lchild = NULL;
		if( rs > 0 )
			CreateTree1( bt->rchild,Prer,Inr,rs );
		else
			bt->rchild = NULL;
	}
}

void CreateBiTree( BiTree &bt )
{
	char ch;
	ch = getchar();
	if( ch == '#' )
	{
		bt = NULL;
	}
	else
	{
		bt = ( BiTree )malloc( sizeof( BiTNode ) );
		bt->data = ch;
		CreateBiTree( bt->lchild );
		CreateBiTree( bt->rchild );
	}
}

void PreOrderTraverse1( BiTree bt )
{//二叉树先序遍历，递归
	if( bt )
	{
		printf( "%c\t",bt->data );
		PreOrderTraverse1( bt->lchild );
		PreOrderTraverse1( bt->rchild );
	}
}

void PreOrderTraverse2( BiTree bt )
{//先序遍历，非递归
	SqStack s;
	BiTree p;
	if( bt )
	{   
		InitStack( s );
		Push( s,bt );
		while( !StackEmpty( s ) )
		{
			while( GetTop( s,p ) && p )
			{
				visit( p->data );
				Push( s,p->lchild );
			}
			Pop( s,p );
			if( !StackEmpty( s ) )
			{
				Pop( s,p );
				Push( s,p->rchild );
			}
		}
	}
}
void InOrderTraverse1( BiTree bt )
{//中序遍历，递归
	if( bt )
	{
		InOrderTraverse1( bt->lchild );
		printf( "%c\t",bt->data );
		InOrderTraverse1( bt->rchild );
	}
}

void InOrdetTraverse2( BiTree bt,SqStack s )
{//中序遍历，非递归
	BiTree p;
	if( bt )
	{
		InitStack( s );
		Push( s,bt );
		while( !StackEmpty( s ) )
		{
			while( GetTop( s,p ) && p )
			{
				Push( s,p->lchild );
			}
			Pop( s,p );
			if( !StackEmpty( s ) )
			{
				Pop( s,p );
				visit( p->data );
				Push( s,p->rchild );
			}
		}
	}
}

void LastOrderTraverse( BiTree bt )
{//二叉树后序遍历，递归
	if( bt )
	{
		LastOrderTraverse( bt->lchild );
		LastOrderTraverse( bt->rchild );
		printf( "%c\t",bt->data );
	}
}

void PostOrderTraverse( BiTree T )
{//后序遍历，非递归
	BiTree p,q;
	SqStack s; 
	if( T )
	{
		InitStack( s );
		Push( s,T );
		
		while( !StackEmpty( s ) )
		{
			while( GetTop( s,p ) && p )
			{
				Push( s,p->lchild );
			}
			Pop( s,p );
			if( !StackEmpty( s ) )
			{
				GetTop( s,p );
				if( p->rchild )
					Push( s,p->rchild );
				else
				{
					Pop( s,p );
					visit( p->data );
					while( !StackEmpty( s ) && GetTop( s,q ) && q->rchild == p )
					{
						Pop( s,p );
						visit( p->data );
					}
					if( !StackEmpty( s ) )
					{
						GetTop( s,p );
						Push( s,p->rchild );
					}
				}
			}
		}
	}
}

int main()
{
	BiTree T;
	LinkQueue l;
	SqStack s;
	int x, y;
	x = y = 0;
	printf( "please create a Tree:\n" );
	CreateBiTree( T );
	printf( "this is the xianxu:\n" );
    PreOrderTraverse1( T );
	printf( "\n" );
	printf( "this is the xianxu:\n" );
	PreOrderTraverse2(T);
	printf( "\n" );
	printf( "this is the zhongxu:\n" );
	InOrderTraverse1(T);
	printf( "this is the zhongxu:\n" );
	InOrdetTraverse2( T,s );
	printf( "\n" );
	printf( "this is houxu:\n" );
	PostOrderTraverse( T );
	printf( "\n" );
	printf( "this is the houxu:\n" );
	LastOrderTraverse( T );

	return 0;
}

