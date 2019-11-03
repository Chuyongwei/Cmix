#include<stdio.h>
float average(float score[],int n)
{
	float aver,sum = 0.0;
	int i;
	for(i=0;i<n;i++)
	sum+=score[i];
	aver=sum/n;
	return aver;
}
main()
{
	float score[6],aver;
	int i;
	printf("please input the score\n");
	for(i=0;i<6;i++)
	scanf("%f",&score[i]);
	aver=average(score,6);
	printf("the average score is %f",aver); 
}
