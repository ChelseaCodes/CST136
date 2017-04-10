/************************************************************************
* Class: flist.h
*
* Purpose: This class is the flight linked list, containing flight 
*		nodes, which have flight objects. 
*
* Manager functions:
* 	FLList()
*		default nodecount is 0, head and tail are nullptr 
*	FLList(const FLList & list_copy)
*	~FLList()
*		purges list of all nodes
*
* Methods:
*	InsertOrdered(Flight * data)
*		insert flight data into flight list in order
*	FNode * NSearch(char * f_target)
*		searches list for flight by code or name (not used)
*	bool Delete(char * f_target)
*		deletes flights by code or name (not used)
*	FNode * GetHead()
*	FNode * GetTail()
*	FLLPrintAll(ofstream& DataOut)
*		print all flight information to txt file 
*
*************************************************************************/
#ifndef fllist_h
#define fllist_h

#include<fstream>
using std::ofstream;

#include "flight.h"
#include "fnode.h"

class FLList
{
	friend class FNode;
public:
	FLList();							//Default c'tor
	FLList(const FLList & list_copy);	//copy c'tor

	void InsertOrdered(Flight * data);	//Insert City data into linked list Alphabetically 
	FNode * NSearch(char * f_target);
	bool Delete(char * f_target);		//Delete City data - return t/f 

	FNode * GetHead();
	FNode * GetTail();

	void FLLPrintAll(ofstream& DataOut);

	~FLList();							//D'tor 

private:
	int m_nodecount;			//variable to represent how many FNodes total in linked list 
	FNode * m_head;				//head FNode 
	FNode * m_tail;				//tail FNode 
};




#endif
