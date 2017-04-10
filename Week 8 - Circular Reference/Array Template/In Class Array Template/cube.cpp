#include "cube.h"

Cube::Cube() : m_side(0)
{
	//cout << "default Cube c'tor" << endl; 
}

Cube::Cube(int size) :m_side(size)
{
	//cout << "1 arg Cube c'tor" << endl;
}

Cube::Cube(const Cube& copy) : m_side(copy.m_side)
{
	cout << "copy c'tor " << endl;
}

void Cube::Display()
{
	cout << m_side << endl; 
}

Cube::~Cube()
{
	//cout << "Cube d'tor" << endl; 
	m_side = 0; 
}