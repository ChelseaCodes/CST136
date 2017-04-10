#include<iostream>
using std::cout; 
using std::endl; 

#include "StrClass.h"


StrClass::StrClass()
{
	cout << "StrClass no arg c'tor" << endl;
	m_nLength = 0; 
}

StrClass::StrClass(char * name)
{
	cout << "StrCLass one arg c'tor" << endl; 
	strcpy(m_sBuffer, name);
	m_nLength = StrLen();
	next = nullptr; 
}


int StrClass::StrLen()
{
	int count(0); 
	char * buffptr = m_sBuffer; 
	char * startptr = buffptr; 

	while (*buffptr != '\0')
	{
		buffptr++; 		
	}

	count = buffptr - startptr; 
	return count; 
}

void StrClass::Display()
{
	for (int i(0); i < StrLen(); i++)
	{
		cout << m_sBuffer[i]; 
	}
	cout << "(" << StrLen() << ")";
}

bool StrClass::IsEmpty()
{
	if (m_sBuffer[0] == '\0')	//if the first element is a  null - it's empty - true 
		return true;
	else
		return false;			//otherwise it has things in it. 
}

StrClass::~StrClass()
{}

//Setters and Getters
void StrClass::SetLength(int length)
{
	if (length < 0)
	{
		cout << "Can't assign a length less than zero" << endl;
	}
	else
		m_nLength = length; 
}

int StrClass::GetLength()
{
	(StrLen() > 10) ? m_nLength = StrLen() + 4 : m_nLength = StrLen() + 3;
	return m_nLength; 
}

char * StrClass::GetBuffer()
{
	char * ptr_buff = m_sBuffer; 
	return ptr_buff; 
}

StrClass * StrClass::GetNext()
{
	return next;
}

void StrClass::SetNext(StrClass * n)
{
	next = n; 
}

char * StrClass::GetBuff()
{
	return m_sBuffer;
}

void StrClass::SetBuff(char * buff)
{
	strcpy(m_sBuffer, buff); 
}
