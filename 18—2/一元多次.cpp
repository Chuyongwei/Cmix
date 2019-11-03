#include<stdio.h>
#include<stdlib.h> 
#define  OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;
typedef struct Polynode
{
	int coef,exp;
	struct Polynode *next;
}Ploynode,*Polylist;
 void polycreate(Polylist &head)//一元多项式 
 {
 	Polylist rear,s;
 	int c,e;
 	head = (Polynode*)malloc(sizeof(Polynode));
 	rear = head;
 	scanf("%d,%d",&c,&e);
 	while(c!=0)
 	{
 		s = (Polynode*)malloc(sizeof(Polynode));
 		s->coef = c;
		 s->exp = e;
 		rear->next = s;
 		rear = s;
 		scanf("%d,%d",&c,&e);
 	} 
 	rear->next = NULL;
 }

Status Polyadd(Polylist &Lc,Polylist La,Polylist Lb)//合并 
{
	Polylist pa,pb,pc,r;
	int sum;
	pc = pa = La;
	pb = Lb;
	while(pa)
	{
		if(pa->exp<pb->exp)	
		{
			pc->next = pa;
			pc=pa;
			pa=pa->next;
		} 
		if(pa->exp>pb->exp)
		{
		    pc->next =pb;
		    pc = pa;
		    pb = pb->next;
		}
		if(pa->exp=pb->exp)
		{
			sum = pa->coef+pb->coef;
			if(sum!=0)
			{
				pa->coef=sum;pc->next=pa;
				pa = pa->next;
				r=pb;pb=pb->next;free(r);
			}
			else
			{
				r=pa;pa=pa->next;free(r);
				r=pb;pb->next=pb;free(r);
			}
		}  
	}
}
