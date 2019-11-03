//编程实现按二叉排序树算法进行查找
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#define LH +1
#define EH 0
#define RH -1
typedef int Status;
typedef int ElemType;
typedef struct BSTNode{
	ElemType data;
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

using namespace std;
void R_Rotate(BSTree& p) {
	BSTree lc;
	lc = p->lchild;
	p->lchild = lc->rchild;
	lc->rchild = p;
	p = lc;
}

void L_Rotate(BSTree& p)
{
	BSTree rc;
	rc = p->rchild;
	p->rchild = rc->lchild;
	rc->lchild = p;
	p = rc;

}

Status InsertAVL(BSTree &T,ElemType e,Boolean)
int main()
{

}