#include<stdio.h> 
#include<stdlib.h>
#define  MAX 20
#define  addsize 10
typedef  int VertexType;
typedef struct ArcNode{
       int adjvex;//邻接点
       struct ArcNode *nextarc;
       //int *info;
}ArcNode,*ArcPtr;
typedef struct VNode{
       VertexType data;
       ArcNode *firstarc;
	   int tag;
}VNode,AdjList[MAX];
typedef struct{
       
       int vexnum,arcnum;//顶点数和边数
	   AdjList vertices;//顶点向量
}ALGraph;

//栈的有关函数
typedef struct{
	ArcPtr *base;
	int top;
	int stacksize;
}St;
typedef struct{
	int *base;
	int top;
	int stacksize;
}St1;
void InitStack(St &S){
	S.base=(ArcPtr*)malloc(MAX*sizeof(ArcPtr));
	S.top=0;
	S.stacksize=MAX;
}
void InitStack1(St1 &S){
	S.base=(int *)malloc(MAX*sizeof(int));
	S.top=0;
	S.stacksize=MAX;
}
int StackEmpty(St S){
	if(S.top==0)
		return 1;
	else
		return 0;
}
int StackEmpty1(St1 S){
	if(S.top==0)
		return 1;
	else
		return 0;
}
void Push(St &S,ArcPtr p){
	if(S.top>=S.stacksize){
		S.base=(ArcPtr *)realloc(S.base,(MAX+addsize)*sizeof(ArcPtr));
		S.stacksize+=addsize;
	}
	S.base[S.top++]=p;
}
void Push1(St1 &S,int p){
	if(S.top>=S.stacksize){
		S.base=(int *)realloc(S.base,(MAX+addsize)*sizeof(int));
		S.stacksize+=addsize;
	}
	S.base[S.top++]=p;
}
void Pop(St &S,ArcPtr &p){
	if(S.top==0)
		return ;
	p=S.base[--S.top];
}

void Pop1(St1 &S,int &p){
	if(S.top==0)
		return ;
	p=S.base[--S.top];
}
//队列的有关函数
typedef struct {
       ArcNode     *base;    //初始化动态分配空间
       int	   front;
       int	   rear;
} SqQueue;
void InitQueue(SqQueue &Q){
//构造一个空队列
    Q.base = (ArcNode *)malloc(MAX * sizeof(ArcNode));
    if ( ! Q.base)   exit(0);
   Q.front = Q.rear = 0;
}//InitQueue
int QueueEmpty(SqQueue Q)
{//判断队列是否是空队列
       if (Q.rear == Q.front )      return 1;
       return 0;
}
void EnQueue(SqQueue &Q, ArcNode e){
//插入元素e为Q的新的队尾元素
    if ((Q.rear+1)%MAX == Q.front) 
        exit(0);
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1) % MAX;
}
void DeQueue(SqQueue &Q, ArcNode &e)
{// 删除Q的队头元素, 并用e返回其值
    if(Q.front == Q.rear) return;
    e = Q.base[Q.front];
    Q.front = (Q.front+1) % MAX;
} 
int LocateVex(ALGraph G,int v){
	int i;
	 for( i=0; i<G.vexnum; i++)
		 if(G.vertices[i].data==v)
			 return i;
} 

//创建一个图       
void CreateAdjList(ALGraph  &G){
//根据输入的有向图G的顶点数及边数，建立图G的邻接表
	int i,j,k;
	char v1,v2;
	ArcNode  *s;
	ArcNode *p;
	printf("请输入图的顶点数和弧数:\n");
    scanf("%d%d",&G.vexnum, &G.arcnum);
	 printf("输入边表:\n");
    for( i=0; i<G.vexnum; i++) //初始化头结点
    { 
		scanf("%d",&G.vertices[i].data);
		G.vertices[i].tag=0;
        G.vertices[i].firstarc = NULL; 
	}
    for( k=0; k<G.arcnum;k++){
		  printf("输入一条弧:\n");//构造邻接表
          scanf( "%d",&v1); //输入一条边
		  scanf("%d",&v2);
          i = LocateVex( G, v1);    j = LocateVex( G, v2);   //确定v1和v2在G中的位置
          s = (ArcNode*)malloc(sizeof(ArcNode));
          s->adjvex = j;  s->nextarc = NULL;
          p = G.vertices[i].firstarc;
          if( !p) 
			  G.vertices[i].firstarc =  s;
          else {  
			  while(p->nextarc)  
				  p = p->nextarc;
                  p->nextarc = s;   }
    }
}//CreateAdjMatrix
//递归深度搜索
void DFS(ALGraph &G, int v){
//从第v个顶点出发递归地深度优先遍历图G
  ArcNode *w;
  G.vertices[v].tag=1;    printf("%d ",G.vertices[v].data);//访问第v个顶点
  while(1){
   for(w = G.vertices[v].firstarc;w;w = w->nextarc){
        if(G.vertices[w->adjvex].tag==0)   
			DFS(G,w->adjvex);
		}
   for(v=0;v<G.vexnum&& G.vertices[v].tag==1;v++);
   if(v==G.vexnum)
	   return ;
   else{
	   G.vertices[v].tag= 1;   printf(" %d ",G.vertices[v].data); //访问第v个顶点
   }
  }
}

/*
//非递归深度搜索
void DFS(ALGraph &G, int v){
    ArcNode *p;
	St S;
//从第v个顶点出发深度优先遍历图G
   InitStack(S);
   G.vertices[v].tag= 1;   printf("%d ",G.vertices[v].data); //访问第v个顶点
   p=G.vertices[v].firstarc;
   while(1){

     while( p || !StackEmpty(S))
   {   while(p)
            if (G.vertices[p->adjvex].tag==1)
                 p = p->nextarc;
            else
            {     printf("%3d",p->adjvex);    G.vertices[p->adjvex].tag=1;
                   Push(S, p);    p = G.vertices[p->adjvex].firstarc;
            }
        if ( !StackEmpty(S))
        {  Pop( S, p);   p = p->nextarc;  }
   }//while
   for(v=0;v<G.vexnum&& G.vertices[v].tag==1;v++);
   if(v==G.vexnum)
	   return ;
   else{
	   G.vertices[v].tag= 1;   printf(" %d ",G.vertices[v].data); //访问第v个顶点
	   p=G.vertices[v].firstarc;}
   }

}*/


//广度优先搜索
void BFSTraverse(ALGraph G){
//对图G作广度优先遍历 
  int v;
  ArcNode *w;
  SqQueue Q;
  InitQueue(Q);     //初始化队列
  for (v=0; v<G.vexnum; v++)
       if( G.vertices[v].tag==0)
       {    G.vertices[v].tag= 1;    printf("%3d ",G.vertices[v].data); //访问第v个顶点
             EnQueue( Q, *G.vertices[v].firstarc);
             while(!QueueEmpty(Q))
             {     DeQueue(Q, *G.vertices[v].firstarc);
                    for(w = G.vertices[v].firstarc; w; w = w->nextarc)
                          if( G.vertices[w->adjvex].tag==0)    
                          {    G.vertices[w->adjvex].tag=1;   printf("%3d",G.vertices[w->adjvex].data); 
                                EnQueue( Q, *w);
}//if }//while}//if}//BFSTraverse
void FindInDegree(ALGraph G,int indegree[])
{

	int i;
    ArcNode *p;
	for(i=0;i<G.vexnum;i++)
indegree[i]=0;
for(i=0;i<G.vexnum;i++){
p=G.vertices[i].firstarc;
		while(p){
indegree[p->adjvex]++;
				p=p->nextarc;}}}
//拓扑排序

void TopologicalSort(ALGraph G){
	  St1 S;
      int indegree[MAX];
	  int i,count,k;
	  ArcNode *p;
      FindInDegree( G, indegree) ;   //对各顶点求入度
      InitStack1(S) ;
      for( i = 0; i <G.vexnum;i++ )  //将入度为0的顶点压入栈
          if( !indegree[i] )  Push1( S, i );
      count = 0; while( !StackEmpty1( S ))
      {    Pop1( S, i );    printf( "i=%d,data=%d\n",i, G.vertices[i].data );   count++;
            for( p = G.vertices[i].firstarc; p; p = p->nextarc )
            {     k = p->adjvex;
                   if ( ! (--indegree[k] ))  Push1( S, k );
            }//for
      }//while
      if( count < G.vexnum )     {  printf("该图有回路\n");   exit(0);  }
}//  TopologicalSort

