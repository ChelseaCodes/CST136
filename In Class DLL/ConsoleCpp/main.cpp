#include <iostream>
using std::cout;
using std::endl;

//now we need to grab the .dll 
//and grab the .lib file 
//rt click the references and add
//a reference.

#include "..\CalcDLLL\Calculator.h"
//include the new namespace
using namespace CalcDll;



int main()
{
	Calculator c0;
	cout << "Adding 4 + 5 = " << c0.Add(4, 5) << endl; 

	//first compile didn't work
	//set the project with main as the start up

	cout << "Multiplying 4 * 5 =" << c0.Mult(4, 5) << endl; 
	//after adding the namespace
	//LINKR error. No way to link from the .h to the .exe
	//****!only if the _declspec() isn't for the class,
	//and only for Mult, or any of the other methods. 
	//use _declspec for the CLASS to include all methods

	return 0; 
}

//when creating .dlls, you should also create namespaces
//C# and java will auto create a namespace when making dlls