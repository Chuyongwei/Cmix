#include<stdio.h> 
#include<stdlib.h> 
#define MAXV 100 
typedef struct {  
	int no; 
	int info; 
 }vertextype;        
typedef struct {   
	int num;      
	int edges[MAXV][MAXV];   
	// vertextype vexs[MAXV];
 }mgraph;   
struct arcnode {     
	int adjvex;     
	int info;      
	struct arcnode *nextarc;   
   };  
struct vexnode {     
	int  data;     
	struct arcnode *firstarc;    
             };  
struct graph {   
	int vexnum,arcnum;  
	vexnode  vexpex[100];
 };     
 graph *creatgraph() 
 {     
	 int i,s,d;  
	 struct graph *g;  
	 struct arcnode *p,*q;  
	 g = (struct graph *)malloc(sizeof(struct graph));  
	 printf("请输入节点数和弧数:");      
	 scanf("%d%d", &g->vexnum, &g->arcnum);  
	 for(i=1; i<=g->vexnum; i++)  
	 {    
		 printf("第 %d 个节点信息:",i);  
		 scanf("%d", &g->vexpex[i].data);
		 g->vexpex[i].firstarc = NULL; 
	 }   
	 for(i=1; i<=g->arcnum; i++)
	 {    
		 p = (struct arcnode *)malloc(sizeof(struct arcnode));
		 q = (struct arcnode *)malloc(sizeof(struct arcnode));  
		 printf("第 %d 条弧的弧尾和弧头的位置:",i);  
		 scanf("%d%d",&s,&d);   
		 p->adjvex = d;  
		 p->info = g->vexpex[d].data;  
		 p->nextarc = g->vexpex[s].firstarc;  
		 g->vexpex[s].firstarc = p;    
		 q->adjvex = s;   
		 q->info = g->vexpex[s].data; 
		 q->nextarc = g->vexpex[d].firstarc; 
		 g->vexpex[d].firstarc = q;  
	 }  
	 return g;               
	 //return graph!
 } 
 void changeto(graph *G, mgraph &g) 
 {   
	 int i,j;  
	 arcnode *m;   
	 g.num = G->vexnum;  
	 for(i = 1; i<=G->vexnum; i++)   
		 for(j = 1; j<=G->vexnum; j++)   
			 g.edges[i][j] = 0;   
 for(i = 1; i<=G->vexnum; i++) 
  {    
	  m = G->vexpex[i].firstarc;    
	  while(m)   
	  {    
		  g.edges[i][m->adjvex] = 1;        
		  m = m->nextarc;   
 }  
 } 
}  
 void printtu(struct graph *g,int n) {  
	 int i;   
	 arcnode *p; 
	 printf("图的邻接表表示为：\n");  
	 for(i=1; i<=n; i++)  
	 {    
		 printf(" [%d,%d]-->", i, g->vexpex[i].data);  
		 p = g->vexpex[i].firstarc;   
		 while(p != NULL)   
		 {      
			 printf("[%d,%d]-->", p->adjvex, p->info);   
			 p = p->nextarc;   
}   
		 printf("^\n"); 
 } 
}  
 void printftu2(mgraph g) {   
	 int i,j;   
	 printf("图的邻接矩阵表示为：\n");  
	 for(i = 1; i<=g.num; i++)  
	 {   
		 for(j = 1;j <= g.num; j++)  
			 printf("%d ",g.edges[i][j]);  
		 printf("\n"); 
 } 
 } 
 int main() 
 {    
	 graph *G;  
	 mgraph g;  
	 G = creatgraph(); 
	 printtu(G,G->vexnum);
	 printf("交换后是::\n");
	 changeto(G, g); 
	 printftu2(g); 
	 system("PAUSE"); 
 } 



