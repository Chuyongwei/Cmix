#include<stdio.h>
int main()
{
	int mouth;
	scanf("%d",&mouth);
	switch(mouth)
	{
		case 1||2||3: printf("����");break;
		case 4||5: printf("�ļ�");break;
		case 7||8||9: printf("�＾");break;
		case 10||11||12: printf("����");break;
		default: printf("����������ֲ���"); 
    }
} 
