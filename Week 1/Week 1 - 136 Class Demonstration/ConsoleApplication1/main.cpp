#include <iostream>
#include"Square.h"
using namespace std; 

int main()
{
	cout << "in main no arg c'tor" << endl; 
	Square s0; 
	s0.Display(); 
	cout << endl; 

	cout << "one arg c'tor in main" << endl;
	Square s1(5); 
	s1.Display();
	cout << endl; 

	cout << "Copy" << endl;		//normally would be a deep copy with a pointer 
	Square s2(s1);
	//Square s2 = s1; same thing calls copy c'tor
	s2.Display(); 
	cout << endl; 

	cout << "Hmmm" << endl;		//not going to be in the copy constructor. Using the default Operator =
	s0 = s2;					//giving the pointer to s0 
	//s0.operator=(s2) is the same thing, rarely used. not as intuitive. 
	s0.Display(); 
	cout << endl; 

	system("pause");
	return 0; 
}