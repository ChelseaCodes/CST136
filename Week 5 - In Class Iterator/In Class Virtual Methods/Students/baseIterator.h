#ifndef BASEITERATOR_H
#define BASEITERATOR_H
#include<iostream>
using std::cout; 
using std::cin; 

#include "student.h"
//this is an abstract class since it is PURE VIRTUAL 
class BaseIterator
{
	public:
		BaseIterator();
		BaseIterator(Student * s); 

		virtual void First() = 0;
		virtual void MoveNext() = 0; 
		virtual bool IsDone() = 0; 
		virtual Student& GetCurrent() = 0; 

		virtual ~BaseIterator(); 

	protected:		//cant be private otherwise derived class cant see info 
		int m_cursor; 
		Student * students;		//needs the collection 
};
#endif