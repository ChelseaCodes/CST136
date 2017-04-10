#ifndef Exception_h
#define Exception_h

#include<iostream>
using std::cout;
using std::endl; 

const int MAX(50);

class Exception
{
public:
	Exception(char * filename, char * methodname, char * message); 

	char * GetFileName();
	char * GetMethodName();
	char * GetMessage(); 

	~Exception();
private:
	char m_fileName[MAX]; 
	char m_methodName[MAX]; 
	char m_message[MAX];
};
#endif // !Exception_h

