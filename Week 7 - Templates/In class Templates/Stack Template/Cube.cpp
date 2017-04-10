#include<iostream>
using std::cout;
using std::endl; 

#include "Cube.h"

Cube::Cube()
{
	cout << "cube no arg c'tor" << endl; 
}

Cube::Cube(int side)
{
	cout << "cube 1 arg c'tor" << endl; 
	m_side = side; 
}

Cube::Cube(const Cube & c)
{
	m_side = c.m_side; 
}

Cube & Cube::operator=(const Cube & c)
{
	cout << "cube op=" << endl; 
	if (this != &c)
	{
		m_side = c.m_side;
	}

	return *this; 
}

void Cube::Display()
{
	cout << "Number of sides on cube: " << m_side << endl; 
}

int Cube::GetSide()
{
	return m_side; 
}

Cube::~Cube()
{
	cout << "in cube d'tor" << endl; 
}
