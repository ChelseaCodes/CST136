#pragma once
#include "ClassB.h"

class ClassA
{
	public:
		ClassA();
		~ClassA();

	private:
		ClassB * bptr;
};