/*
Julius Caesar����ʹ�ù�һ�ֺܼ򵥵����롣���������е�ÿ���ַ�������������ĸ���к�5λ��Ӧ���ַ������棬�����͵õ������ġ������ַ�A��F�����档���������ĺ��������ַ��Ķ�Ӧ��ϵ��

����
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

����
V W X Y Z A B C D E F G H I J K L M N O P Q R S T U 

��������ǶԸ��������Ľ��н��ܵõ����ġ�

����Ҫע����ǣ������г��ֵ���ĸ���Ǵ�д��ĸ��������Ҳ��������ĸ���ַ�������Щ�ַ����ý��н��롣
����
һ�У��������ģ����Ĳ�Ϊ�գ��������е��ַ���������200��
���
���һ�У������Ķ�Ӧ�����ġ�
��������
NS BFW, JAJSYX TK NRUTWYFSHJ FWJ YMJ WJXZQY TK YWNANFQ HFZXJX
�������
IN WAR, EVENTS OF IMPORTANCE ARE THE RESULT OF TRIVIAL CAUSES
*/

#include<iostream>

using namespace std;
int main() {
	char hang[255];
	cin.getline(hang, 255);
	for (int i = 0; hang[i] != '\0'; i++)
	{
		if (hang[i] >= 70 && hang[i] <= 90) 
		{
			cout << char(hang[i] - 5);
		}
		else
		{
			if (hang[i] >= 65 && hang[i] <= 90)
			{
				if (hang[i] == 'A') 
				{ 
					cout << "V";
				}
				if (hang[i] == 'B') 
				{
					cout << "W";
				}
				if (hang[i] == 'C') 
				{
					cout << "X";
				}
				if (hang[i] == 'D')
				{ 
					cout << "Y";
				}
				if (hang[i] == 'E')
				{
					cout << "Z"; 
				}
			}
			else
			{
				cout << hang[i];
			}
		}
	}
	system("pause");
} 
