#include "stdio.h"

#define MAX_VERTEX_NUM 10

#include "conio.h"

#include "stdlib.h"

typedef char VertexType;

typedef struct ArcNode{
       int adjvex;
       struct ArcNode *nextarc;
       int info;
}ArcNode;  //表结点类型

typedef struct VNode{
       VertexType data;
       ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM]; //头结点

typedef struct{
       AdjList vertices;  //邻接表
       int vexnum,arcnum;
}ALGraph;

int visited[MAX_VERTEX_NUM];

int LocateVex(ALGraph G,char u)
    {
       int i;
       for (i=0;i<G.vexnum;i++)
           {
		    if(u==G.vertices[i].data) 
			return i; 
			}
   /*    if (i==G.vexnum) 
	   {
	   	printf("Error u!\n");
	   	exit(1);
	   }*/
       return 0;
    }
    
void CreateALGraph_adjlist(ALGraph &G)
  {    
       int i,j,k,w; 
       char v1,v2,enter;
       ArcNode *p;
       printf("Input vexnum & arcnum:\n");
       scanf("%d",&G.vexnum);
       scanf("%d",&G.arcnum);
       printf("Input Vertices:\n");
       for (i=0;i<G.vexnum;i++)
              {    
			   scanf("%c%c",&enter,&G.vertices[i].data);//注意点，解说
                     G.vertices[i].firstarc=NULL;
              }//for
printf("Input Arcs(v1,v2,w)以回车分开各个数据:\n");
   for (k=0;k<G.arcnum;k++)
       {
              scanf("%c%c",&enter,&v1);
              scanf("%c%c",&enter,&v2);
              scanf("%d",&w);
              i=LocateVex(G,v1);
              j=LocateVex(G,v2);
              p=(ArcNode*)malloc(sizeof(ArcNode));
              p->adjvex=j;  
              p->info = w;
              p->nextarc=G.vertices[i].firstarc;
              G.vertices[i].firstarc=p;
       }//for     
   return;
}//CreateALGraph_adjlist

void DFS(ALGraph &G, int v)
{
   ArcNode *p;
   printf("%c",G.vertices[v].data);
   visited[v]=1;
    p=G.vertices[v].firstarc;
    while (p)
      {  
	  if (!visited[p->adjvex]) 
	  DFS(G,p->adjvex);
      p=p->nextarc;
      }
 }   //从第v个顶点出发DFS

void DFSTraverse(ALGraph &G)
 {
     for (int v=0;v<G.vexnum;++v)
              visited[v]=0;
     for (int v=0;v<G.vexnum;++v)
              if (!visited[v]) 
			  DFS(G,v);
}//DFSTraverse

int main()
{
ALGraph G;
CreateALGraph_adjlist(G);
DFSTraverse(G);
return 0;
}
