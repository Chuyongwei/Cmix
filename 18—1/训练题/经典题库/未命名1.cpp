#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
 int n,g,i=10;
 srand((unsigned)time(NULL)); //��ʼ���������
 n=rand()%100+1;//����[1,100]�����
  while(i--)
 {
 printf("Input A Number: ");//��ʾ����
 scanf("%d",&g);
 if(n==g)
 {
 	printf("you are right!%d Times right\n",10-i);//����
 	break;
 }
 else if(g<n)
 printf("Lower Than That\n");
 else
 printf("Higher Than That\n");
 if(i==0)
 printf("Game Over!\n");//10��δ����
}
  return 0;
}
