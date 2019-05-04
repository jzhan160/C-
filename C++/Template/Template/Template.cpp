// Template.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<iostream>
#include<string>

using namespace std;
//template class
template <typename T> class Blob {
public:
	T value;
	std::initializer_list<T> il;
	//typedef typename std::vector<T>::size_type size_type;
	// constructors
	Blob(T value) {
		this->value = value;
	}
	Blob(std::initializer_list<T> il) {
		this->il = il;
	}
	// number of elements in the Blob
	//size_type size() const { return data->size(); }
	//bool empty() const { return data->empty(); }
	// add and remove elements
	//void push_back(const T &t) { data->push_back(t); }
	// move version; see § 13.6.3 (p. 548)
	//void push_back(T &&t) { data->push_back(std::move(t)); }
	//void pop_back();
	// element access
	//T& back();
	//T& operator[](size_type i); // defined in § 14.5 (p. 566)
private:
	
//	std::shared_ptr<std::vector<T>> data;
	// throws msg if data[i] isn't valid
//	void check(size_type i, const std::string &msg) const;
};

//template function
template<typename T>
T compare(const T & v1, const T & v2) {
	if (v1 > v2) {
		std::cout << v1 << " is larger than " << v2<<std::endl;
		return v1;
	}
	else if (v1 < v2) {
		std::cout << v1 << " is smaller than " << v2 << std::endl;
		return v1;
	}
	else {
		std::cout << v1 << " is equal to " << v2 << std::endl;
		return v1;
	}
}

int main()
{

	std::cout << "compare two integer numbers:" << std::endl ;
	int num1 = compare(1, 2);
	std::cout << "compare two double numbers:" << std::endl;
	int num2 = compare(1.0, 2.0);
	std::cout << "compare two strings:" << std::endl;
	std::string b = "b";
	std::string a = "a";
	std::string num3 = compare(a, b);

	Blob<int> blob1(1);
	std::cout << blob1.value << std::endl;
	Blob<int> blob2 = { 1,2,3 };
	for (auto iter : blob2.il)
	{
		cout << iter << endl;
	}

    return 0;
}

