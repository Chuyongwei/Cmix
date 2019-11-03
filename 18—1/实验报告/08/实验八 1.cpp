#include<stdio.h>
struct str
{
       int year;
       int mouth;
       int day;
};
int countdays(int a,int b,int c)
{
    int count = 0;
    int m[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int i=b;
    for(i = 0;i<=b-2;i++)
          count = count+m[i];
    count = count+c; 
    if(a%4 == 0 && a%100!=0 || a%400 == 0)
    {
           printf("ÊÇÈòÄê"); 
         if(b>2)
         count = count+1;
    }  
     return count;
}
int main()
{
	int countdays(int a,int b,int c);
    struct str days,*p;
    int count;
    p = &days;
    scanf("%d%d%d",&p->year,&p->mouth,&p->day); 
    printf("%d",countdays(p->year,p->mouth,p->day));
    return 0;
}
