#include<stdio.h>
int main()
{
	FILE *filep;
	char ch1;
	
	if(filep=(fopen("C:\\Users\\ASUS\\Desktop\\ccp\\text.doc","r"))==NULL);
	{
		printf("\nCannot open the file, press any key to exit!\n");
		getch();
		exit(0);
	}
	ch1 = fgetc(filep);
	while(ch1!=EOF)
	{
		putchar(ch1);
		ch1 = fgetc(filep);
	}
	fclose(filep);
	getch();
} 
