#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OK 
typedef int Status;
typedef int SElemType;
typedef struct stacknode
{
	datatype data;
	struct stacknode *next;
}stacknode;

void conversion(){
	InitStact(S);
	scanf("%d",&N);
	while(N){
		Push(S,N%8);
		N = N/8;
	}
	while(!StackE)
}
