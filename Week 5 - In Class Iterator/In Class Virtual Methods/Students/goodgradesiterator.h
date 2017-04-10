#ifndef GoodGradesIterator_H
#define GoodGradesIterator_H
#include<iostream>
using std::cout;
using std::endl; 

#include"genericIterator.h"

class GoodGradesIterator : public BaseIterator
{
	friend class Student; 
public:
	GoodGradesIterator();
	GoodGradesIterator(Student * s, int score); 
	void First(); 
	void MoveNext();
	bool IsDone();
	Student & GetCurrent(); 

	~GoodGradesIterator(); 
private:
	int m_score; 
};


#endif

