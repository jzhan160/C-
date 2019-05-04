// StringVectorArray.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include<iostream>
using std::string;
using std::vector;
using std::cout;
using std::endl;
void stringMethod() {  
	//Initialization
	string s1 = "string1";
	string s2("string2");
	string s3(3,'s');   //"sss"
    std::cout << s1 << std :: endl;
	std::cout << s2 << std::endl;
	std::cout << s3 << std::endl;
	
	string line;
	getline(std::cin, line); //readline
    std::cout << line << std::endl;

	int len = line.size();
	size_t i = line.size();  //The string class defines several companion types to make it possible to use the library types in a machine-independent manner.
							 //The type size_type is one of these companion types.
	std::cout << len <<" "<<i<<std::endl;

	string s4(3, 's');
	if (s3 == s4)  // if s3 and s4 have the same content, different from Java
	{
	  std::cout <<"s3 is equal to s4."<< std::endl;
	}

	for ( auto &c:s3) //c must be address
	{
		c = toupper(c);
	}
	std::cout << s3 << std::endl;
	std::cout << s3[1] << std::endl; //access the second character in s3
}

void vectorMethod() {
	vector<int> v1;  //empty vector
	vector<string> v2 = { "a","c","v" };
	vector<string> v3(v2); //v3 is a copy of v2
	vector<int> v4(10, 1); //v4 has ten 1 .
	vector<string> v5{ 10 };
	vector<string> v6{ 10, "hi" };
	for (size_t i = 0; i < v5.size(); i++)
	{
	 std::cout << v5[i] << std::endl;
	 std::cout << v6[i] << std::endl;
	}
}

void iteratorMethod() {
	//use iterators to iterate vector v by begin() and end() methods
	vector<string> v = { "1","2","3" };
	auto c1 = v.begin(), c2 = v.end(); //c2 denotes the off-the-end iterator which is nonexistent
	cout << *c1 << endl;     //must use *
	//cout << *c2 << endl;  //error because c2 points to one past the last element in v
	//if container is empty, begin() = end();
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}
    //const and nonconst iterators 
	const vector<int> cv = {1,2,3};
	auto const_it1 = cv.begin();
	cout << *const_it1 << endl; // read only
	auto it1 = v.begin();
	*it1 = "2"; // read and write
	auto const_it2 = v.cbegin();
	cout << *const_it2 << endl; // read only

	// detect whether an element in vector vc is empty
	vector<string> vc = {"a","b","","c"};
	for (auto i = vc.cbegin(); i != vc.cend(); i++)
	{
		if (!i->empty())  //equals to !(*i).empty()
		{
			cout << *i << endl; 
		}
		else
		{
			cout << "This element is empty"<< endl; 
		}
	}

	//iterator increment
	auto iter = vc.begin() + 1;
	cout << *iter << endl;  //vc[1]
}

//binary search using iterators
void binarySearch(int num) {
	vector<int> nums = { 1,2,3,4,5,6,7,8,9};
	auto start = nums.begin(), end = nums.end();
	while (start != end)
	{
		auto mid = start + (end - start) / 2;
		if (*mid == num)
		{
			cout << "Find the element " << *mid << endl;
			return;
		}
		else if (*mid > num) {
			end = mid;
		}
		else
		{
			start = mid+1;
		}
	}
	cout << "Not find the element " << num << endl;
}

void arrayMethod() {
	char cArray[] = "characters"; //11 characters, null is added to the end automatically
	cout << sizeof(cArray)/sizeof(cArray[0])<< endl;
	cout << sizeof(cArray) << endl;
	// char a[] = cArray; //cannot assign one array to another

	//complicated array declaration
	int* p1 = nullptr, *p2 = nullptr;
	int *ptrArray[2] = {p1,p2}; // an array holds two pointer
	int arr[2];
	int(*Parray)[2] = &arr;    //a pointer points to an array whose element is in type of int
	int(&refArray)[2] = arr;   //a reference refers to an array whose element is in type of int
	int *(&rArray)[2] = ptrArray;  //a reference refers to an array whose element is in type of int*
	int *(*pArray)[2] = &ptrArray; ////a pointer points to an array whose element is in type of int*
}

void arrayAndPointer() {
	int nums[] = {1,2,3,4,5};
	int* p1 = &nums[0]; //1
	int* p2 = nums;    // 2
	                   // 1 is equavilent to 2
	auto p3(nums);     //then p3 is a pointer which equals to auto p3(&nums[0]);
	decltype(nums) p4 = {1,2,3};//p4 is an int array. p4 must be innatialized because decltype just gives p4 the type of nums[] not values
	cout << p4[1] << endl;
	
}
int main()
{   
	//stringMethod();
	//vectorMethod();
	//iteratorMethod();
	//binarySearch(4);
	//binarySearch(0);
	//arrayMethod();
	arrayAndPointer();

	string s("This is a string.");
	cout << s;  //now there is no error outputing string type
	// but if we remove #include <string>, errors will apprear
	//if we want to output  string correctly, we need to convert it 
	// to char* using s.c_str()
    return 0;
}

