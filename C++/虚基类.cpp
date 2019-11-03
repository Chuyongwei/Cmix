#include<iostream>
class A{
	public:
		int n;
}; 

class B:virtual public A{}; 
class C:virtual public A{};
class D:public B,public C
{
	int getn(){return B::n;}
}; 
int main(){
	D a;
	a.B::n = 20;
	a.C::n = 10;
	std::cout<<a.C::n<<",";
	std::cout<<a.B::n<<std::endl;
}
