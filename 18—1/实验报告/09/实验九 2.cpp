#include<stdio.h>
#include<stdlib.h>
#include<calloc.h>
truct studen
{
	int nomber;
	char name[20];
	char sex;
	int age;
	struct studen *next;
} ;
struct studen *link_create()
{
		struct studen *p,stu,*head,*q;
	int i,d;
	q = (struct studen*) malloc (sizeof(struct studen));
	printf("NO.:");
	scanf("%d",&q->nomber);
	printf("name:");
	scanf("%s",q->name);
	getchar();
	printf("sex('m'or'f'):");
	scanf("%c",&q->sex);
	printf("age:");
	scanf("%d",&q->age);
	head = q;
	for(i=1;i<3;i++)
	{
		p = (struct studen*) malloc (sizeof(struct studen));
        printf("NO.:");
		scanf("%d",&p->nomber);
	    printf("name:");
		scanf("%s",p->name);
		getchar();
		printf("sex('m'or'f'):");
	    scanf("%c",&p->sex);
	    printf("age:"); 
	    scanf("%d",&p->age);
	    q->next  = p;
	    q = p;
	}
}
void link_outpout(struct studen *)
