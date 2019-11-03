#include<iostream> 
#include<string.h>
#include<iostream>
#include<stdio.h> 
using  namespace std;
int main()
{
	int i;
	char a[200],b[200];
	while(gets(a))
	{
		if(strcmp(a,"START")==0) memset(b,0,sizeof(b));
		else if(strcmp(a,"END")==0)printf("%s\n",b);
		else if(strcmp(a,"ENDOFINPUT")==0)break;
		else
		{
			for(i = 0;a!='\0';i++)
		{
			if(a[i]>'A'&&a[i]<='Z')
			{
				if(a[i+21]>90)
				b[i] = (a[i]-5);
				else
				b[i] = (a[i]+21);
			}
			else
			b[i]= a[i];
		}
		} 
		
	} 
	printf("hsdklfjdsl"); 
	return 0;
	
	
} 
//START
//NS BFW, JAJSYX TK NRUTYFSHJ FWJ YMJ WJXZQT TK YWNANFQ HFZXJX
//END
//START
//N BTZQI WFYMJW GJ KNWXY NS F QNYYQJ NGJWNFS ANQQFLJ YMFS XJHTSI NS WTRJ
//END
//START
//IFSLJW PSTBX KZQQ BJQQ YMFY HFJXFW NX RTWJ IFSLJWTZX YMFS MJ
//END
