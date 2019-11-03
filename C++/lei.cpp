#include<iostream>
using namespace std;
class Box{
	private:
		int a,b,c;
	public:
		Box(int i,int j,int k){
			a = i;
			b = j;
			c = k;
		}
		int GetVolume()
		{
			return a*b*c;
		}
		int GetArea(){
			return ((a*b)+(b*c)+(b*a))*2;
		}
}; 

int main(){
	Box f(5,6,7);
	int a = f.GetArea();
	int b = f.GetVolume();
	cout << a<<endl << b;
}
