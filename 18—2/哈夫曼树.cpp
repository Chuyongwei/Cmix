#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FLASE 0
#define TURE 1
#define ERROR 0
#define OK 1
typedef int TElemType;
typedef int Status;
typedef struct{
	 int weight;
	 int parent,lchild,rchild;
}HTNode,*HuffmanTree,*BiTree;

typedef char* *HuffmanCode;

void Select(HuffmanTree &HT,int n,int &s1,int &s2){
	//设0为初始，仅为循环开始 
	HuffmanTree p;
	int j=1;
	s1=0;s2=0;
	for(;j<n;j++)
	{
		if(HT[j].parent!=0) break;
		if(HT[j].weight<HT[s2].weight)
		{
			if(HT[j].weight<HT[s1].weight)s1=j,s2=s1;
			else s2=j;
		}
		 
	}
	HT[s1].parent = 1;
	HT[s2].parent = 1;
} 
void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n)
{
	if(n<=1)return;
	int m = 2*n-1,i,s1,s2;
	HuffmanTree p;
	HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));
	for(p = HT,i = 1;i<n;++i,++p,++w)  *p = {*w,0,0,0};
	for(;i<m;++i,++p) *p={0,0,0,0};
	for(i=n+1;i<=m;++i){
		Select(HT,i-1,s1,s2);
		HT[s1].parent  = i; HT[s2].parent = i;
		HT[i].lchild = s1;HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	//
	HC = (HuffmanCode)malloc((n+1)*sizeof(char*));
	char *cd = (char*)malloc(n*sizeof(char));
	cd[n-1] = '\0';
	int start,c,f;
	for(i = 1;i<=n;++i){
		start = n-1;
		for(c =i,f = HT[i].parent;f!=0;c=f,f=HT[f].parent)
		     if(HT[f].lchild==c) cd[--start] = '\0';
		    else cd[--start] = '1';
		HC[i] = (char*)malloc((n-start) * sizeof(char));
		strcpy(HC[i],&cd[start]);
	} 
	free(cd);
} 

Status PreOrderTraverse(BiTree &T,int i){
	//二叉树先序遍历。visit为PrintfElement(TElemType e) 
	TElemType m;
	if(i<5)
	{
		int j = T[i].lchild;
		printf("%d",T[i].weight);
		PreOrderTraverse(T,j);
		j = T[i].rchild;
		PreOrderTraverse(T,j);
	}else return OK;
}

Status InOrderTraverse(BiTree &T,int i)
{//中序遍历  
	if(T[i].lchild)
	{
		int j = T[i].lchild;
	    PreOrderTraverse(T,j);
    }
		printf("%c",T[i].weight);
		PreOrderTraverse(T,j);
	}
}

int main()
{
	int w[5]={1,2,3,4,5};
	HuffmanCode HC;
	HuffmanTree HT;
	HuffmanCoding(HT,HC,w,5);
	PreOrderTraverse(HT,1);
	InOrderTraverse(HT,1);
	return 0;
}
