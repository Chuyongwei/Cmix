#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[5555];
int num;
int len = 0;
struct M_tree
{
    char data;
    M_tree * lchild, * rchild;
    int length;
};

M_tree * creat(int n)
{
    M_tree *T;
    char c = a[num++];
    if (c == ',') T = NULL;
    else
    {
        T = (M_tree *)malloc(sizeof(M_tree));
        T->data = c;
        T->length = n;
        T->lchild = creat(n+1);
        T->rchild = creat(n+1);
        len = len > n ? len : n;
    }
    return T;
}

int main()
{
    printf("请按先序遍历的方式输入二叉树（其中空节点用 , 表示 如'abc,,de,g,,f,,,'， 请自行保证输入的合法性）\n");
    scanf("%s", a);
    num = 0;
    M_tree *T;
    T = creat(1);
    printf("二叉树的高度为%d\n", len);
    return 0;
}

