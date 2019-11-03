#include<stdio.h>
int main()
{
	int mouth;
	scanf("%d",&mouth);
	switch(mouth)
	{
		case 1||2||3: printf("´º¼¾");break;
		case 4||5: printf("ÏÄ¼¾");break;
		case 7||8||9: printf("Çï¼¾");break;
		case 10||11||12: printf("¶¬¼¾");break;
		default: printf("ÄãÊäÈëµÄÊı×Ö²»¶Ô"); 
    }
} 
