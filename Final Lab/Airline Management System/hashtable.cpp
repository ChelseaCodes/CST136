#include "hashtable.h"

HashTable::HashTable()
{
	for (int i(0); i < TABLESIZE; i++)
	{
		m_hash_table[i] = nullptr; 
	}
}

void HashTable::Prepend(City* city, Flight* flight)
{
	//first create the node to prepend
	HashNode * nn = new HashNode(city, flight); 

	int index = Hash(flight->GetName()); 

	if(m_hash_table[index] == nullptr)
	{
		m_hash_table[index] = nn; 
		nn->setNext(nullptr); 
		nn->setPrevious(nullptr);
	}
	else
	{
		nn->setNext(m_hash_table[index]);	//nn next is current node
		nn->getNext()->setPrevious(nn);		//current node's prev is nn
		m_hash_table[index] = nn; 
	}

}

HashTable::~HashTable()
{
	for (int i(0); i < TABLESIZE; i++)
	{
		HashNode * temp = m_hash_table[i];
		HashNode * trail = nullptr;
		while (temp != nullptr)
		{
			trail = temp;
			temp = temp->getNext();
			delete trail;
		}
	}
}

int HashTable::Hash(char flightname[])
{
	int length = strlen(flightname); 
	int name_total = 0;
	int key = 0;

	for(int i(0); i < length; i++)
	{
		name_total += static_cast<int>(flightname[i]); 
	}

	key = name_total & 7; 

	return key; 
}

bool HashTable::DeleteFlight(char * flight)
{
	HashNode * node_delete = Search(flight);	//search returns the node to delete 
	int index = Hash(flight); 

	if(node_delete != nullptr)
	{
		//if node_del is head ptr
		if(m_hash_table[index] == node_delete)
		{
			m_hash_table[index] = node_delete->getNext(); //set head ptr to deleted nodes nxt
			m_hash_table[index]->setPrevious(nullptr);
			delete node_delete; 

			return true; 
		}
		else
		{
			HashNode * prev = node_delete->getPrevious();	

			prev->setNext(node_delete->getNext());	//set node before one to del to del's nxt
			node_delete->getNext()->setPrevious(prev);	//set del's next's prev to one before
			delete node_delete;
			prev = node_delete; 
			return true;
		}
	}
	return false; 

}

HashNode* HashTable::getHead(int index)
{
	return m_hash_table[index];
}

void HashTable::PrintHistogram()
{
	for (int i(0); i < TABLESIZE; i++)
	{
		std::cout << i + 1 << ".";
		if(m_hash_table[i] != nullptr)
		{
			HashNode * travel = m_hash_table[i];
			
			while(travel != nullptr)
			{
				std::cout << "x";
				travel = travel->getNext(); 
			}
		}
		std::cout << std::endl; 
	}
}

HashNode* HashTable::Search(char* target)
{
	int index = Hash(target); 
	HashNode * temp = m_hash_table[index];

	while (temp != nullptr)
	{
		if (*temp->getFlight() == target)
		{
			return temp;
		}
		else
			temp = temp->getNext();
	}
	return nullptr;
}
