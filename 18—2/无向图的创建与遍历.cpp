#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
int visited[MAX];
typedef char VertexType;
typedef int AdjMtrix[MAX][MAX];
typedef struct{
	int vexnum,arcnum;//节点数，边数 
	VertexType vexs[MAX];//结点 
	AdjMtrix arcs;//边关系 
}MGraph;

 typedef struct {
	int *base;
	int front;
	int rear;
	
}SqQueue;

void InitQueue(SqQueue &Q){
	//初始化队列
	Q.base=(int *)malloc(MAX * sizeof(int));
	if(!Q.base)
		exit(0); 
		
	Q.front=Q.rear=0; 
}

int QueueEmpty(SqQueue &Q){
	//判空操作 
	if (Q.front==Q.rear)
		return 1;
		
	return 0;
}

void EnQueue(SqQueue &Q,int &T){
	//入队操作 
	if((Q.rear+1)%MAX==Q.front)
		return;
	Q.base[Q.rear]=T;
	Q.rear=(Q.rear+1)%MAX;
}

void GetQueue(SqQueue Q,int &T)
{
	if(Q.front==Q.rear)
		return;
	T=Q.base[Q.front];
	
}
void DeQueue(SqQueue &Q,int &T){
	//出队列操作
	if(Q.front==Q.rear)
		return;
	T=Q.base[Q.front];
	Q.front=(Q.front+1)%MAX;
}

int LocateVex(MGraph &G,char v){
	for(int i=0;i<G.vexnum;i++)
		if(G.vexs[i]==v)
			return i;
	    return -1;
}
void CreateUDN(MGraph &G){
	//建立无向图的邻接矩阵
	char v1,v2;
	int i,j,k; 
	printf("输入当前顶点数:");
	scanf("%d",&G.vexnum);
	printf("输入当前弧数:");
	scanf("%d",&G.arcnum);
	printf("输入当前顶点向量:\n");
	getchar();
	for(i=0;i<G.vexnum;i++)
	{
		scanf("%c",&G.vexs[i]);
		getchar();
	}
	 for(i=0;i<G.vexnum;i++)
	 {
	 	for(j=0;j<G.vexnum;j++)
	 	{
			G.arcs[i][j]=0;
		}
	}
	printf("输入边:\n");
	for(k=0;k<G.arcnum;k++){
		printf("%d\t",k+1);
		scanf("%c %c",&v1,&v2);
		getchar();
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		G.arcs[i][j]=G.arcs[j][i]=1;
	}

}

void Output(MGraph G){
	int i,j;
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		{
			printf("%d",G.arcs[i][j]);
		}
		printf("\n");
	}
}

int FirstAdjVex(MGraph G,int v)
{
	int i,j;
	for(i=0;i<G.vexnum;i++)
//	{
		if(G.arcs[v][i]&&!visited[i])
		return i;
//	}
	return -1;
 } 
 
 int NextAdjVex(MGraph G,int v,int w)
 {
 	int i;
 	for(i=w+1;i<G.vexnum;i++)
 //	{
 		if(G.arcs[v][i]&&!visited[i])
		 return i;
//	}
	 return -1;
 }
 void DFS(MGraph G,int v)
 {
 	int w;
 	visited[v]=1;
 	printf("%c",G.vexs[v]);
 	for(w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w))
 	{
 		if(!visited[w])
 		DFS(G,w);
	 }
 }
 void DFSTraverse(MGraph G)
 {
 	int v;
 	for(v=0;v<G.vexnum;v++)
 	visited[v]=0;
 	for(v=0;v<G.vexnum;v++)
 	{
 		if(!visited[v])
 		DFS(G,v);
	 }
 }
 /*
//无向图的递归 
void DFS(MGraph G, int v){
//从第v个顶点出发递归地深度优先遍历图G

        int j;
        if(!visited[v])
        {
        	printf("%c",G.vexs[v]);
        	visited[v]=1;
		}
		for(j=0;j<G.vexnum;j++)
		{
			if(G.arcs[v][j]&&!visited[j])
			{
				DFS(G,j);
			}
		}
}
void DFSTraverse(MGraph G){
//对图G作深度优先遍历
int v;
  for (v=0; v<G.vexnum; ++v)  
      visited[v] = 0;  
  for (v=0; v<G.vexnum; ++v)   
       if(!visited[v]) 
	    DFS(G, v);
   }
 */
 void BFS(MGraph G)
{
	SqQueue Q;
 	int v,j;
 	for(v=0;v<G.vexnum;v++)
		visited[v]=0;
	InitQueue(Q);
	for(v=0;v<G.vexnum;v++)
	{
 	if(!visited[v]) //即为visited[v]==0，也就是未被访问过
 	{
  	//	cout<<G->vertex[v]<<" ";
  		printf("%c  ",G.vexs[v]);
	  	visited[v]=1;
  		EnQueue(Q,v); //被访问的顶点入队
 	}
 	while(!QueueEmpty(Q)) //队不空进循环
 	{
  
		GetQueue(Q,v);
  		DeQueue(Q,v);
  		for(j=0;j<G.vexnum;j++)
   		if (G.arcs[v][j]&&!visited[j])
   		{
    		printf("%c  ",G.vexs[j]);
			visited[j]=1; //标记为访问过
    		EnQueue(Q,j);   //被访问的顶点继续入队
   		}
 	}
 }
}

int main()
{
	MGraph G;
	CreateUDN(G);
	Output(G);
	printf("深度遍历："); 
	DFSTraverse(G);
	printf("\n广度遍历：");
	BFS(G);
	
	 
	return 0;
}
