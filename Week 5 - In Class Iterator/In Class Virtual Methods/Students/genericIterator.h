#ifndef GENERICITERATOR_H
#define GENERICITERATOR_H	

#include"baseIterator.h"

//Generic iterator is a concrete class. Can "new" this, NOT baseiterator 
class GenericIterator : public BaseIterator
{

	public:
		GenericIterator();
		GenericIterator(Student * s); 

		void First(); 
		void MoveNext();
		bool IsDone(); 
		Student& GetCurrent(); 

		virtual ~GenericIterator();
};
#endif
