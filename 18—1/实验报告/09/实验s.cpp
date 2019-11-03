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
    for(i=0;i<3;i++)//输入链表 
    {
    	printf("%d",p->nomber);
    	printf("%s",p->name);
    	printf("%c",p->sex);
		printf("%d",p->age);
		p = p->next;
		printf("\n"); 
    }
    p =(struct stden*)malloc(sizeof(struct studen));
	p->next = head;//插入链表 
	head = p;
	printf("NO.:");
		scanf("%d",&p->nomber);
	    printf("name:");
		scanf("%s",p->name);
		getchar();
		printf("sex('m'or'f'):");
	    scanf("%c",&p->sex);
	    printf("age:"); 
	    scanf("%d",&p->age);
	    printf("%d",p->nomber);
    	printf("%s",p->name);
    	printf("%c",p->sex);
		printf("%d",p->age);
		p = p->next;
		printf("\n"); 
		for(i=1;i<=4;i++)
		{
			if(p->age==b)
			{
				if(p!=NULL)
				{
				q=p;
				p=p->next;
			    }
				if(p==NULL)
				   return (NULL);
				if(p==head)
				   head == head->next;
				q->next = p->next;//连接链表 
				free(p);//出去链表 
			}
		} 
}

