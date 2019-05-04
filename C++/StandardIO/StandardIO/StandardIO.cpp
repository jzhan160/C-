// StandardIO.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using  std::cin;
using  std::cout;
using  std::endl; //using namesapce declaration
int main()
{   
	//int num1 = 0,num2 = 0;
	//cout << "This is the standard output."<<endl;
//	cin >> num1>>num2;
//	cout << "Numbers you input are "<<num1 << " and " << num2 << endl;
	

//	int sum = 0, value = 0;
//	while (cin >> value) //receive numbers until not int(you can enter a character) and add all numbers
//		sum += value; 
//	cout << "Sum is: " << sum << endl;
	char chars[] = {'a','a'};
	for each (char c in chars)
	{
		c = 'b';
	}
	for each (char c in chars)
	{
		cout << c << endl;
	}


    return 0;
}

