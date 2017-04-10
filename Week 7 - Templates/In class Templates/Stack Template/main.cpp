/*****************************************
*	2.20 - Exception handling 
* funA():try funB() catch
* funB():funC();
* funC(): throw() - unwinds stack and 
*		goes to catch block in funA()
*
*	2.20 - Templating persons and Cubes
*
******************************************/
#include<iostream>
using std::cout;
using std::endl;

#include "Cube.h"
#include "CubeStack.h"
#include "Exception.h"
#include "TStack.h"
#include "person.h"

int main()
{
	//try catch statement - v similar to c# exception handling
	try {
		Cube c0(8); Cube c1(6); 

		cout << endl; 
		//CubeStack myStack; 
		TStack<Cube> myStackC;	//TStack < OBJECT >  name; 
		TStack<Person> myStackP; 
		cout << endl; 

		/*cout << "Pushing in main" << endl; 
		myStack.Push(c0); 
		myStack.Push(c1); 
		cout << "Stack size: " << myStack.GetSize() << endl; */

		cout << "Push in main" << endl;
		cout << "stack size: " << myStackC.GetStackSize() << endl; 
		myStackC.Push(c0);
		cout << "stack size: " << myStackC.GetStackSize() << endl;
		cout << endl; 

		myStackC.Pop().Display(); 
		cout << "Stack size: " << myStackC.GetStackSize() << endl;  
		cout << endl; 
		
		//cout << "throws exception in push" << endl; 
		//for (int i(0); i < 10; i++)
		//{
		//	myStack.Push(0); 
		//}

		//cout << "\n\nPopping in main" << endl;

		////this relies on the caller checking if it's empty, rather than auto doing it. 
		////if (!myStack.IsEmpty())	
		//myStack.Pop().Display();
		////if(!myStack.IsEmpty())
		//cout << endl; 

		//cout << "2nd pop" << endl; 
		//myStack.Pop().Display();
		//cout << "Stack size: " << myStack.GetSize() << endl;
	}
	//catch ensures code doesn't completely crash
	catch (Exception ex)
	{
		cout << ex.GetFileName() << " " << ex.GetMethodName()
			 << " " << ex.GetMessage() << endl; 
	}
	//since throwing a 10 - need to catch a 10(int)
	catch (int num)
	{
		cout << "Error number: " << num << endl; 
	}
	//good to have in main
	catch (...)
	{
		cout << "I catch everything" << endl; 
	}
	system("pause"); 
	return 0; 
}