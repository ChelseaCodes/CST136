#define _CRTDBG_MAP_ALLOC
#include<crtdbg.h>

#include<iostream>
using namespace std;

#include "Date.h"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);

	cout << "Main no arg demo" << endl;

	Date d1;
	d1.Display();
	cout << endl; 

	cout << "Main 4 arg c'tor" << endl; 
	Date d2(9, 16, 58, "Now is the time..."); 
	d2.Display();
	cout << endl;

	cout << "Copy c'tor probs" << endl;						//without the deep copy, the address will be the same 
	Date d3 = d2; 
	d3.Display(); 
	cout << endl; 

	system("pause");
	return 0; 
}