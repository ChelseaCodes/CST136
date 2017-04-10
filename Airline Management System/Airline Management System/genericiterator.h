/************************************************************************
* Class: genericiterator.h
*
* Purpose: This class is a generic iterator for city linked list, 
*		inherits from BaseIterator
*
* Manager functions:
* 	GenericIterator()
*		default CityList is nullptr
*	GenericIterator(Llist * citylist)
*		set CityList to passed list
*	~GenericIterator()
*
* Methods:
*	First()
*	MoveNext()
*	IsDone()
*	Node * GetCurrent()
*
*************************************************************************/
#ifndef genericiterator_h
#define genericiterator_h

#include"baseiterator.h"

class GenericIterator : public BaseIterator
{
	public:
		GenericIterator();
		GenericIterator(Llist * citylist); 

		void First(); 
		void MoveNext();
		bool IsDone(); 
		Node * GetCurrent(); 

		~GenericIterator();
};
#endif 

