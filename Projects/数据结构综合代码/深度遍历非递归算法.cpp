#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20
#define maxsize 100
#define STACK_INIT_SIZE 100  
#define STACKINCREMENT 10
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
 typedef  struct { 
     VNode *base;
     int top;
     int stacksize;
}SqStack;  
 
void InitStack(SqStack &S){
	//构造空栈
	S.base=(VNode *)malloc(STACK_INIT_SIZE * sizeof(VNode));
	if (!S.base)
		return ;
	S.top=0;
	S.stacksize=STACK_INIT_SIZE;
}	  

int StackEmpty(SqStack S){
	//判空
	if(S.top==0)
		return 1;
	 return 0;
}

void Push(SqStack &S,VNode &G){
	//入栈
	if(S.top>=S.stacksize){
		S.base=(VNode *)realloc(S.base,(S.stacksize + STACKINCREMENT)*sizeof(VNode));
		if(!S.base)
			return;
		S.stacksize+=STACKINCREMENT;
	} 
	S.base[S.top++]=G.data;
}
void GetTop(SqStack S,VNode &G){
	if(S.top==0)
	return;
	G.data=S.base[S.top-1];
}
void Pop(SqStack &S,VNode &G){
	//出栈
	if(S.top==0)
		return;
	G.data=S.base[--S.top]; 
}




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

