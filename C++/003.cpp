#include<bits/stdc++.h>
using namespace std;
class Product{
	private:
	string name;
	int age;
	public:
	Product(){}
	Product(const string &ac,int c);
	void setname(string sd);
	string getname();
	void print();
};
	void Product::setname(string sd)
	{
		name = sd;
	} 
	Product::Product(const string &ac,int c){
		age = c;
		name = ac;
		cout<<"class prouduct";
	}
	string Product::getname()
	{
		return name;
	}
	void Product::print()
	{
		cout << name <<age;
	}
int mian(){
	string a = "hdskjfh";
	Product pro = Product("dshfkj",3);
	//pro.setname(a);
	//cout << pro.getname();
	pro.print();
	return 0;
}


