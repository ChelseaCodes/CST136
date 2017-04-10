/************************************************************************
* Class: fnode.h
*
* Purpose: This class holds flight data in a node, which is inserted
*		to flight linked list 
*
* Manager functions:
* 	FNode()
*		next pointer is nullptr 
*	FNode(Flight * f_new)
*		set flight data to data passed in 
*	FNode(const FNode & newnode)
*	FNode & operator=(const FNode & newnode)
*	~FNode()
*		delete flight data 
*
* Methods:
*	char * GetCode()
*	char * GetName()
*	char * GetMan()
*	char * GetDest()
*	int GetDist()
*	int GetCost()
*	friend ostream& operator << (ostream& os, FNode * data)
*		output flight information to txt file 
*
*************************************************************************/
#ifndef fnode_h
#define fnode_h

#include<iostream>
using std::ostream;

#include"flight.h"
#include"fllist.h"

class FNode
{
	friend class FLList;
public:
	FNode();					//Default c'tor 
	FNode(Flight * f_new);		//One arg c'tor Passed in a City obj
	FNode(const FNode & newnode); 
	FNode & operator=(const FNode & newnode); 

	char * GetCode();
	char * GetName();
	char * GetMan();
	char * GetDest();
	int GetDist();
	int GetCost(); 

	friend ostream& operator << (ostream& os, FNode * data);

	~FNode();					//D'tor
private:
	Flight * m_data;				//Contains a City object
	FNode * m_next;				//Pointer to next FNode 
};
#endif 
