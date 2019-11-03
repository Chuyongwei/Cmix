#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_VERTEX_NUM  10
#define STACKINIT_SIZE 100
#define STACKINCREASE 10
typedef struct
{
	int *base;
	int top;
	int stacksize;
}Sqstack;

void InitStack(Sqstack &s)
{
//��ʼ��
    s.base=(int*)malloc(STACKINIT_SIZE*sizeof(int));
	if(!s.base)
		return;
	s.top=0;
	s.stacksize=STACKINIT_SIZE;
}

int Stackempty(Sqstack s)
//�п�
{
    if(s.top==0)
		return 1;
	return 0;
}

void Push(Sqstack &s,int e)
//��ջ
{
    if(s.top>=s.stacksize)
	{
		s.base=(int*)realloc(s.base,(s.stacksize+STACKINCREASE)*sizeof(int));
		if(!s.base)
			return;
	    s.stacksize+=STACKINCREASE;
	}
	s.base[s.top++]=e;
}

void Pop(Sqstack &s,int &e)
//��ջ
{
    if(s.top==0)
		return ;
	e=s.base[--s.top];
}


void Gettop(Sqstack &s,int &e)
//ȡջ��Ԫ��
{
    if(s.top==0)
		return ;
	e=s.base[s.top-1];
}


typedef struct ArcNode{
    int adjvex;
    struct  ArcNode *nextarc;
}ArcNode,*ANode;

typedef struct VNode{
    char data;
    ArcNode *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct{
    AdjList vertices;
    int vexnum, arcnum;
}ALGraph;      

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
    {//�����   	
    
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
void FindInDegree(ALGraph G,int indegree[]){
	int i;
	ArcNode *p;
	for(i=0;i<G.vexnum;i++)
	{
		p=G.vertices[i].firstarc;
		while(p){
			indegree[p->adjvex]++;
			p=p->nextarc;
		}
	}
}

void TopologicalSort(ALGraph G)
{
	Sqstack S;
	int i,count,j;
	int indegree[100]={0};
	ArcNode *p;
	FindInDegree(G,indegree);
	InitStack(S);
	printf("�����������:\n");
	for(i=0;i<G.vexnum;i++)
	if(!indegree[i])
	Push(S,i);
	count=0;
	while(!Stackempty(S)){
		Pop(S,i);
		printf("%d %c\n",i,G.vertices[i].data);
		count++;
		for(p=G.vertices[i].firstarc;p;p=p->nextarc){
			j=p->adjvex;
			if(!--indegree[j])
			Push(S,j);
		}
	}
	if(count<G.vexnum)
	{
		printf("��ͼ�л�·\n");
		exit(0);
	}
}

int main(){
	ALGraph G;
	CreateALGraph(G);
	TopologicalSort(G);
	return 0;
} 
