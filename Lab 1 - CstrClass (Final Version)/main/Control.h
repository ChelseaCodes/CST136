#ifndef CONTROL_H
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include"StrClass.h"; 

class Control
{
	public:
		Control();												//no arg c'tor
		Control(int numbers);									//one arg c'tor, sets numbers per line 
		void CreateNode(char * info);							//creates an object of StrClass
		void InsertOrdered(StrClass * n);						//Inserts created StrClass obj. into linked list 

		void SetHead(StrClass * h);								//Sets the head of the linked list 
		void SetTail(StrClass * t);								//sets the tail
		StrClass * GetHead();									//Gets the head
		StrClass * GetTail();									//Gets the tail
		void SetPerLine(int number);							//Sets number of words per line 

		void DisplayAlgorithm();								//Top algorithm for finding how many chars there are per line 
		int DisplayConsole(int namesPer, int node_count);		//displays name. uses a loop based on names per and returns how many StrClass objs were outputted
		int GetTotalNodes();									//Gets the total number of StrClass objs in linked list 
		int GetCharCount(int names_per_line, int index);		//Passing in how many names are wanted per line, starting at the index, figures out how many chars are in a line 

		~Control();												//d'tor 
	private:
		int m_nNamesPerLine;									//How many names per line 
		int m_nTotalNodes;										//How many nodes in linked list 
		StrClass * head;										//head pointer 
		StrClass * tail;										//tail pointer 


};
#endif

