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
    printf("�밴��������ķ�ʽ��������������пսڵ��� , ��ʾ ��'abc,,de,g,,f,,,'�� �����б�֤����ĺϷ��ԣ�\n");
    scanf("%s", a);
    num = 0;
    M_tree *T;
    T = creat(1);
    printf("�������ĸ߶�Ϊ%d\n", len);
    return 0;
}

