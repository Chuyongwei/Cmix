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
    printf("�밴��������ķ�ʽ��������������пսڵ��� , ��ʾ ��'abc,,de,g,,f,,,'�� �����б�֤����ĺϷ��ԣ�\n");
    scanf("%s", a);
    num = 0;
    M_tree *T;
    T = creat();
    if (Judge(T))
        printf("�˶���������ȫ������\n");
    else
        printf("�˶�����������ȫ������\n");
    return 0;
}
