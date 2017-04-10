/************************************************************************
* Class: skipiterator.h
*
* Purpose: This class is a skip iterator for linked list, inherits 
*	from GenericIterator
*
* Manager functions:
* 	SkipIterator()
*		default CityList is nullptr
*	SkipIterator(Llist * citylist)
*		set CityList to passed list
*	~SkipIterator()
*
* Methods:
*	First()
*		calls GenericIterator::First()
*	MoveNext()
*		calls GenericIterator::MoveNext twice
*	IsDone()
*	Node * GetCurrent()
*
*************************************************************************/
#ifndef skipiterator_h
#define skipiterator_h

#include"genericiterator.h"

class SkipIterator : public GenericIterator
{
	public:		
		SkipIterator();
		SkipIterator(Llist * citylist);

		void First(); 
		void MoveNext();
		bool IsDone();
		Node * GetCurrent(); 

		~SkipIterator(); 
};

#endif
