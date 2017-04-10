#ifndef CONTROL_H
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include"StrClass.h"; 

class Control
{
	friend class StrClass; 
	public: 
		Control();
		Control(int numbers); 
		void CreateNode(char * info);
		void InsertOrdered(StrClass * n);

		void SetHead(StrClass * h);
		void SetTail(StrClass * t);
		StrClass * GetHead();
		StrClass * GetTail();
		void SetPerLine(int number); 

		void DisplayAlgorithm();
		int DisplayConsole(int namesPer, int node_count); 
		int GetTotalNodes();
		int GetCharCount(int names_per_line, int index); 

		~Control(); 
	private:
		int m_nNamesPerLine;
		int m_nTotalNodes; 
		StrClass * head;
		StrClass * tail;


};
#endif

