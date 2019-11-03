#include<iostream>
using namespace std;
double scar(double);
int main()
{
	double C;
	cout << "piase cout C: ";
	cin >> C;
	cout << endl;
	double F = scar(C);
	cout << "C is:" << F;
	system("pause");
	return 0;
}

double scar(double c)
{
	double a;
	a = 1.8*c + 32.0;
	return a;
}