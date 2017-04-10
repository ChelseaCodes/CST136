/************************************************************************
* Class: llist.h
*
* Purpose: This class is a linked list of Cities, handling insert, print
*		Search and delete. 
*
* Manager functions:
* 	Llist()
*		default nodecount is 0, head and tail pointers are nullptr
*	Llist(const Llist& list)
*	~Llist()	
*		Purges entire list
*
* Methods:
*	InsertOrdered(City * data) 
*		Inserts City data into linked list 
*	Node * NSearch(char * c_target)
*		Searches for node, and returns it if found 
*	bool Delete(char * c_target)
*		Deletes specified City, searched by name or code 
*	Node * GetHead()
*	Node * GetTail()
*	LLPrintAll(ofstream& DataOut)
*		Print entire linked list to txt file 
*************************************************************************/
#ifndef llist_h
#define llist_h

#include<fstream>
using std::ofstream;

#include"node.h"
#include"city.h"

class Llist
{
	friend class Node;
	friend class BaseIterator; 
	public:
		Llist();							//Default c'tor
		Llist(const Llist & list); 
		
		void InsertOrdered(City * data);	//Insert City data into linked list Alphabetically 
		Node * NSearch(char * c_target); 
		bool Delete(char * c_target);		//Delete City data - return t/f 
		
		Node * GetHead();
		Node * GetTail();

		void LLPrintAll(ofstream& DataOut);

		~Llist();			
	private:
		int m_nodecount;			//variable to represent how many nodes total in linked list 
		Node * m_head;				//head node 
		Node * m_tail;				//tail node 
};
#endif