// PointerAndRef.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

class A {
	int i;  // i does not have to be explicitly initialized
	std::string str;
public:
	A() {
		//int k;
		std::cout << i << std::endl;
		//std::cout << k << std::endl;  //k must be explicitly initialized
		std::cout << str.c_str() << std::endl;
	}
	void print() {
		std::cout << "The print mehthod in class A" << std::endl;
	}
};

void TestPR(int *num) {
	std::cout << *num << "\n";
}
int main()
{

	A a;  
	a.print();

	//A reference is not an object. Instead, a reference is just another name for an already existing object.
	int iValue = 1024;
	int &refValue = iValue;
	//int &refValue1; error: must initialize by object instead of literal
	std::cout << &refValue<<std::endl; //address
	std::cout << refValue << std::endl;//value
	refValue = 2048;
	std::cout << &refValue << std::endl; //address
	std::cout << refValue << std::endl;//value
	std::cout << iValue << std::endl;//the value of iValue has been changed but the address is not changed

	//pointer 
	int * p = 0;
	std::cout << p << std::endl; 
	if(p== nullptr)
	std::cout << "p points to nullptr." << std::endl;
	int zero = 0;
	int num1 = 1;
	int num2 = 2;

	p = &num1; 
	std::cout << p << std::endl;
	std::cout << *p << std::endl;
	*p = num2; // can do this only if p is not a nulptr
	std::cout << p << std::endl;
	std::cout << *p << std::endl;

	std::cout << num1 << std::endl; // num1 = num2
	std::cout << num2 << std::endl;
	std::cout << "---------------------------------------------------------"<< std::endl;
	int *p1 = &zero;
	std::cout << *p1 << std::endl;
	TestPR(p1);
	TestPR(&zero); // passed by either pointer or ref  OK

	//void* 
	// We can compare it to another pointer, we can pass it to or return it from a function, and we can assign it to another void* pointer.
	//But we cannot use a void* to operate on the object it addresses becasue we don’t know that object’s type.
	void* vPointer = &iValue;
	vPointer = p1;

	int **p2 = &p1; //pointer which points to a pointer
	std::cout << "*p1 = "<<*p1 << std::endl;
	std::cout << "p1 = "<< p1 << std::endl;
	std::cout << "&zero = "<<&zero << std::endl;

	std::cout <<"**p2 = " <<**p2 << std::endl;
	std::cout <<"*p2 = " <<*p2 << std::endl;
	std::cout << "p2  ="<< p2 << std::endl;

	int *&refP = p1;  //reference to pionter
    return 0;
}

