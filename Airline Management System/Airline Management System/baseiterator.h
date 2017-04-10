/************************************************************************
* Class: baseiterator.h
*
* Purpose: This abstract base class defines a base iterator to be used
*		for deriving other iterators.
*
* Manager functions:
* 	BaseIterator()
*		default cursor is 0, city linked list is nullptr
*	BaseIterator(Llist * citylist)
*		sets city linked list to passed list, cursor set to head of list
*	~BaseIterator()
*
* Methods:
*	virtual void First() = 0
*		initialize cursor to first element in CityList
*	virtual void MoveNext() = 0
*		traverse to next element
*	virtual bool IsDone() = 0
*		true when past last element
*	virtual Node * GetCurrent() = 0
*		pointer to current node
*
*************************************************************************/
#ifndef baseiterator_h
#define baseiterator_h

#include"llist.h"

class BaseIterator
{
	friend class Llist; 
	public:
		BaseIterator();						//no arg c'tor 
		BaseIterator(Llist * citylist);		//one arg c'tor, passed linked list with city nodes

		virtual void First() = 0;			//initialize cursor to first element in CityList
		virtual void MoveNext() = 0;		//traverse to next element
		virtual bool IsDone() = 0;			//true when past last element
		virtual Node * GetCurrent() = 0;	//ptr to current node 
		
		virtual ~BaseIterator();			//virtual d'tor 
	protected:	
		Node * m_cursor; 
		Llist * CityList;
};
#endif 
