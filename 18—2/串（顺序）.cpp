#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define TURE 1
#define ERROR 0
#define FALSE 0
#define OVERFLOW 0
#define MAXSTRLEN 255
typedef unsigned char SString[MAXSTRLEN+1];
typedef int Status;
typedef int ElemType;

Status Concat(SString &T,SString S1,SString S2)
{//链接两个串 
	int i=0;
	Status uncut;
	if(S1[0]+S2[0]<=MAXSTRLEN)
	{
		while(i<=S1[0])
		{
			T[i] = S1[i];
			i++;
		}
		i = 0;
		while(i<=S2[0])
		{
			T[S1[0]+1] = S2[i];
			i++;
		}
		T[0] = S1[0]+S2[0];
		uncut = TURE; 
	}
	else if(S1[0]<MAXSTRLEN)
	{
		while(i<=S1[0])
		{
			T[i] = S1[i];
			i++;
		}
		while(i<=MAXSTRLEN)
		{
			T[i] = S2[i-S1[0]];
			i++;
		}
		T[0] = MAXSTRLEN;
		uncut = FALSE; 
	}
	else
	{
		while(i<=MAXSTRLEN)
		{
			T[i] = S1[i];
			i++;
			uncut = FALSE;
		}
	}
	return uncut;	
}


Status SubString(SString &Sub,SString S,int pos,int len)
{//获取第Sub后的pos个元素 
	if(len>S[0]-len+1||pos<1||pos>S[0]||len<0)
	return ERROR;
	int i=1;
	while(i<len)
	{
		Sub[i]=S[i+pos-1];
		i++;
	}
	Sub[0] = len;
	return OK;
}









