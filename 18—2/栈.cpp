#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define OVERFLOW -1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Status;
typedef int SElemType;
typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
} SqStack;

Status InitStack(SqStack &s)//�՜� 
{
	s.base=(SElemType*)malloc(STACK_INIT_SIZE);
	if(!s.base)exit(OVERFLOW) ;
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE;
	return 0;
}

Status GetTop(SqStack s,SElemType &e)
{
	if(s.top==s.base) return ERROR;
	e = *(s.top-1);
	return OK;
} 

Status Push(SqStack &s,SElemType e)
{
	if(s.top-s.base>=s.stacksize)
	{
		s.base = (SElemType*)realloc(s.base,(s.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!s.base) exit(OVERFLOW);	
		s.top=s.base+s.stacksize;
		s.stacksize+=STACKINCREMENT;
	}
	*(s.top++) = e;
	return OK;
}

Status Pop(SqStack &s,SElemType e)
{
	if(s.top=s.base)return ERROR;
	e = *(--s.top);
	return OK;
} 

Status StackEmpty(SqStack s)
{
	if(s.base=s.top) return TRUE;
}


