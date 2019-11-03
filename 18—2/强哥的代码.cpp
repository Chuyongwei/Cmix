#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<malloc.h>
using namespace std;

typedef struct{
	int weight;
	int parent,lchid,rchild;
}HTnode,*HuffmanTree;

typedef char * * HufferCode;

void Select(HuffmanTree &HT,int n,int &s1,int &s2)
{
	int i,min;
	for(i = 1;i <= n;i++)
	{
		if(HT[i].parent == 0)
		{
			min = i;
			i =n+1;
		}
	}
	for(int i = 1;i<=n;i++)
	{
		if(HT[i].parent == 0)
		{
			if(HT[i].weight<HT[min].weight)
			min = i;
		}
	}
	s1 = min;
	for(int i = 1;i <=n;i++)
	{
		if(HT[i].parent == 0 && i!=s1)
		{
			min = i;
			i =n+1;
		}
	}
	
	for(int i = 1;i<=n;i++)
	{
		if(HT[i].parent == 0&&i!=s1)
		{
			if(HT[i].weight<HT[min].weight)
			min = i;
		}
	}
	s2 = min;
}

//构建赫尔曼树 
void CreatHuffmantree(HuffmanTree& HT,int n)
{
	if(n<=1)
	{
		return;
	}
	int i; 
	int m = 2 * n-1;//0号单元没有使用 从1开始 
	int s1;
	int s2;
	HT = (HuffmanTree)malloc((m+1)* sizeof(HTnode));
	for(i = 1;i <= m;i++)
	{
		HT[i].lchid = 0;
		HT[i].rchild = 0;
		HT[i].parent = 0;
	 }
	 for(i = 1;i <=n;i++)
	 {
	 	scanf("%d",&HT[i].weight); 
	 } 
	 //构建HUffman树
	 for(i = n+1;i<=m;++i)
	{
		 	Select(HT,i-1,s1,s2);
			 HT[s1].parent = i;
			 HT[s2].parent = i;
			 HT[i].lchid = s1;
			 HT[i].rchild = s2;
			 HT[i].weight = HT[s1].weight+HT[s2].weight;
	} 
}

void CreatHuffmanCode(HuffmanTree &HT,HufferCode &HC,int n)
{
	int i;
	char *cd;
	int start;
	HC = (HufferCode)malloc((n+1) * sizeof(char*));
	//存放编码 
	cd = (char*)malloc(n*sizeof(char));
	cd[n-1] ='\0';
	for(i = 1;i <= n;++i)
	{
		start = n-1;
		int c = i;
		int f = HT[i].parent;
		while(f !=0)
		{
		--start;
		if(HT[f].lchid == c)
		cd[start] = '0';
		else
		cd[start] = '1';
		c = f;
		f = HT[f].parent; 
		}
	   	HC[i] = (char *)malloc((n-start)*sizeof(char));
		strcpy(HC[i],&cd[start]);
	}
	free(cd);
} 

int main()
{
	HuffmanTree HT;
	HufferCode HC;
	int sum = 0;
	int i;
	int a;
	int b;
	int n;
	scanf("%d",&n);
	CreatHuffmantree(HT,n);
	CreatHuffmanCode(HT,HC,n);
	for(i = 1;i <= n;++i)
	{
		a = strlen(HC[i])*HT[i].weight;
		sum = sum + a;
//		printf("%s\n",HC[i]);
	}
	printf("%d",sum);
	return 0;
}
