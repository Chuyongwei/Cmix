#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>  
#define max 20               //���м����
#define MAX_LNT 10         //������
#define INF 32627            //�������м���ֱ��·�����ô���32627��ʾ
typedef struct node          /*����һ���ṹ�壬�������п��Կ��������յ㣬֮��ĵ�·���Կ���һ����*/ 
{
        int str;             /*���*/ 
        int end;            /*�յ�*/ 
        int dis;            /*����*/ 
        }node;  
node p[max],temp;          /*p��¼������Ϣ*/  
typedef struct{             //�ڽӾ���洢ͼ�ṹ
int vexs[MAX_LNT];        //�������ڴ洢������
int adj[max+1][max+1];      //ͼ���ڽӾ����ʾ
int n,e;                    //n�����������e������м����
}graph; 
int pre[100],rank[100];        /*�����ж��Ƿ񹹳ɻ�·*/  
//int arcs[MAX_LNT][MAX_LNT];/*n��ʾ���и�����arcs[][]��¼���м�Ȩֵ*/ 
int menu()                /*�˵�����*/ 
{ 
    int m; 
    printf("            ����С������              \n"); 
    printf("  ************************************\n\n"); 
    printf("  1:�������֮�����Ϣ\n"); 
    printf("  2:�ж��Ƿ��ܹ���һ����С������\n"); 
    printf("  3:�������г���������С������\n"); 
    printf("  4:�˳�\n"); 
    printf(" ************************************\n\n"); 
    printf("  ��������ѡ����(1-4):"); 
    scanf("%d",&m);  
    return m; 
    } 
    void create(graph *g) /*���������Ϣ*/ 
    { 
         int i,j,k; 
         printf("���������Ϊ:"); 
         scanf("%d",&(g->n)); 
         printf("\n"); 
         printf("����n�����м����Ϊ:");  
         scanf("%d",&(g->e)); 
         printf("������еĸ�������Ϊ:");  
         for(i=0;i<(g->n);i++) 
         scanf("%d",&(g->vexs[i])); //�����������vexs[] 
         printf("����%d���ߣ������ڽӾ���",(g->e)); 
         printf("\n"); 
         for(i=0;i<(g->n);i++) //��ʼ���ڽӾ���
         { 
             for(j=0;j<(g->n);j++) 
             { 
                 if(i==j) 
                 g->adj[i][j]=0; 
                 else 
                 g->adj[i][j]=INF; 
             } 
         } 
         printf("����������ڽӹ�ϵ�����������ھ��������ڵ������м�Ȩֵ:\n"); 
         for(k=0;k<(g->e);k++) //��g->e���ߣ�����g->e��Ȩֵ
         { 
            scanf("%d,%d",&i,&j); 
            scanf("%d",&g->adj[i][j]); 
            }
            for(i=0;i<(g->n);i++) 
            for(j=0;j<(g->n);j++) 
            g->adj[j][i]=g->adj[i][j]; 
            printf(" ͼ���ڽӾ�������\n"); 
            for(i=0;i<(g->n);i++) 
            //����ڽӾ���g 
            { 
               for(j=0;j<(g->n);j++) 
               if(g->adj[i][j]==INF) 
               printf("\t%3s","��"); 
               else 
               printf("\t%3d",g->adj[i][j]); 
               printf("\n"); 
            } 
} 
/*�����������������Ǽ��鵱һ������ӽ�ȥ���Ƿ�������·*/ 
void set(int x)/*��ʼ��*/ 
{ 
     pre[x] = x;
     rank[x] = 0; 
     } 
     int find(int x)/*�ҵ�����������*/ 
     { 
         if(x != pre[x])  
         pre[x] = find(pre[x]); 
         return pre[x]; 
         } 
void Union(int x,int y)/*����������ӵ�һ��������ȥ*/ 
{ 
     x = find(x); 
     y = find(y); 
     if(rank[x] >= rank[y]) 
     { 
                pre[y] = x; 
                rank[x] ++; 
                } 
                else 
                pre[y] = x; 
                }  
void Kruskal(graph *g ) 
{ 
     int ans = 0,i,j,k = 0;  /*ans������¼������С����Ȩ��ֵ*/  
     int index; 
     int count = 0; /*��¼��ӡ�ߵ�����*/ 
     for(i = 0;i<(g->n);i ++) /*��ʼ������pre[x],rank[x]*/ 
     set(i); 
     for(i = 0;i<(g->n);i ++)  
     { 
           for(j = i + 1;j <(g->n);j ++) 
           { 
                 p[++k].str = i; 
                 p[k].end = j; 
                 p[k].dis = g->adj[i][j]; /*�Ȱ����г���֮���·�ο���һ����*/ 
           } 
     }
     for(i=0;i<k;i++) /*�����еı߰���С�����������*/ 
     { 
        index=i; 
        for(j=i+1;j<=k;j++) 
        if(p[j].dis <p[index].dis) 
        index=j; 
        temp=p[index]; 
        p[index]=p[i]; 
        p[i]=temp;  
        } 
        for(i = 0;i < k;i ++) 
        { 
           if(find(p[i].str) != find(p[i].end))/*���������������һ�𲻹���һ����·����ִ���������*/ 
           { 
              printf("\t��%d��·��Ϊ��%d--%d,ȨֵΪ%d\n",++count,p[i].str,p[i].end,p[i].dis);/*�������ߵ���㡢�յ��ӡ����*/ 
              ans += p[i].dis; /*˵������·��Ҫ��*/ 
              Union(p[i].str,p[i].end); 
           } 
        } 
        printf("\t�������г��еõ���С�������Ĵ���Ϊ: %d\n\n",ans); 
}  
void display( graph *g ) /*��ʾ���ɵ���С������*/ 
{ 
     if((g->n)==0) 
     { 
         printf("����û�г���֮�����Ϣ\n"); 
         return; 
     } 
     printf("�������г��еõ���С������Ϊ��\n\n\n"); 
     Kruskal(g); 
}  
void judge(graph *g )/*�ж��Ƿ��ܹ�������С������*/ 
{ 
     int close[100],low[100],i,j,ans = 0;/*close[j]��ʾ��j����Ķ��㣬low[j]��ʾ��j��̵ľ���*/ 
     int use[100]; 
     use[1] = 1;
     for(i = 1;i<(g->n);i++) 
     { 
           low[i]=g->adj[1][i]; /*��ʼ��*/ 
           close[i] = 1; 
           use[i] = 0; 
     }  
     for(i=0;i<(g->n);i++) 
     { 
         int min = 100000000,k = 0; 
         for(j=1;j<(g->n);j ++) 
         {
             if(use[j] == 0 && min > low[j])/*�ҵ���С��low[]ֵ������¼*/ 
             { 
                   min = low[j]; 
                   k = j; 
             } 
         } 
         for(j =1;j < (g->n);j ++) 
           { 
               if(use[j] == 0 && low[j] >( g->adj[k][j])) 
               { 
                  low[j] = g->adj[k][j]; /*�޸�low[]ֵ��close[]ֵ*/ 
                  close[j] = k; 
               } 
           }
           ans += g->adj[close[k]][k]; 
      } 
      if(ans >= 100000000) 
      printf("���ܹ�����С������\n"); 
      else 
      printf("�ܹ�����С������\n"); 
}  
int main( ) /*������*/ 
{ 
    graph *g=(graph*)malloc(sizeof(graph)); 
    while(1) { 
             switch( menu( ) ) 
             { 
                     case 1:create(g);break;/*���������Ϣ*/ 
                     case 2:judge(g);break;/*�ж��Ƿ��ܹ�������С������*/ 
                     case 3:display(g);break; /*��ʾ���ɵ���С������*/ 
                     case 4:exit(0); 
             } 
    } 
    return 0; 
}



