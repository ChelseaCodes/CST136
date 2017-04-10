#include "Exception.h"

Exception::Exception(char * filename, char * methodname, char * message)
{
	strcpy(m_fileName, filename);
	strcpy(m_methodName, methodname);
	strcpy(m_message, message); 
}

char * Exception::GetFileName()
{
	return m_fileName;
}

char * Exception::GetMethodName()
{
	return m_methodName;
}

char * Exception::GetMessage()
{
	return m_message;
}

Exception::~Exception()
{
}
