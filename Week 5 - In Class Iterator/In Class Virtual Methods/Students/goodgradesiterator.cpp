#include "goodgradesiterator.h"

GoodGradesIterator::GoodGradesIterator()
{
	cout << "in no arg GG iterator" << endl; 
	m_score = 0;
}

GoodGradesIterator::GoodGradesIterator(Student * s, int score):
	BaseIterator(s)
{
	cout << "In 2 arg GG iterator" << endl; 
	m_score = score;
}

void GoodGradesIterator::First()
{
	m_cursor = 0; 

	//not at the end, and score is less than score passed; inc. cursor
	while (!IsDone() && students[m_cursor].m_score < m_score)
	{
		m_cursor++; 
	}
}

void GoodGradesIterator::MoveNext()
{
	m_cursor++; 

	//not at the end, and score is less than score passed; inc. cursor
	while (!IsDone() && students[m_cursor].m_score < m_score)
	{
		m_cursor++;
	}
}

bool GoodGradesIterator::IsDone()
{
	return m_cursor > 5; 
}

Student & GoodGradesIterator::GetCurrent()
{
	if (IsDone())
		cout << "Maybe throw an exception" << endl;

	return students[m_cursor]; 
}

GoodGradesIterator::~GoodGradesIterator()
{
	cout << "In GG iterator d'tor" << endl; 
	m_cursor = 0;
	m_score = 0; 
}
