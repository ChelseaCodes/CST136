#include<iostream>
using std::cout;
using std::endl; 

#include "LibraryClass.h"
#include "MyClass.h"

// 3.3.17 - manipulating classes here
//

void TestOne(const MyClass& myclass); 
void TestTwo(const MyClass& myclass); 
void TestThree(const LibraryClass& libclass); 
void TestFour(int num);
int main()
{
	LibraryClass libclass(7);
	cout << endl; 
	MyClass myclass(8); 
	cout << endl; 

	//passing a 5? Compiles. 
	//Passing in an int, to a funct that takes a MyClass
	//MyClass 1 arg takes an int, grabs the 5 and constructs
	//class object. 
	TestOne(5);	
	cout << endl; 

	//needs a constructor to take a LibCLass 
	//TestTwo(libclass);
	//created c'tor for this
	TestTwo(libclass); 
	cout << endl; 

	//Now we want to call a method to take MyClass
	//when it's expecting the LibraryClass
	//write a c'tor to take a MyClass in LibraryClass
	//Conceptually LibraryClass is a library, CANT modify
	// TestThree(myclass);
	//just need to write a conversion operator for MyClass
	//take MyClass obj and convert to LibClass obj. 
	TestThree(myclass); 

	//Expects an int, passing in MyClass
	//now needing to write another conversion
	//Something else into me = C'tor
	//Me to something else = conversion operator
	//TestFour(myclass); 
	TestFour(myclass); 
	//wrote conversion ^ 


	//Calvin categorizes above as "Clever Code" 
	//"Slick" ~ Calvin 2k17
	//Can be tougher to follow. Not used as often 
	//"Specialty Stuff" ~ Calvin 2k17 
	//make sure you're using them the way you want them to 
	//"Use with care" ~ Calvin 2k17 

	return 0; 
}

void TestOne(const MyClass & myclass)
{
	cout << "in TestOne" << endl; 

	//can't retrieve the number
	//why? Passing in a CONST ref object. 
	//Setters, Getters : Accessors, Mutators 
	//passing params: pass by value, by ref, by const ref
	//passing by value in our classes is inefficient due 
	//to having to create copies every time. 
	//pass by const ref for pass by value efficiency, 
	//and pass by ref semantics. 
	cout << "MyClass m_num is: " << myclass.GetNumber() << endl; 
}

//want to pass a LIB class, when this catches a MyClass
void TestTwo(const MyClass & myclass)
{
	cout << "In TestTwo" << endl; 
}
//"now for the tricky part" ~ Calvin 2k17
void TestThree(const LibraryClass & libclass)
{
	cout << "In TestThree" << endl; 

}

void TestFour(int num)
{
	cout << "In TestFour" << endl; 

}
