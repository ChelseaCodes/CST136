#pragma once
#include "Cube.h"

using namespace std; 

const int MAX_STACK(5); 

class CubeStack
{
	public:
		CubeStack();

		void Push(const Cube& cube);	//what you want to push onto the stack
		Cube Pop();						//pop what was on the top of the stack
		bool IsFull();					//is the stack full?
		bool IsEmpty();					//is the stack empty?

		int GetSize(); 
		~CubeStack(); 

	private:
		Cube m_stack[MAX_STACK];
		int m_size; 
};