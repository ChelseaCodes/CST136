#pragma once

#include "ClassA.h"

class ClassA; 
class ClassB
{	public:
		ClassB();
		~ClassB();

	private:
		ClassA * aptr; 

};