#include<iostream>
class Teacher{
	private:
		int x;
	public:
		Teacher(){
			x = 0;
		}
		Teacher(int x_){
			x = x_;
		}
		~Teacher(){
			std::cout<<"delete t"; 
		}
}; 

class Student{
	private:
		int x;
	public:
		Student(){
			x = 0;
		}
		Student(int x_){
			x = x_;
		}
		~Student(){
			std::cout<<"delete s";
		}
};

class Teach_Assistant:public Teacher,public Student{
	private:
		int m;
	public:
		Teach_Assistant():Teacher(),Student()
		{
			m = 0;
		}
		Teach_Assistant(int s,int a,int b):Teacher(s),Student(a)
		{
			m = b;
			
		}
		~Teach_Assistant(){
			std::cout<<"delete A"; 
		}
};

int main(){
	Teach_Assistant AA(3,4,5);
}



