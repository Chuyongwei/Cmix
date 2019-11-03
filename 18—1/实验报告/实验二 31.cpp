#include<stdio.h>
int main()
{
	int mouth;
	scanf("%d",&mouth);
	if(mouth>=1&&mouth<=3)
	printf("spring");
	else if(mouth>=4&&mouth<=6)
	printf("summer");
	else if(mouth>=7&&mouth<=9)
	printf("ant");
	else if(mouth>=10&&mouth<=12)
	printf("wein");
	else printf("not");
	return 0;
	
	
} 
