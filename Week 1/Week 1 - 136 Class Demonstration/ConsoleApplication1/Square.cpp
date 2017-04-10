#include "Square.h"; 

//Method Definitions
//using :: (scope resolution operator) says "This method belongs to this class" 
Square::Square()
{
	cout << "Creating default Square - no arg c'tor" << endl;				//For now, always cout to see where and which c'tors are being called
	m_size = 0;																//always initialize to a default value 
}
Square::Square(int size)
{
	cout << "Creating Square using size - one arg c'tor" << endl; 

	if (size < 0)
	{
		cout << "Size can't be a negative number" << endl;
	}
	else
		m_size = size;
}

Square::Square(const Square& s)
{
	cout << "in copy c'tor " << endl;
	m_size = s.m_size;						//copying over. no getter since inside own class 
}

Square& Square::operator= (const Square& s)	//returning a square, dereference the square b/c returned a pointer
{
	cout << "in op =" << endl; 
	m_size = s.m_size; 
	//this ->m_size = s.m_size as well also works.  
	return *this; 
}
/*
* Do you always need setters and getters? depends on what
* data members to access, set or get. getters are usually
* going to be used. Setters only when you need to
*/
int Square::GetSize()
{
	return m_size; 
}

void Square::SetSize(int size)
{
	if (size < 0)
	{
		cout << "Size can't be a negative number" << endl;
	}
	else
		m_size = size; 
}

void Square::Display()
{
	cout << "Size of Square is: " << m_size << endl; 
}

Square::~Square()
{
	cout << "Destructing Square - D'tor" << endl; 
}