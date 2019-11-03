#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node * Creat(int len){
    struct node *p, *q, *head;
    head = (struct node *) malloc (sizeof(struct node));
    head->next = NULL;
    q = head;
    for (int i = 1; i <= len; i++){
        p = (struct node *) malloc (sizeof(struct node));
        printf("请输入第%d个数:\n", i);
        scanf("%d", &p->data);
        q->next = p;
        p->next = NULL;
        q = p;
    }
    return head;
};

struct node * Hebing(struct node *p, struct node *q){
    struct node *head, *s;
    head = (struct node *) malloc (sizeof(struct node));
    head->next = NULL;
    s = head;
    while (p->next != NULL && q->next != NULL){
        if (p->next->data < q->next->data){
            s->next = p->next;
            p->next = p->next->next;
            s = s->next;
        }
        else if (p->next->data > q->next->data){
            s->next = q->next;
            q->next = q->next->next;
            s = s->next;
        }
        else{
            s->next = p->next;
            p->next = p->next->next;
            q->next = q->next->next;
            s = s->next;
        }
    }
    if (p->next != NULL){
        s->next = p->next;
    }
    else{
        s->next = q->next;
    }
    return head;
};

int main(){
    struct node *La, *Lb, *Lc;
    int len1, len2;

    printf("请输入链表La中元素个数:\n");
    scanf("%d", &len1);
    La = Creat(len1);

    printf("请输入链表Lb中元素个数:\n");
    scanf("%d", &len2);
    Lb = Creat(len2);

	printf("Lc中的元素分别为:\n");
    Lc = Hebing(La, Lb);
    while (Lc->next != NULL)
    {
        printf("%d ", Lc->next->data);
        Lc = Lc->next;
    }

    return 0;
}
