#include<stdio.h>
int main()
{
	int v;
	float u; 
	scanf("%d",&v);
	if(v<0)
	{u=3*v-1;}
	else if(v==0)
	{u=0;}
	else if(v>0&&v<=10)
    {u=v*v+4;}
	else if(v>10)
	{u=(v-5)/2;}
	printf("%f",u);
	return 0;
} 
