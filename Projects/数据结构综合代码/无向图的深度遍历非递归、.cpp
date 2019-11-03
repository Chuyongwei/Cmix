#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_VERTEX_NUM  10
#define STACKINIT_SIZE 100
#define STACKINCREASE 10
#define MAX 20
int visited[MAX]; 
typedef int SElemType;
typedef char VertexType;
typedef int AdjMtrix[MAX][MAX];
typedef struct{
	int vexnum,arcnum;
	VertexType vexs[MAX];
	AdjMtrix arcs;
}MGraph;


typedef struct
{
	int *base;
	int top;
	int stacksize;
}SqStack;

void InitStack(SqStack &s)
{
//初始化
    s.base=(int*)malloc(STACKINIT_SIZE*sizeof(int));
	if(!s.base)
		return;
	s.top=0;
	s.stacksize=STACKINIT_SIZE;
}

int Stackempty(SqStack s)
//判空
{
    if(s.top==0)
		return 1;
	return 0;
}

void Push(SqStack &s,int e)
//入栈
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

void Pop(SqStack &s,int &e)
//出栈
{
    if(s.top==0)
		return ;
	e=s.base[--s.top];
}


void Gettop(SqStack &s,int &e)
//取栈顶元素
{
    if(s.top==0)
		return ;
	e=s.base[s.top-1];
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
/*无向图的递归 
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
       if(!visited[v])  DFS(G, v);
   }

*/ 


void DFSTraverse(MGraph G)
{
	//非递归
	int i,j,flag;
	//stack<int > S;
	SqStack S;
	for(i=0;i<MAX;i++)
	{
		visited[i]=0;
	}
	i=0;
//	S.push(i);
	Push(S,i);
	printf("%c ",G.vexs[i]);
	visited[i]=1;
	while(!Stackempty(S)||i>=0)
	{
		while(i>=0)
		{
			if(visited[i])
			{
				flag=0;
				for( j=0;j<G.vexnum;j++ )
				{
					if(G.arcs[i][j]&&!visited[j])
					{
						i=j;
						//S.push(i);
						Push(S,i);
						flag=1;
						break;
					}
				}
				if(!flag)
				{
					i=-1;
				}
			}
			else
			{
				printf("%c ",G.vexs[i]);
				visited[i]=1;
			}
		}	
		if(!Stackempty(S))
		{
	//		i=S.top();
			//S.pop();
			Gettop(S,i);
			Pop(S,i);
		}
	}
	
	
}
	
	 

int main()
{
	MGraph G;
	CreateUDN(G);
	Output(G);
	DFSTraverse(G);
	return 0;
}
