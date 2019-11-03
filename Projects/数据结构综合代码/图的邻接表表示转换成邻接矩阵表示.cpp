#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int u, v;
}q[111111];

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        q[i].u = 0;
        q[i].v = 0;
    }
}

void change(int n, int m)
{
    int **row = new int*[n];
    for (int i = 0; i < n; i++)
    {
        row[i] = new int[n];
        for (int j = 0; j < n; j++)
            row[i][j] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int u = q[i].u;
        int v = q[i].v;
        row[u][v] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", row[i][j]);
        printf("\n");
    }
    printf("0������ͨ  1������ͨ\n");
}

int main()
{
    int m, n, i;
    printf("�������ĸ���:\n");
    scanf("%d", &n);
    printf("������ߵĸ���:\n");
    scanf("%d", &m);
    init(n);
    for (i = 0; i < m; i++)
    {
        printf("�������%d��������㡢�յ�(���������%d��%d):\n", i+1, 0, n-1);
        scanf("%d%d", &q[i].u, &q[i].v);
    }
    change(n, m);
    return 0;
}
