#include<stdio.h>
struct students
{
    int nomber;
    char m[20];
    float score1;
    float score2;
    float score3;
};
int main()
{
    struct students stu[3],*p;
    p = stu;
    float aver,sum;
    int i,j;
    for(i = 0;i<3;i++,p++)
    {
          scanf("%d%s%f%f%f",&p->nomber,&p->m,&p->score1,&p->score2,&p->score3);
          aver = (p->score1+p->score2+p->score3)/2; 
          printf("NO:%d\nname:%s\nscore:%5.2f %5.2f  %5.2f\n%5.3f",p->nomber,p->m,p->score1,p->score2,p->score3,aver);
          printf("\n");
    }
    p = stu;
    for(i = 0;i<3;i++,p++)
    {
    	if(sum<p->score1+p->score2+p->score3)
    	{
    		j=i;
    		sum=p->score1+p->score2+p->score3;
    	}
    } 
    printf("%s%5.2f",stu[j].m,sum);
    return 0;
}
