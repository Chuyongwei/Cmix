#include <iostream>
class Complex
{
	
	public:
		double real;
		double image;
		Complex(void){
			real = 0;
			image  = 0;
		};
		Complex(double rp,double ip){real = rp;image = ip;}
		friend Complex operator+(const Complex &x,const Complex &y);
		void print(void);
};
Complex operator+(const Complex &x,Complex &y){
	return Complex(y.real+x.real,y.image+x.image); 
}

void Complex::print(){
	std::cout<<'('<<real<<','<<image<<')';
}
int main()
{		
	Complex A(255,34);
	Complex B(34,255);
	Complex C;
	C = A+B;
	C.print();
} 


