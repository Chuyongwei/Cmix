/*���亯�������,������Ҫ����֪һ��Ԫ�ؾ�Ϊ��λ�������飬
      �����������͸��������ڳ����е��ú���output_s����������Ԫ��
      ˳����������ú���reverse_s������������Ԫ�ط����Ų������
      �����ú���calculate_s�������Ԫ���и�λ����3��Ԫ�ء��뽫
      ��������������*/
#include<stdio.h>
#include<string.h>
void output_s(int a[],int j);
void reverse_s(int a[],int j);
void calculate_s(int a[],int j);
main()
{ 
	int b[10]={387,234,432,432,34,232,454,322,432,372},l;
	l = 10;
	printf("/n��������/n")
	output_s(b,l);
	printf("/n��������/n")
	reverse_s(b,l);
	printf("/n��λ�����������/n")
	calculate_s(b[10],l);
	return 0;
} 
void output_s(int a[],int j)
{
	for(int i=0;i<j;i++)
	printf("%d",a[i]);
}
void reverse_s(int a[],int j)
{
	for(int i=j-1;i>=0;i++)
	printf("%d",a[i]);
}
void calculate_s(int a[],int j)
{
	for(int i=0;i<j;i++)
	{
		if(a[i]>0)
		c = a[i]-a[i]/10*10;
		else
		c = a[i]/10*10-a[i];
		if(c=3)
		printf("%d",a[i]);
	}
}
