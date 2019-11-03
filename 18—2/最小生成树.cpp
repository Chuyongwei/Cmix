#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>  
#define max 20               //城市间边数
#define MAX_LNT 10         //城市数
#define INF 32627            //两个城市间无直接路径，用大数32627表示
typedef struct node          /*构造一个结构体，两个城市可以看成起点和终点，之间的道路可以看成一个边*/ 
{
        int str;             /*起点*/ 
        int end;            /*终点*/ 
        int dis;            /*距离*/ 
        }node;  
node p[max],temp;          /*p记录城市信息*/  
typedef struct{             //邻接矩阵存储图结构
int vexs[MAX_LNT];        //数组用于存储城市数
int adj[max+1][max+1];      //图的邻接矩阵表示
int n,e;                    //n代表城市数，e代表城市间边数
}graph; 
int pre[100],rank[100];        /*用于判断是否构成回路*/  
//int arcs[MAX_LNT][MAX_LNT];/*n表示城市个数，arcs[][]记录城市间权值*/ 
int menu()                /*菜单函数*/ 
{ 
    int m; 
    printf("            求最小生成树              \n"); 
    printf("  ************************************\n\n"); 
    printf("  1:输入城市之间的信息\n"); 
    printf("  2:判断是否能构成一个最小生成树\n"); 
    printf("  3:遍历所有城市生成最小生成树\n"); 
    printf("  4:退出\n"); 
    printf(" ************************************\n\n"); 
    printf("  请输入所选功能(1-4):"); 
    scanf("%d",&m);  
    return m; 
    } 
    void create(graph *g) /*输入城市信息*/ 
    { 
         int i,j,k; 
         printf("输入城市数为:"); 
         scanf("%d",&(g->n)); 
         printf("\n"); 
         printf("输入n个城市间边数为:");  
         scanf("%d",&(g->e)); 
         printf("输入城市的各个顶点为:");  
         for(i=0;i<(g->n);i++) 
         scanf("%d",&(g->vexs[i])); //顶点存入数组vexs[] 
         printf("输入%d条边，建立邻接矩阵",(g->e)); 
         printf("\n"); 
         for(i=0;i<(g->n);i++) //初始化邻接矩阵
         { 
             for(j=0;j<(g->n);j++) 
             { 
                 if(i==j) 
                 g->adj[i][j]=0; 
                 else 
                 g->adj[i][j]=INF; 
             } 
         } 
         printf("请输入具有邻接关系的两个顶点在矩阵中所在的行与列及权值:\n"); 
         for(k=0;k<(g->e);k++) //有g->e条边，即有g->e个权值
         { 
            scanf("%d,%d",&i,&j); 
            scanf("%d",&g->adj[i][j]); 
            }
            for(i=0;i<(g->n);i++) 
            for(j=0;j<(g->n);j++) 
            g->adj[j][i]=g->adj[i][j]; 
            printf(" 图的邻接矩阵如下\n"); 
            for(i=0;i<(g->n);i++) 
            //输出邻接矩阵g 
            { 
               for(j=0;j<(g->n);j++) 
               if(g->adj[i][j]==INF) 
               printf("\t%3s","∞"); 
               else 
               printf("\t%3d",g->adj[i][j]); 
               printf("\n"); 
            } 
} 
/*下面三个函数作用是检验当一条边添加进去，是否会产生回路*/ 
void set(int x)/*初始化*/ 
{ 
     pre[x] = x;
     rank[x] = 0; 
     } 
     int find(int x)/*找到这个点的祖先*/ 
     { 
         if(x != pre[x])  
         pre[x] = find(pre[x]); 
         return pre[x]; 
         } 
void Union(int x,int y)/*将这两个添加到一个集合里去*/ 
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
     int ans = 0,i,j,k = 0;  /*ans用来记录生成最小树的权总值*/  
     int index; 
     int count = 0; /*记录打印边的条数*/ 
     for(i = 0;i<(g->n);i ++) /*初始化数组pre[x],rank[x]*/ 
     set(i); 
     for(i = 0;i<(g->n);i ++)  
     { 
           for(j = i + 1;j <(g->n);j ++) 
           { 
                 p[++k].str = i; 
                 p[k].end = j; 
                 p[k].dis = g->adj[i][j]; /*先把所有城市之间的路段看成一个边*/ 
           } 
     }
     for(i=0;i<k;i++) /*把所有的边按从小到大进行排序*/ 
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
           if(find(p[i].str) != find(p[i].end))/*如果这两点连接在一起不构成一个回路，则执行下面操作*/ 
           { 
              printf("\t第%d条路段为：%d--%d,权值为%d\n",++count,p[i].str,p[i].end,p[i].dis);/*将这条边的起点、终点打印出来*/ 
              ans += p[i].dis; /*说明这条路段要用*/ 
              Union(p[i].str,p[i].end); 
           } 
        } 
        printf("\t遍历所有城市得到最小生成树的代价为: %d\n\n",ans); 
}  
void display( graph *g ) /*显示生成的最小生成树*/ 
{ 
     if((g->n)==0) 
     { 
         printf("这里没有城市之间的信息\n"); 
         return; 
     } 
     printf("遍历所有城市得到最小生成树为：\n\n\n"); 
     Kruskal(g); 
}  
void judge(graph *g )/*判断是否能够生成最小生成树*/ 
{ 
     int close[100],low[100],i,j,ans = 0;/*close[j]表示离j最近的顶点，low[j]表示离j最短的距离*/ 
     int use[100]; 
     use[1] = 1;
     for(i = 1;i<(g->n);i++) 
     { 
           low[i]=g->adj[1][i]; /*初始化*/ 
           close[i] = 1; 
           use[i] = 0; 
     }  
     for(i=0;i<(g->n);i++) 
     { 
         int min = 100000000,k = 0; 
         for(j=1;j<(g->n);j ++) 
         {
             if(use[j] == 0 && min > low[j])/*找到最小的low[]值，并记录*/ 
             { 
                   min = low[j]; 
                   k = j; 
             } 
         } 
         for(j =1;j < (g->n);j ++) 
           { 
               if(use[j] == 0 && low[j] >( g->adj[k][j])) 
               { 
                  low[j] = g->adj[k][j]; /*修改low[]值和close[]值*/ 
                  close[j] = k; 
               } 
           }
           ans += g->adj[close[k]][k]; 
      } 
      if(ans >= 100000000) 
      printf("不能构成最小生成树\n"); 
      else 
      printf("能构成最小生成树\n"); 
}  
int main( ) /*主函数*/ 
{ 
    graph *g=(graph*)malloc(sizeof(graph)); 
    while(1) { 
             switch( menu( ) ) 
             { 
                     case 1:create(g);break;/*输入城市信息*/ 
                     case 2:judge(g);break;/*判断是否能够生成最小生成树*/ 
                     case 3:display(g);break; /*显示生成的最小生成树*/ 
                     case 4:exit(0); 
             } 
    } 
    return 0; 
}



