#pragma once
#include<iostream>
using std::cout;
using std::endl; 

//
class Cube
{
	public:
		Cube();
		Cube(int size);
		Cube(const Cube& copy);
		void Display(); 
		~Cube();

	private:
		int m_side;
};