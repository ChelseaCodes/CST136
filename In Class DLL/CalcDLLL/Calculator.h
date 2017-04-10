#pragma once

//create the namespace
namespace CalcDll
{
	//the _declspec -declaration specification
	//class is now available to the exe
	class _declspec(dllexport) Calculator
	{
	public:
		int Add(int x, int y);
		//following: would make ONLY Add funct avail to the .exe
		//_declspec(dllexport)int Add(int x, int y);
		int Sub(int x, int y);
		int Mult(int x, int y);
		int Div(int x, int y);
	};
	//need to add code to generate the lib file
	//this is so the .exe knows what it can do 
	//
}

