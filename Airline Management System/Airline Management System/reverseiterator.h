/************************************************************************
* Class: reverseiterator.h
*
* Purpose: This class is an iterator that iterates through linked list
*		backwards. Inherits from BaseIterator.
*
* Manager functions:
* 	ReverseIterator()
*		default CityList is nullptr
*	ReverseIterator(Llist * citylist)
*		set CityList to passed list
*	~ReverseIterator()
*
* Methods:
*	First()
*		cursor set to CityList tail
*	MoveNext()
*		moves to previous node in CityList
*	IsDone()
*	Node * GetCurrent()
*
*************************************************************************/
#ifndef reverseiterator_h
#define reverseiterator_h 
#include "baseiterator.h"

class ReverseIterator : public BaseIterator
{
	public:
		ReverseIterator();
		ReverseIterator(Llist * citylist); 

		void First();
		void MoveNext();
		bool IsDone();
		Node * GetCurrent(); 

		~ReverseIterator(); 
};
#endif