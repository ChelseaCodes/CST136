#define _CRTDBG_MAP_ALLOC
#include<crtdbg.h>

#include <iostream>
using std::cout; 
using std::endl;

#include<string>
using std::string; 

#include<sstream>
using std::getline; 

#include "StrClass.h"; 
#include "Control.h";

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);
	//StrClass s0, s1;		//test no arg

	//if (s0.IsEmpty())
	//{
	//	cout << "s0 is empty" << endl;
	//}
	//else
	//	s0.Display(); 

	//StrClass s3("Now is the Time for All..."); 
	//if (s3.IsEmpty())
	//{
	//	cout << "s3 is empty" << endl;
	//}
	//else s3.Display(); 

	//s1 = s3; 

	//if (s1.IsEmpty())
	//{
	//	cout << "s1 is empty" << endl;
	//}
	//else s1.Display();

	//Test Linked List Capabilities 
	/*Control s0(7);
	s0.CreateNode("Beautiful");
	s0.CreateNode("Absolute");
	s0.CreateNode("It's About Time");
	s0.CreateNode("Hollaback");
	s0.CreateNode("Tina Beltcher");
	s0.CreateNode("Louise Beltcher");
	s0.CreateNode("Aardvark");
	s0.CreateNode("Xzylophone");
	s0.CreateNode("Snakes can be pretty cool");
	s0.CreateNode("Hello World");

	s0.DisplayAlgorithm(); */

	int num_names(0);
	int num_lines(0);
	string buff = { '\0' };
	char ch_buff[75] = { '\0' };

	do
	{
		cout << "How many names will you input? (Max 10) ";
		cin >> num_names; 

		cout << "\n\nHow many names per line? ";
		cin >> num_lines; 

		if (num_names > 10)
		{
			cout << "max of 10 names only" << endl; 
		}
		else if (num_lines > 10)
		{
			cout << "max of 10 names per line" << endl; 
		}

	} while (num_names > 10 || num_lines > 10);

	Control s0(num_lines);

	cin.ignore();
	for (int i(0); i < num_names; i++)
	{
		cout << "Enter name/string " << i + 1 << " : ";
		getline(cin, buff);
		
		strcpy(ch_buff, buff.c_str());
		s0.CreateNode(ch_buff); 
	}

	s0.DisplayAlgorithm(); 

	system("pause");
	return 0; 
}