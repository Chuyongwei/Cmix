#include<stdio.h>
#define NULL 0
struct node
{
	int data;
	struct node *next;
};
main()
{
	struct node *creatlist(int v[],int n);
	struct node *head;
	
	void printlist();
	int v[]={1,2,3,4,5,6,7,8,9};
	head = creatlist(v[10],9);
	printlist (head);
} 
struct node *creatlist(int v[],int n)
{
	struct node *head, *p, *q;
	int i;
	
	if(n <= 0) 
	return (NULL);
	q = (strcut node*)malloc(sizeof(struct node));
	q ->data = v[0];
	head = q;
	for(i = 1;i < n; i++)
	{
		/*形成新节点*/
		p = (struct node *) malloc(sizeof(struct node));
		p->data = v[i];
		q->next = p;
		q = p;
	} 
	q->next = NULL;
	return (head);
}
void printlist(struct node *head)
{
	struct node *p;
    p = head;
    while (p!= NULL)
    {
    	printf("%5d",p->data);
    	p = p->next;
    }
} 
