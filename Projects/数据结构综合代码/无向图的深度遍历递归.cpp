#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
int visited[MAX];
typedef char VertexType;
typedef int AdjMtrix[MAX][MAX];
typedef struct{
	int vexnum,arcnum;
	VertexType vexs[MAX];
	AdjMtrix arcs;
}MGraph;

int LocateVex(MGraph &G,char v){
	for(int i=0;i<G.vexnum;i++)
		if(G.vexs[i]==v)
			return i;
	    return -1;
}
void CreateUDN(MGraph &G){
	//��������ͼ���ڽӾ���
	char v1,v2;
	int i,j,k; 
	printf("���뵱ǰ������:");
	scanf("%d",&G.vexnum);
	printf("���뵱ǰ����:");
	scanf("%d",&G.arcnum);
	printf("���뵱ǰ��������:\n");
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
	printf("�����:\n");
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
//����ͼ�ĵݹ� 
void DFS(MGraph G, int v){
//�ӵ�v����������ݹ��������ȱ���ͼG

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
//��ͼG��������ȱ���
int v;
  for (v=0; v<G.vexnum; ++v)  
      visited[v] = 0;  
  for (v=0; v<G.vexnum; ++v)   
       if(!visited[v]) 
	    DFS(G, v);
   }
 */
int main()
{
	MGraph G;
	CreateUDN(G);
	Output(G);
	DFSTraverse(G);
	return 0;
}
