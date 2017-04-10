/************************************************************************
* Class: node.h
*
* Purpose: This class holds all City information, used in linked list
*
* Manager functions:
* 	Node()
*		default next and previous pointers are nullptr 
*	Node(City * c_new)
*		set private City * member to passed City pointer
*	Node(const Node& c_node)
*	Node& operator=(const Node& c_node)
*	~Node()
*		Deletes city data
*
* Methods:
*	char * GetName()
*	char * GetCode()
*	char * GetMan()
*	char * GetPhone()
*	FLList * GetCityFlights()
*	Node * GetNext()
*	Node * GetPrevious()	
*	friend ostream& operator<< (ostream& os, Node * data)
*		overloaded << for output to txt file 
*************************************************************************/
#ifndef node_h
#define node_h

#include<iostream>
using std::ostream;

#include "city.h"

class Node
{
	friend class Llist; 
	public:
		Node();						//Default c'tor 
		Node(City * c_new);			//One arg c'tor Passed in a City obj.
		Node(const Node & c_node);				//Copy c'tor 
		Node & operator=(const Node & c_node);	//Operator= 

		char * GetName();
		char * GetCode();
		char * GetMan();
		char * GetPhone();
		FLList * GetCityFlights(); 

		Node * GetNext();
		Node * GetPrevious();
		
		friend ostream& operator<< (ostream& os, Node * data);		//overloaded << for output 

		~Node();	

	private:
		City * m_data;				//Contains a City object
		Node * m_next;				//Pointer to next node
		Node * m_previous;			//ptr to previous node 

};

#endif 
