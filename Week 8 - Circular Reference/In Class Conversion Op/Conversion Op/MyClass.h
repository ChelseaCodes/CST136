#pragma once
#include<iostream>
#include"LibraryClass.h"

using namespace std; 

class MyClass
{
public:
	MyClass(int number) 
	{		
		cout << "My class 1 arg c'tor" << endl; 
		m_number = number;
	}
	MyClass(const LibraryClass & libclass)
	{
		cout << "in MyClass 1 arg LibClass c'tor" << endl; 
		m_number = libclass.GetNumber();	//can only do this b/c libclass GetNum is a const method 
	}

	//******Const Methods
	//added in const. 
	//this is all that's needed.
	//only need to get the number
	//don't need to change it. 
	int GetNumber() const 
	{ return m_number; }

	//******Function Overloading
	//same name, different num of parameters and types
	//BUT not the return type. 
	//another way to overload: using COONST
	void foo(int a);
	void foo(int a, char * str); 
	void foo(char * str); 
	//int foo(int a);	//wont allow with just a different return type
	int foo(int a) const;	//WILL allow, with the const. 
	//Accessors should ALL be const. 

	//*******Conversion Operator. 
	//operator "Type i want to convert to"
	//convert me (MyClass) into something else (LibClass)
	//with operator, because it's LibraryClass, you don't need a return type
	//it can ONLY return a LibClass. 
	operator LibraryClass()
	{
		cout << "in operator LibraryClass" << endl; 
		return LibraryClass(m_number); 
	}

	operator int()
	{
		cout << "in operator int" << endl; 
		return m_number;	//returns an int.
	}

private:
	int m_number; 
};
