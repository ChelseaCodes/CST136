/************************************************************************
* Class: mtoziterator.h
*
* Purpose: This class is an M to Z iterator, iterating through cities 
*		with names M through Z. Inherits from BaseIterator
*
* Manager functions:
* 	MtoZIterator()
*		default CityList is nullptr
*	MtoZIterator(Llist * citylist)
*		set CityList to passed list
*	~MtoZIterator()
*
* Methods:
*	First()
*		moves cursor to first "M" city in CityList
*	MoveNext()
*		moves to next city with names M through Z
*	IsDone()
*	Node * GetCurrent()
*
*************************************************************************/
#ifndef mtoziterator_h
#define mtoziterator_h
#include"baseiterator.h"

class MtoZIterator : public BaseIterator
{
	public:
		MtoZIterator();
		MtoZIterator(TLList<City> * citylist);

		void First();
		void MoveNext(); 
		bool IsDone();
		Node<City> * GetCurrent();

		~MtoZIterator(); 
};

#endif
