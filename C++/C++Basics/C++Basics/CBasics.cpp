// CBasics.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include <iomanip>
#include <regex>
#include <functional>
//Number class and testStaticVariable() will test the static variable in a class
class Number{
public :
	static int i;
};
int Number::i = 0;
void testStaticVariable() {
	Number n1;
	n1.i = 1 ;
	Number n2;
	n2.i=  2;
	cout << n1.i << endl;
}
//arithmetic types : integral(int, character,boolean) and floating point.
string& ChangeStr(string& s) {
	s = "2";
	return s;
}
void testStrWithAnd() {
	std::cout << "testStrWithAnd:" << std::endl;
	string s1 = "1";
	string& s2 = s1; //s1 and s2 refer to the same memory
	s2 = "2";
	std::cout << "s1  =" << s1 << std::endl;
	std::cout << "s2  =" << s2 << std::endl;
}
void testStrWithoutAnd() {
	std::cout << "testStrWithoutAnd:" << std::endl;
	string s1 = "1";
	string s2 = s1;  //allocate a new space to store s2 which has the same content with s1
	s2 += "1";
	std::cout << "s1  =" << s1 << std::endl;
	std::cout << "s2  =" << s2 << std::endl;
}
void showHeader(std::ostream& out = std::cout) {
		out << "\n  ";
		out << std::setw(26) << std::left << "DateTime";   //std::setw will fill spaces 
		out << std::setw(10) << std::left << "Name";       //std::left makes spaces show after the string
		out << std::setw(25) << std::left << "Description";
		out << std::setw(25) << std::left << "Payload";
		out << "\n  ";
		out << std::setw(26) << std::left << "------------------------";
		out << std::setw(10) << std::left << "--------";
		out << std::setw(25) << std::left << "-----------------------";
		out << std::setw(25) << std::left << "-----------------------";
}
/* regular expression
   e.g. /^[0-9]+abc$/
 * covered with / amd /
   ^: from the start of obj to be matched
   [0-9]: to match a single number from 0 to 9
   plus +: can match several numbers
   abc: match characters abc
   with $: abc must in the tail of matching string
 *
 *
 */
void testLambda() {
	std::cout << [](double i) {return i; }(1.0); //return double automatically
	std::cout << "\n";
	std::cout << [](double i) ->int{return i; }(1.0); //return int 
	auto lambda = [](string s) {return "\nThis is a string: "+s;};
	std::function<string()> func = []() {return "\nThis is a string."; };
	std::cout << lambda("thos");
	std::cout << func();
}
void dynamicAllocation() {
	//p2 is on stack, new int(20) is on heap
	int * p2 = new int(20);  // define a int pointer with the 20 as its default value 
							 //the function new asks system to allocate a storage space
							 //for int and returns the address of the storage space
	cout << *p2 << "\n";
	cout << p2 << "\n";
	*p2 = 35;
	//p2 = 35;
	cout << *p2 << "\n";
	cout << p2 << "\n";

	delete p2; //*p2 is deleted, but not p2
	cout << p2 << endl;
	p2 = new int;
	cout << *p2 << endl;
}
enum status {
	open,
	close
};

int main()
{   
	
	//testStrWithAnd();
	//testStrWithoutAnd();

	//string s1 = "1";
	//string& s2 = ChangeStr(s1); //even though the return type of ChangeStr() is string&, the return value can also
	//                            //be assigned to a string type e.g.string s2 = ChangeStr(s1);but in that way,
	//                            // s1 and s2 will be different things
	//s2 ="3";
	//std::cout << "s1  =" << s1 << std::endl;
	//std::cout << "s2  =" << s2 << std::endl;
	//std::cout << "\n\n\n\n"<< std::endl;
	//showHeader();
	//std::cout << "\n" << std::endl;
	//testStaticVariable();

	//std::string str("akc");
	//std::string strin("xdf");
	//std::regex r("[abc]");
	//std::smatch m;
	////std::regex_search(str, m, r);
	////for (auto v : m) std::cout << v << std::endl;
	//if (std::regex_search(str, m, r))
	//{
	//	std::cout << true << std::endl;
	//}
	//if (!std::regex_search(strin, m, r))
	//{
	//	std::cout << false << std::endl;
	//}
	//testLambda();
	//dynamicAllocation();
	status s = open;
	if(s == open)
	cout << s;


	getchar();
	getchar();

    return 0;
}

