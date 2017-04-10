#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Control.h"

const int MAX(10);			//max names is 10 

Control::Control()
{
	cout << "No arg c'tor control" << endl; 
	head = nullptr;
	tail = nullptr; 
	m_nNamesPerLine = 0; 
	m_nTotalNodes = 0; 
}
Control::Control(int numbers)
{
	head = nullptr;
	tail = nullptr; 
	m_nTotalNodes = 0; 

	SetPerLine(numbers); 
	
}
Control::~Control()
{
	cout << "deleting list" << endl;
	StrClass * trail = nullptr;
	while (head != nullptr)
	{
		trail = head;
		head = head->GetNext();
		delete trail; 
	}
}
void Control::CreateNode(char * info)
{
	if (m_nTotalNodes != MAX)
	{
		StrClass * n = new StrClass(info);			//create node by passing in information
		InsertOrdered(n);
		m_nTotalNodes++;			//update total nodes 
	}
	else
		cout << "Too many names, insert failed" << endl; 
}

void Control::InsertOrdered(StrClass * name)
{
	StrClass * travel = head;
	StrClass * trail = nullptr;
	StrClass * nn = nullptr;
	nn = new StrClass(*name);

	if ((head == nullptr) || (stricmp(name->GetBuffer(), head->GetBuffer()) <= 0))
	{
		nn->SetNext(head);		//set next to head
		head = nn;				//head is new node 

		StrClass * temp = head;
		while (temp->GetNext() != nullptr)	//while next isn't null
			temp = temp->GetNext();			//traverse 

		tail = temp;
	}
	else
	{
		while ((travel != nullptr) && (stricmp(name->GetBuff(), travel->GetBuff()) >= 0))
		{
			trail = travel;
			travel = travel->GetNext();
		}
		trail->SetNext(nn);
		nn->SetNext(travel);
	}

	if (tail->GetNext() != nullptr)
	{
		tail = tail->GetNext();
	}
}

void Control::DisplayAlgorithm()
{
	//will use the names per line
	int namesPer = m_nNamesPerLine; 
	int node_count = 0;				
	int char_count = 0; 

	while (node_count != (GetTotalNodes() + 1))
	{
		namesPer = m_nNamesPerLine;

		char_count = GetCharCount(namesPer, node_count) + (namesPer - 1);

		while (char_count >= 80)									//while the total count is greater than 80
		{
			char_count = GetCharCount(--namesPer, node_count) + (namesPer - 1);	//figure out how many names per line i CAN do 
		}

		node_count = DisplayConsole(namesPer, node_count);
		
	}
}

int Control::DisplayConsole(int namesPer, int node_count)
{
	int count = 0; 
	StrClass * temp = head;
	for (int j(0); j < node_count; j++)		//second time in: traverse to last count
	{
		temp = temp->GetNext();		//traverse as many times for as many nodes 
	}

	while ((count != namesPer) && (temp != nullptr))	//counts how many chars for how many lines wanted
	{
		++count;
		temp->Display();
		node_count++;
		cout << " ";
		temp = temp->GetNext();
	}
	cout << endl;

	return node_count; 
}

int Control::GetCharCount(int names_per_line, int index)
{
	int char_count = 0;
	int count = 0; 
	StrClass * temp = head;
	for (int j(0); j < index; j++)		//second time in: traverse to last place 
	{
		temp = temp->GetNext();		//traverse as many times for as many nodes 
	}
	
	while ((count != names_per_line) && (temp->GetNext() != nullptr))	//counts how many chars for how many lines wanted
	{
		++count;
		char_count += temp->GetLength();
		temp = temp->GetNext();
	}

	return char_count; 
}

int Control::GetTotalNodes()
{
	int count(0); 
	
	StrClass * travel = head;
	while (head != nullptr && travel->GetNext() != nullptr)
	{
		count++; 
		travel = travel->GetNext(); 
	}

	return count; 
}

void Control::SetHead(StrClass * h)
{
	head = h;
}

StrClass * Control::GetHead()
{
	return head;
}

void Control::SetTail(StrClass * t)
{
	if (t != nullptr)
	{
		StrClass * temp = head;
		while (temp->GetNext() != nullptr)
			temp = temp->GetNext(); 

		tail = temp; 
	}
}

StrClass * Control::GetTail()
{
	return tail;
}

void Control::SetPerLine(int number)
{
	if (number < 0)
	{
		cout << "Can't set below Zero" << endl;
	}
	else
		m_nNamesPerLine = number; 
}