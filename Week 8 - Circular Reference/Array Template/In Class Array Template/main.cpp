#include <iostream>
using namespace std;

#include"cube.h"
#include"TArray.h"


int main()
{
	try
	{
		TArray<Cube> arr0; //call no arg

		TArray<Cube> arr1(5); //create cube array of size 5, base 0

		int foo[3] = { 5 , 3, 8 };
		cout << "test" << (foo[2] = 99) << endl; 

		for (int i = 0; i < arr1.GetLength(); i++)
		{
			//	arr1[i] : class is not actually an array, so this doesn't work
			//will have to overload the "[]" operators in able to use
			//this notation (subscript operators)

			arr1[i].Display(); 
		}
		cout << endl; 

		arr1[3] = Cube(88); 
		for (int i = 0; i < arr1.GetLength(); i++)
		{

			arr1[i].Display();
		}
		cout << endl; 

		cout << "Testing copy c'tor" << endl;
		TArray<Cube> arr2(arr1); 
		for (int i = 0; i < arr1.GetLength(); i++)
		{

			arr2[i].Display();
		}
		cout << endl; 

		cout << "Testing op=" << endl; 
		arr0 = arr2; 

		for (int i = 0; i < arr1.GetLength(); i++)
		{

			arr0[i].Display();
		}
		
	}
	catch (char * msg)
	{
		cout << "Exception massage: " << msg << endl; 
	}

	return 0; 
}
