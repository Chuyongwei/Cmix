#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct studen
{
	int nomber;
	char name[20];
	char sex;
	int age;
	struct studen *next;
} ;
int main()
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
	q->next = NULL;                     //建立链表完成 
    printf("input age:");
    p = head;
    for(i=0;i<3;i++)
    {
    	printf("%d",p->nomber);
    	printf("%s",p->name);
    	printf("%c",p->sex);
		printf("%d",p->age);
		p = p->next;
		printf("\n"); 
    }
}

