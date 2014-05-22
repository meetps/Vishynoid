#include<iostream>
#include<list>
using namespace std;
class Base{
	public:
	Base(){
	}
	virtual void speak(){
		cout<<"Base!\n";
	}
};
class Derived1:public Base{
	public:
	Derived1(){
	}
	virtual void speak(){
		cout<<"Derived1!\n";
	}
};
class Derived2:public Base{
	public:
	Derived2(){
	}
	virtual void speak(){
		cout<<"Derived2!\n";
	}
};
int main(){
	Base objs[3];
	objs[0]=Base();
	objs[1]=Derived1();
	objs[2]=Derived2();
	for(int i=0; i<3; i++)
		objs[i].speak();
	return 0;
}
