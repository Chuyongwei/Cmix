#include<iostream>
#include<string.h>
class Student{
	protected :
		char Name[10];
		char Ad[20];
		int Year;
	public :
		Student(char *n,char *a,int y){
			strcpy(Name,n);
			strcpy(Ad,a);
			Year = y;
		} 
		virtual void show();
};

class Academician:public Student
{
	private:
		char university_name[20];
	public :
		Academician(char *n,char*a,int y,char * un_n):Student(n,a,y){
			strcpy(university_name,un_n);
		}
		void show();
};
class Primary_scholar:public Student{
	private:
		int course1 ,course2;
	public:
		Primary_scholar(char *n,char *a,int y,int c1,int c2):Student(n,a,y)
		{
			course1 = c1;
			course2 = c2;
		}
		void show();
};

void Student::show(){
	std::cout<<std::endl;
	using namespace std;
	cout<<"name: "<<Name<<endl;
	cout<<"adress: "<<Ad<<endl;
	cout<<"years: "<<Year<<endl; 
}

void Academician::show(){
	Student::show();
	std::cout << "大学名称: "<<university_name<<std::endl;
} 
void Primary_scholar::show(){
	Student::show();
	using namespace std;
	cout<<"课程成绩1: "<<course1<<endl;
	cout<<"课程成绩2："<<course2<<endl; 
}

int main()
{
	Student *p,A("张美丽","杭州市小黑山",1980);
	Academician B("王静","紫金港",1980,"浙江大学");
	Primary_scholar C("芳芳","温州市南白象紫金钩",1979,89,95);
	std::cout<<"输出结构"<<std::endl<<std::endl;
	p = &A;
	p->show();
	p = &B;
	p->show();
	p =&C;
	p->show();
	 
}
