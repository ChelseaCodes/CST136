/*************************************************************
* Author:		Chelsea Christison
* Filename:		main.cpp
* Date Created:	02.17.2017
* Modifications:
**************************************************************/
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

#include<iostream>
using std::cout;
using std::cin; 
using std::endl; 

#include"controller.h"
#include"city.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Controller C0; 
	C0.ReadAndFill();
	C0.ReadAndExecute(); 

	

	return 0; 
}