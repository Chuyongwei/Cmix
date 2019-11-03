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
	std::cout << "��ѧ����: "<<university_name<<std::endl;
} 
void Primary_scholar::show(){
	Student::show();
	using namespace std;
	cout<<"�γ̳ɼ�1: "<<course1<<endl;
	cout<<"�γ̳ɼ�2��"<<course2<<endl; 
}

int main()
{
	Student *p,A("������","������С��ɽ",1980);
	Academician B("����","�Ͻ��",1980,"�㽭��ѧ");
	Primary_scholar C("����","�������ϰ����Ͻ�",1979,89,95);
	std::cout<<"����ṹ"<<std::endl<<std::endl;
	p = &A;
	p->show();
	p = &B;
	p->show();
	p =&C;
	p->show();
	 
}
