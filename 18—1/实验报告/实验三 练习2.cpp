#include<stdio.h>
int main()
{
	char ch1 = 'a';
	for(int i=1;i<=26;i++)
{
	printf("%c%c",ch1-32,ch1);
	ch1 = ch1+1;
	if(i%5==0)
	printf("\n");
	}
	return 0;
}
