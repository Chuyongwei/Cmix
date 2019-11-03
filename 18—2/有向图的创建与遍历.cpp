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
 
 typedef struct {
	int *base;
	int front;
	int rear;
	
}SqQueue;




void InitQueue(SqQueue &Q){
	//��ʼ������
	Q.base=(int *)malloc(MAX * sizeof(int));
	if(!Q.base)
		exit(0); 
		
	Q.front=Q.rear=0; 
}

int QueueEmpty(SqQueue &Q){
	//�пղ��� 
	if (Q.front==Q.rear)
		return 1;
		
	return 0;
}

void EnQueue(SqQueue &Q,int &T){
	//��Ӳ��� 
	if((Q.rear+1)%MAX==Q.front)
		return;
	Q.base[Q.rear]=T;
	Q.rear=(Q.rear+1)%MAX;
}

void DeQueue(SqQueue &Q,int &T){
	//�����в���
	if(Q.front==Q.rear)
		return;
	T=Q.base[Q.front];
	Q.front=(Q.front+1)%MAX; 
}


int visit[maxsize];
int LocateVex(ALGraph G,char v){
 	for(int i=0;i<G.vexnum;i++)
 		if(G.vertices[i].data==v)
 			return i;
 		return -1;
 }
void CreateList(ALGraph &G){
 	//����ͼ���ڽӱ�
 	int i,j,k;
 	char v1,v2;
 	ArcNode *s,*p,*t;
	 printf("����ͼ�Ķ�����:");
	 scanf("%d",&G.vexnum);
	 printf("����ͼ�ı���:");
	 scanf("%d",&G.arcnum);
	 printf("���붥����Ϣ:\n");
	 for(i=0;i<G.vexnum;i++){
	 	scanf("%c",&G.vertices[i].data);
	 	G.vertices[i].firstarc=NULL;
	 }
	 for(k=0;k<G.arcnum;k++){
	 	printf("�����%d����:\n",k+1);
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


 
void DFS(ALGraph G,int v)
{
	//��ͼ��ȱ���
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
void BFSTraverse(ALGraph G)
{
	int i;
	ArcNode *p;
	SqQueue Q;
	for(i=0;i<G.vexnum;i++)
		visit[i]=0;
	InitQueue(Q);
	for(i=0;i<G.vexnum;i++)
	{
		if(!visit[i])
		{
			
			printf("%c ",G.vertices[i].data);
			visit[i]=1;
			EnQueue(Q,i);
			while(!QueueEmpty(Q)){
				DeQueue(Q,i);				
				p=G.vertices[i].firstarc;
				while(p)
				{
					if(!visit[p->adjvex])
					{
						visit[p->adjvex]=1;
						printf("%c",G.vertices[p->adjvex].data);
						EnQueue(Q,p->adjvex);
					}
					p=p->nextarc;
				}
			}
		}
	}
}
int main(){
	ALGraph G;
	int v;
	CreateList(G);
	DFStraverse(G); 
	Output(G);
	return 0;
}
