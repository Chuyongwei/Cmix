//2019年3月28日 18：17
#include<stdio.h>
#include<malloc.h>
#define TURE 1
#define OK 1
#define ERROR 0
typedef int Status; 
typedef struct node{
	Status data;
	struct node *next;
}List;
Status InitList(List *L)
{
	 List *p;
    int i,j;
     L = ( List *) malloc ( sizeof ( List ) );
    L->next = NULL; // 先建立一个带头结点的空链表
   for ( i = 5; i > 0; --i )
   {
   p = ( List *) malloc ( sizeof ( List ) ); 
	p->next = L->next; 	
    L->next = p;       
         } 
	return OK;
} 
Status DestroyList(List &T)
{
	free(&T);
	return OK;
}
Status ListLength(List L)
{
	List *p;
	int i=0;
	while(p!=NULL)
	{
		i++;
		p = p->next;
	}
	return OK;
} 
Status Get(List *L,int i,Status &e)
{
	int j = 0;
	List *p = L;
	while(j<=i)
	{
		p = p->next;
		j++;
	}
	e = p->data;
	return OK;
}

Status Put(List *L,int i,Status e)
{
	int j = 0;
	List *p;
	p = L;
	p = p->next;
	while(j<=i)
	{
		p = p->next;
		i++;
}
	p->data = e;
	return OK;
}
Status ListDelete(List *L,int i,Status &e)
{
	int j = 0;
	List *p = L->next,*q;
	while(j<=i)
	{
		p = p->next;
		i++;
	}
	e = p->data;
	q = p->next;
	p->next = q->next;
	free(q);
	return 0;
}
Status main()
{
	Status i = 0, e, a[5]={1,2,3,4,5};
	List *L;
	InitList(L);
	while(i<5)
	{
		Put(L,i,1);
		getchar();
		i++;
	}
	while(i<5)
	{
		Get(L,i+1,e);
		printf("%5d",e);
	}
	return 0;
	
} 
