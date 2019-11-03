#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
 int n,g,i=10;
 srand((unsigned)time(NULL)); //初始化随机种子
 n=rand()%100+1;//生成[1,100]随机数
  while(i--)
 {
 printf("Input A Number: ");//提示输入
 scanf("%d",&g);
 if(n==g)
 {
 	printf("you are right!%d Times right\n",10-i);//猜中
 	break;
 }
 else if(g<n)
 printf("Lower Than That\n");
 else
 printf("Higher Than That\n");
 if(i==0)
 printf("Game Over!\n");//10次未猜中
}
  return 0;
}
