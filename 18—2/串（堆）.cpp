#include<stdio.h>
#include<stdlib.h>
#define TURE 1
#define FALSE 0
#define ERROR 0
#define OK 1
#define OVERFLLOW -2
typedef int Status;
typedef struct{
	char *ch;
	int length;
}HString;

Status SteAssign(HString &S,char *chars)
{//生成一个纸等于chars的串s； 
	int i,j;
	char *c; 
	for(i=0,c=chars;chars;i++,c++)
	if(!i)
	{
	   S.ch = NULL;
	   S.length = 0;
	}
	else
	{

	   if(!(S.ch=(char*)malloc(i*sizeof(char))))
	      exit(OVERFLLOW);
	   for(j = 0;j<i-1;j++)
	      S.ch[j] = chars[j];
	    S.length = i; 
    }
    return OK;
}

Status StrLength(HString S)
{//长度 
	return S.length;
}

Status StrInsert(HString &S,int pos,HString T)
{//在pos前加1个元素 
	int i = 0;
	if(pos<1||pos>S.length+1) return ERROR;
	if(T.length)
	{
	   if(!(S.ch = (char*)malloc(sizeof(char))))
	      exit(OVERFLLOW);
	   for(i=S.length-1;i>=pos-1;--i)
		   S.ch[i+T.length] = S.ch[i];
	   for(i = 0;i<=T.length-1;i++)
	    S.ch[pos-1+i]=T.ch[i];
	   S.length+=T.length;
    }
    return OK;
}

int StringCompare(HString S,HString T)
{
	int i;
	for(i = 0;i<S.length&&i<T.length;++i)
	if(S.ch[i]!=T.ch[i])return S.ch[i]-T.ch[i];
	return S.length-T.length;
}

Status ClearString(HString &S)
{
	if(S.ch)
	{
	  free(S.ch);
	  S.ch = NULL;
	}
	S.length = 0;
	return OK;
}

Status Concat(HString &S,HString S1,HString S2)
{
	int j;
	if(!(S.ch=(char*)malloc(S1.length+S2.length*sizeof(char))))
	exit(OVERFLLOW);
	for(j = 0;j<=S1.length-1;j++)
	{
		S.ch[j] = S1.ch[j];
	}
	 S.length = S1.length+S2.length;
	for(j=0;j<=S2.length-1;j++)
	{
		S.ch[S1.length+j] = S2.ch[j];
	}
	return OK; 
}


















