#include<iostream>


class  point{
	private:
		double x,y;
	public:
		point(double i,double j){
			x =i;y=j;
		}
		virtual double area(){
			return 0.0;
		}
};

const double pi = 3.14159;
class circle:public point{
	private:
		double radius;
	public:
		circle(double x,double y,double r):point(x,y)
		{
			radius = r;
		}
		double area(){
			return pi*radius*radius;
		}
};

//int main(){
//	point Ppoint(100,200);
//	double a= Ppoint.area();
//	std::cout<<"The area of the point is "<<a<<std::endl;
//	circle Ccircle(50,100,3.3);
//	a = Ccircle.area();
//	std::cout<<"The area of the circle is "<<a<<std::endl;
//	
//}

int main(){
	point *p;
	circle Ccircle(100,200,3.3);
	p = &Ccircle;
	double a = p->area();
	std::cout<<"The area of the circle is "<<a<<std::endl;
} 
