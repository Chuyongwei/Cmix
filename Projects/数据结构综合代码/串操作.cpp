#include<stdio.h>  
#include<math.h>  
#include<stdlib.h>  
#include<string.h>  
#include<iostream>  
using namespace std;  
#define MAX 20  
typedef char* Type;  
char e[4];  
char s;  
  
typedef struct {  
    Type *base;  
    int front;  
    int rear;  
    int tag;  
    int count=0;  
}Sq;  
  
void InitSq(Sq &QQ);  
int Getlen(Sq QQ);  
int Isempty(Sq QQ);  
void InSq(Sq &QQ);  
void OutSq(Sq &QQ);  
void GetHead(Sq QQ);  
void OutSq_one(Sq &QQ);  
  
int main()  
{  
    int len,index=0;  
    char a[20*4];  
    Sq Q;  
    InitSq(Q);  
    //input  
    printf("please input the number of Q\n");  
    cin>>len;  
    getchar();  
    for(int i=0;i<len/4+1;i++)  
    {  
        scanf("%s",e);  //必须四个一组输入，每次敲回车，剩下不足四个也一块输入，以回车结束   
        InSq(Q);  
    }  
      
    //judge  
    for(int i=0;i<(len/2);i++)  
    {  
        OutSq_one(Q);  
        a[index++]=s;  
    }  
    if(len%2!=0)        //如果是奇数就弹出中间那个  
        OutSq_one(Q);  
    while(--index>=0)  
    {  
        OutSq_one(Q);  
        if(s!=a[index])  
        {  
            printf("NO\n");  
            return 0;  
        }  
    }  
        printf("YES\n");  
    return 0;  
}  
  
void OutSq_one(Sq &QQ)  
{  
    if(QQ.front == QQ.rear && QQ.tag==0)  
    {  
        printf("the queue is empty\n");  
        return;  
    }  
    s=QQ.base[QQ.front][QQ.count++];  
    if(QQ.count==4)  
    {  
        QQ.count=0;  
        free(QQ.base[QQ.front]);  
    //  e=Q.base[Q.front];  
        QQ.front=(QQ.front+1)%MAX;  
        if(QQ.front == QQ.rear)  
            QQ.tag=0;  
    }  
}  
void InitSq(Sq &QQ)  
{  
    QQ.base=(Type *)malloc(MAX * sizeof(Type));  
    if(!QQ.base)  
        return ;  
    QQ.front=QQ.rear=QQ.tag=QQ.count=0;  
}  
  
int Getlen(Sq QQ)  
{  
    if(!QQ.tag)     //分情况讨论，tag==0，长度肯定为0；  
        return 0;  
    else  
    {  
        if(QQ.rear==QQ.front)  
            return MAX;  
        return (QQ.rear-QQ.front+MAX)%MAX;  
    }  
      
}  
  
int Isempty(Sq QQ)  
{  
    if(QQ.front==QQ.rear && QQ.tag==0)  
        return 1;  
    return 0;  
}  
  
void InSq(Sq &QQ)  
{  
  
    if (QQ.front == QQ.rear && QQ.tag==1)   //tag与队头队尾必须同时满足  
    {  
        printf("%d\n",QQ.tag);  
        printf("the queue is full\n");  
        return ;  
    }  
    QQ.tag=1;  
    //  Q.base=(Type )malloc(MAX * sizeof(Type));  
    QQ.base[QQ.rear]=(Type )malloc(4 * sizeof(Type));  
    strcpy(QQ.base[QQ.rear],e);                   
//    Q.base[Q.rear] = e;  
    QQ.rear =(QQ.rear+1)%MAX;  
}  
void OutSq(Sq &QQ)  
{  
    if(QQ.front == QQ.rear && QQ.tag==0)  
    {  
        printf("the queue is empty\n");  
        return;  
    }  
    strcpy(e,QQ.base[QQ.front]);  
    free(QQ.base[QQ.front]);  
//  e=Q.base[Q.front];  
    QQ.front=(QQ.front+1)%MAX;  
    if(QQ.front == QQ.rear)  
        QQ.tag=0;  
}  
  
void GetHead(Sq QQ)  
{  
    if(QQ.front == QQ.rear && QQ.tag==0) return;  
    strcpy(e, QQ.base[QQ.front]);  
//    e = Q.base[Q.front];  
}   
