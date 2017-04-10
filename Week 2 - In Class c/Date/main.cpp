#include <iostream>
#include <string>"

#include "Date.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);


	cout << "main no arg c'tor demo" << endl;
	Date d1;
	d1.Display();
	cout << endl;

	cout << "main 4 arg c'tor" << endl;
	Date d2(9, 16, 58, "Now is the time...");
	d2.Display();
	cout << endl;

	cout << "fixed copy c'tor problems" << endl;
	Date d3 = d2;					
	d3.Display();
	cout << endl;

	//difference with copy c'tor and op=: 
	//d3 is being instantiated 
	//d1 is an object already made 

	cout << "fixed op= problems" << endl;
	d1 = d3;
	d1.Display();
	cout << endl;

	cout << "using friend ostream method" << endl;
	cout << d1;
	cout << endl;

	return 0;
}