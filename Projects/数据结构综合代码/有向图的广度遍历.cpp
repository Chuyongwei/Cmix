//ͼ�Ĺ�����ȱ���
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
int visited[MAX];
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

int LocateVex(ALGraph G,char v){
 	for(int i=0;i<G.vexnum;i++)
 		if(G.vertices[i].data==v)
 			return i;
 		
	return -1;
 }
void CreateALGraph(ALGraph &G){
 	//����ͼ���ڽӱ�
 	int i,j,k;
 	char v1,v2;
 	ArcNode *s,*p;
	 printf("����ͼ�Ķ�����:");
	 scanf("%d",&G.vexnum);
	 printf("����ͼ�Ļ���:");
	 scanf("%d",&G.arcnum);
	 getchar();
	 printf("���붥��:\n");
	 for(i=0;i<G.vexnum;i++){
	 	scanf("%c",&G.vertices[i].data);
		getchar();
	 	G.vertices[i].firstarc=NULL;
	 }
	 printf("��������֮��ı�:\n");
	 for(k=0;k<G.arcnum;k++)  
    {   	
        scanf("%c %c",&v1,&v2);  
        getchar(); 
        i=LocateVex(G,v1);  
        j=LocateVex(G,v2);  
        s= (ArcNode *)malloc(sizeof(ArcNode));  
        s->adjvex=j;  
        s->nextarc=NULL;  
        p=G.vertices[i].firstarc;  
        if(!p)  
        {  
        
            G.vertices[i].firstarc = s;  
        }  
        else  
        {  
            while(p->nextarc)  
                p=p->nextarc;  
            p->nextarc=s;  
        }  
    }  
}

void BFSTraverse(ALGraph G)
{
	int i;
	ArcNode *p;
	SqQueue Q;
	for(i=0;i<G.vexnum;i++)
		visited[i]=0;
	InitQueue(Q);
	for(i=0;i<G.vexnum;i++)
	{
		if(!visited[i])
		{
			
			printf("%c ",G.vertices[i].data);
			visited[i]=1;
			EnQueue(Q,i);
			while(!QueueEmpty(Q)){
				DeQueue(Q,i);				
				p=G.vertices[i].firstarc;
				while(p)
				{
					if(!visited[p->adjvex])
					{
						visited[p->adjvex]=1;
						printf("%c",G.vertices[p->adjvex].data);
						EnQueue(Q,p->adjvex);
					}
					p=p->nextarc;
				}
			}
		}
	}
}
 int main()
 {
 	ALGraph G;
 	
 	CreateALGraph(G);
 	BFSTraverse(G);
 	
 	return 0;
 } 
