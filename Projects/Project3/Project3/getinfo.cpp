#include<iostream>
#include<stdlib.h>
int main()
{
	using namespace std;
	int carrots;
	cout << "How many carrots do you have?" << endl;
	cin >>  carrots;

	cout << "Here are wo more. ";
	carrots = carrots + 2;
	cout << "How you have " << carrots << " carrots." << endl;
	cin.get();
	cin.get();
	system("pause");
	return 0;
}