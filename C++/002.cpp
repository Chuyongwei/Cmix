#include<iostream>
using namespace std;
void coudntion(int);
int main()
{
	double fun();
	cout << fun();
}

double fun(){
	double x = 9,y =9;
	double aver = 0;
	double i = 0;
	while(x!=0&&y!=0)
	{
		cin >>x>>y;
		aver += 2.0*x*y/(x+y); 
		i++;
	}
	return aver/i;
}
