#include<iostream>
using std::cout;
using std::endl; 

#include "CubeStack.h"
#include "Exception.h"

CubeStack::CubeStack()
{
	cout << "In CS no arg c'tor" << endl;
	m_size = 0; 
}

void CubeStack::Push(const Cube & cube)
{
	cout << "Pushing" << endl; 
	if (IsFull())
	{
		//exception handling
		//1st way to handle
		//throw("Stack is Full");		//caught in main
		throw(Exception("CubeStack.cpp", "Push", "Cant push on a full stack"));	//perhaps this 10 means - pushed on full stack
	}
	//no reason for an else stmnt 
	m_stack[m_size++] = cube; //this will call op=
}

Cube CubeStack::Pop()
{
	cout << "Popping" << endl;
	if (IsEmpty())
	{
		//exception handling 
		throw("Stack is Empty");		//caught in main
	}
	else
		return m_stack[--m_size];
}

bool CubeStack::IsFull()
{
	return m_size == 5;
}

bool CubeStack::IsEmpty()
{
	return m_size == 0;
}

int CubeStack::GetSize()
{
	return m_size;
}

CubeStack::~CubeStack()
{
	cout << "CS d'tor" << endl; 
}


