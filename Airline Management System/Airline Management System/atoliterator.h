/************************************************************************
* Class: atoliterator.h
*
* Purpose: This class is an A to L iterator, iterating through Cities 
*		with names A through L. Inherits from BaseIterator
*
* Manager functions:
* 	AtoLIterator()
*		default CityList is nullptr
*	AtoLIterator(Llist * citylist)
*		set CityList to passed list
*	~AtoLIterator()
*
* Methods:
*	void First()
*		sets to head of CityList
*	MoveNext()
*		moves to next city A through L 
*	IsDone()
*		done when cursor points to first "M" City
*	Node * GetCurrent()
*
*************************************************************************/
#ifndef atoliterator_h
#define atoliterator_h
#include"baseiterator.h"

class AtoLIterator : public BaseIterator
{
	public:
		AtoLIterator(); 
		AtoLIterator(Llist * citylist); 

		void First(); 
		void MoveNext(); 
		bool IsDone(); 
		Node * GetCurrent(); 

		~AtoLIterator(); 
};


#endif