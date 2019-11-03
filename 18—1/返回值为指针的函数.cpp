#include<stdio.h>
int main()
{
	float score[ ][4]={{60,70,80,90},{56,89,67,88},{34,78,90,66}}; 
	float *search(float(*pl)[4],int );
	int k,i;
	float *p;
	scanf("%d",&k);
	p=search(score,k);
	for(i = 0;i<4;i++)
	printf("%5.2f\t",*(p+i));
	return 0;
}
float *search(float(*pl)[4],int t)
{
	float *p;
	p = *(pl+t);
	return(p); 
}
