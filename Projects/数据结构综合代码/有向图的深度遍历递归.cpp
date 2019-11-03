#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20
#define maxsize 100
typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
}ArcNode;
typedef struct VNode{
	char data;
	ArcNode *firstarc;
}VNode,AdjList[MAX];
typedef struct {
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;
 
int visit[maxsize];
int LocateVex(ALGraph G,char v){
 	for(int i=0;i<G.vexnum;i++)
 		if(G.vertices[i].data==v)
 			return i;
 		return -1;
 }
void CreateList(ALGraph &G){
 	//建立图的邻接表
 	int i,j,k;
 	char v1,v2;
 	ArcNode *s,*p,*t;
	 printf("输入图的顶点数:");
	 scanf("%d",&G.vexnum);
	 printf("输入图的边数:");
	 scanf("%d",&G.arcnum);
	 printf("输入顶点信息:\n");
	 for(i=0;i<G.vexnum;i++){
	 	scanf("%c",&G.vertices[i].data);
	 	G.vertices[i].firstarc=NULL;
	 }
	 for(k=0;k<G.arcnum;k++){
	 	printf("输入第%d条边:\n",k+1);
	 	scanf("%c%c",&v1,&v2);
	 	getchar();
	 	i=LocateVex(G,v1);
	 	j=LocateVex(G,v2);
	 	s=(ArcNode *)malloc(sizeof(ArcNode));
	 	s->adjvex=j;
	 	s->nextarc=NULL;
	 	p=G.vertices[i].firstarc;
	 	if(!p)
	 	G.vertices[i].firstarc=s;
	 	else{
	 	while(p->nextarc)
	 		p=p->nextarc;
	 		p->nextarc=s;
	 		} 
	 }
}

int FirstAdjVex(ALGraph G,int v){
	for(int u=0;u<G.vexnum;u++)
	if(G.)
}
void DFS(ALGraph G,int v)
{
	//对图深度遍历
	ArcNode *p;
	int w;
	visit[v]=1;
	printf("%2c",G.vertices[v].data); 
	for(p=G.vertices[v].firstarc;p;p=p->nextarc){
		w=p->adjvex;
		if(visit[w]!=1)
		DFS(G,w);
	}
	
}
void DFStraverse(ALGraph G)
{
	int v;
	for(v=0;v<G.vexnum;v++)
	visit[v]=0;
	for(v=0;v<G.vexnum;v++)
	if(visit[v]!=1)
	DFS(G,v); 
}
void Output(ALGraph G){
	int i;
	for(i=0;i<G.vexnum;i++)
	printf("%5c",G.vertices[i].data);
}
int main(){
	ALGraph G;
	int v;
	CreateList(G);
	DFStraverse(G); 
	Output(G);
	return 0;
}
