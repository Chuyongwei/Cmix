#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[5555];
int num;
struct M_tree
{
    char data;
    M_tree * lchild, * rchild;
};

M_tree * creat()
{
    M_tree *T;
    char c = a[num++];
    if (c == ',') T = NULL;
    else
    {
        T = (M_tree *)malloc(sizeof(M_tree));
        T->data = c;
        T->lchild = creat();
        T->rchild = creat();
    }
    return T;
}

int Judge(M_tree * head)
{
    M_tree **base, **top;
    base = (M_tree **) malloc (5555*sizeof(M_tree **));
    top = base + 1;
    *base = head;
    while (*base != NULL)
    {
        *(top++) = (*base)->lchild;
        *(top++) = (*base)->rchild;
        base++;
    }
    while (base < top)
    {
        if (*(base++) != NULL)
            return 0;
    }
    return 1;
}

int main()
{
    printf("请按先序遍历的方式输入二叉树（其中空节点用 , 表示 如'abc,,de,g,,f,,,'， 请自行保证输入的合法性）\n");
    scanf("%s", a);
    num = 0;
    M_tree *T;
    T = creat();
    if (Judge(T))
        printf("此二叉树是完全二叉树\n");
    else
        printf("此二叉树不是完全二叉树\n");
    return 0;
}
