#include "engine.h"

Engine::Engine(int pistons)
{
	m_num_of_pistons = pistons; 
	m_pistonptr = new Piston[pistons]; 
}

void Engine::Display()
{
	cout << "i am an engine" << endl;
	for (int i(0); i < m_num_of_pistons; i++)
	{
		m_pistonptr[i].Display(); 
	}
}

Engine::~Engine()
{
	cout << "Engine dies" << endl; 
	delete[] m_pistonptr; 
}

Engine::Piston::Piston()
{
	cout << "piston default c'tor" << endl; 
}

void Engine::Piston::Display()
{
	cout << "I'm a piston" << endl;
}

Engine::Piston::~Piston()
{
	cout << "piston dies" << endl; 
}

