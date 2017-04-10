/************************************************************************
* Class: controller.h
*
* Purpose: This class handles input and output of Airline data. Including
*	iterators: Generic, Skip, AtoL, MtoZ, Reverse
*
* Manager functions:	
* 	Controller()
*			The default m_echo is true, opens CST136Output.txt
*	~Contorller()
*
* Methods:		
*	ReadAndFill()
*			Read AirData3.txt and fill information into Linked List
*	ReadAndExecute()
*			Read Commands.txt and execute accordingly 
*	Delete(char * c_tar)
*			Delete City based on Code or Name
*	PrintErr(char * c_tar)
*			Error message if city target isn't found 
*	PrintConfirm(char * c_tar)
*			Confirmation message if city target was found 
*	PrintExit()
*			Exit message 
*	PrintDataTo(Node * data)
*			Print data found, City and flights 
*	PrintAll()
*			Print all data, calling each iterator
*	ofstream DataOut;
*			variable for all OutPut to txt file 
*************************************************************************/

#ifndef controller_h
#define controller_h
#include<fstream>>
using std::ofstream; 

#include "llist.h"

class Controller
{
	public:
		Controller(); 

		void ReadAndFill(); 
		void ReadAndExecute();

		void Delete(char * c_tar); 

		void PrintErr(char * c_tar); 
		void PrintConfirm(char * c_tar); 
		void PrintExit(); 

		void PrintDataTo(Node * data);
		void PrintAll();

		ofstream DataOut; 

		~Controller();
	private:
		char m_com[3]; 
		bool m_echo; 
		Llist m_AirList; 
		BaseIterator *iterators[5];
};
#endif