#include<iostream>
using namespace std; 

//typedef returntype (*typename) (params)
//function pointer that takes two ints and returns nothing 
//The two display functions have the SAME SIGNATURE
typedef void(*Dptr)(int, int); 

void SimpleDisplay(int x, int result)
{
	cout << "The value of " << x << " Factorial is: "
		<< result << endl; 
}

void FancyDisplay(int x, int result)
{
	cout << "Fancy Display" << endl; 
	cout << "*************************************" << endl; 
	cout << "*                                   *" << endl; 
	cout << "  The value of " << x << " Factorial is: "
			<< result << endl;
	cout << "*                                   *" << endl; 
	cout << "*************************************" << endl; 
}


//incorporate the function pointer into the Factorial function
//void XFactorial(int x)
void XFactorial(int x, Dptr display)
{
	if (x < 0)
	{
		throw("No negative numbers"); 
	}
	int result = 1;
	for (int i(1); i <= x; i++)
	{
		result *= i; 
	}

	display(x, result); 
}

int main()
{
	try
	{
		//XFactorial(5);
		// = SimpleDisplay() - with the brackets, it's a function call
		//below - Display1 equals the address of SimpleDisplay!
		Dptr Display1 = SimpleDisplay; 

		Dptr Display2 = FancyDisplay; 

		//invoke the function using the variable Display1; 
		//Display1(5, 120); 
		
		//Display1 = FancyDisplay; 
		//Display1(5, 120); 
		cout << endl; 

		XFactorial(5, Display1); 
		XFactorial(6, Display2); 
	}
	catch (char * msg)
	{
		cout << msg; 
	}

	return 0; 
}
/*  Can also have an array of function pointers and use a for loop
	to address all the different functions. Useful for Test methods 
	in data structures.  */
