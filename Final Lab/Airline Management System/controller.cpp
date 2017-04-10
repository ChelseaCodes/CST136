/*************************************************************
* Author:		Chelsea Christison
* Filename:		controller.cpp
* Date Created:	02.17.2017
* Modifications:	2.20.2017 - fixed output formatting
*	 3.14 - 
**************************************************************/
#include<iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;
using std::setfill;
using std::right; 

#include<fstream>
using std::ifstream;
using std::ofstream; 

#include "controller.h"		

const int MAX(15); 

Controller::Controller():m_echo(true)
{
	cout << "Default Controller c'tor" << endl; 

	//open file, create new City list
	DataOut.open("CST136Output.txt"); 
	m_AirList = new TLList<City>(); 
	m_flight_hash_table = new HashTable(); 
	//instantiate all iterators
	GenericIterator * GenIter = new GenericIterator(m_AirList);
	SkipIterator * SkipIt = new SkipIterator(m_AirList);
	AtoLIterator * ALit = new AtoLIterator(m_AirList);
	MtoZIterator * MZit = new MtoZIterator(m_AirList);
	ReverseIterator * RevIt = new ReverseIterator(m_AirList);

	//add iterators into base class * array
	iterators[0] = GenIter;
	iterators[1] = SkipIt;
	iterators[2] = ALit;
	iterators[3] = MZit;
	iterators[4] = RevIt;
}

void Controller::ReadAndFill()
{
	ifstream ReadData("AirData3.txt");

	//city buffers
	char buff_c[5] = { '\0' };
	char buff_n[11] = { '\0' };
	char buff_m[11] = { '\0' };
	char buff_p[11] = { '\0' };
	int t_fl(0);

	//flight buffers
	char buff_fcode[5] = { '\0' };
	char buff_fname[11] = { '\0' };
	char buff_fmana[11] = { '\0' };
	char buff_fdest[11] = { '\0' };
	int f_dist(0);
	int f_cost(0);

	if (ReadData.is_open())
	{
		while (ReadData.good())
		{
			while (!ReadData.eof())
			{
				ReadData >> buff_c >> buff_n >> buff_m >> buff_p >> t_fl;

				//Full city read and insert
				City * new_city = new City(buff_c, buff_n, buff_m, buff_p, t_fl);
				Node<City> * nn = new Node<City>(new_city);

				//full flight read and insert
				for (int i(0); i < t_fl; i++)
				{
					ReadData >> buff_fcode >> buff_fname >> buff_fmana >> buff_fdest >> f_dist >> f_cost;

					Flight * new_flight = new Flight(buff_fcode, buff_fname, buff_fmana, buff_fdest, f_dist, f_cost); 
					Node<Flight> * nfn = new Node<Flight>(new_flight);

					new_city->InsertIntoFlightList(nfn); 

					//Hash Time 
					m_flight_hash_table->Prepend(new_city, new_flight);
				}
				m_AirList->InsertOrdered(nn);
			}
			ReadData.close();
			m_flight_hash_table->PrintHistogram(); 
		}
	}
	else
		cout << "file could not open!" << endl; 

}

void Controller::ReadAndExecute()
{
	ifstream ReadFile("Commands.txt");

	if (ReadFile.is_open())
	{
		while (ReadFile.good())
		{
			char buffer[25] = { '\0' };

			ReadFile >> m_com;

			switch (m_com[0])
			{
				case 'P':
				{
					char * c_tar = 0;	//city target

					if (m_com[1] == 'A')	//print all 
						PrintAll(); 
					else				//print what's in the buff - or error 
					{
						City * temp = nullptr;

						ReadFile >> buffer; 

						c_tar = new char[strlen(buffer) + 1];
						strcpy(c_tar, buffer); 

						temp = m_AirList->Search(c_tar);

						if (temp != nullptr)
							PrintDataTo(temp);
						else
							PrintErr(c_tar);
						
						delete[] c_tar; 
					}			
					break;
				}
				
				case 'D':
				{
					char * c_tar = 0;
					
				 	ReadFile >> buffer; 

					c_tar = new char[strlen(buffer) + 1];
					strcpy(c_tar, buffer); 

					Delete(c_tar); 

					delete[] c_tar; 
					m_flight_hash_table->PrintHistogram();
					break; 
				}
				case 'E':
				{
					if (m_com[1] == 'C')
					{
						m_echo = !m_echo;	//toggle echo
					}
					else
						PrintExit(); 
					break;
				}
				case 'L':
					{
						if(m_com[1] == 'F')
						{
							char * f_tar = 0;

							ReadFile >> buffer;

							f_tar = new char[strlen(buffer) + 1];
							strcpy(f_tar, buffer);

							PrintHashFlights(f_tar);

							delete[] f_tar; 
						}
						else
						{
							char * f_tar = 0;

							ReadFile >> buffer;

							f_tar = new char[strlen(buffer) + 1];
							strcpy(f_tar, buffer);

							PrintHashChain(f_tar); 

							delete[] f_tar; 
						}
						break;
					}

				default:
					break;
			}
		}
		ReadFile.close();
	}
}

void Controller::Delete(char * c_tar)
{
	City * city = m_AirList->Search(c_tar); 
	if (city == nullptr)
		PrintErr(c_tar);
	else
	{
		DeleteHashFlights(c_tar);
		m_AirList->Delete(c_tar);
		PrintConfirm(c_tar);
	}
}

void Controller::DeleteHashFlights(char * c_tar)
{
	City * city = m_AirList->Search(c_tar);

	Node<Flight> * travel = city->GetFlightList()->GetHead();

	while (travel != nullptr)
	{
		char * flname = travel->GetData()->GetName();
		m_flight_hash_table->DeleteFlight(flname);
		travel = travel->GetNext();
	}
}

void Controller::PrintHashFlights(char* f_tar)
{
	HashNode * temp = m_flight_hash_table->Search(f_tar); 

	if(temp != nullptr)
	{
		if (m_echo)
		{
			if (DataOut.is_open())
			{
				DataOut << m_com << endl;
				DataOut << temp->getCity() << '\n' << "- "
						<< temp->getFlight()<< '\n' << endl;

			}
			else
				cout << "Could not write to file" << endl;
		}
		else
		{
			if (DataOut.is_open())
			{
				DataOut << temp->getCity() << '\n' << "- "
					<< temp->getFlight() << '\n' << endl;

			}
		}
	}
	else
	{
		PrintErr(f_tar); 
	}
}

void Controller::PrintHashChain(char* f_tar)
{
	HashNode * temp = m_flight_hash_table->Search(f_tar);

	if (temp != nullptr)
	{
		if (m_echo)
		{
			if (DataOut.is_open())
			{
				DataOut << m_com << endl;
				while(temp != nullptr)
				{
					DataOut << "- " << temp->getFlight()
							<< endl;

					temp = temp->getNext(); 
				}
				cout << endl << endl; 
			}
			else
				cout << "Could not write to file" << endl;
		}
		else
		{
			if (DataOut.is_open())
			{
				while (temp != nullptr)
				{
					DataOut << "- " << temp->getFlight()
						<< endl;

					temp = temp->getNext();
				}
				cout << endl << endl; 
			}
		}
		
	}
	else
	{
		if(m_echo)
			DataOut << m_com << endl;

		DataOut << "- " <<f_tar << endl; 
		int index = m_flight_hash_table->Hash(f_tar);
		temp = m_flight_hash_table->getHead(index);

		while (temp != nullptr)
		{
			DataOut << temp->getCity() << '\n'
				<< temp->getFlight() << endl;

			temp = temp->getNext();
		}
	}
}

void Controller::PrintErr(char * c_tar)
{
	if (m_echo)
	{
		if (DataOut.is_open())
		{
			DataOut << m_com << endl; 
		}
		else
			cout << "Could not write to file" << endl;
	}
	
	if (DataOut.is_open())
	{
		DataOut<< "Could not find " << c_tar << '\n' << endl;
	}
	else
		cout << "Could not write to file" << endl;
	
}


void Controller::PrintConfirm(char * c_tar)
{
	if (m_echo)
	{
		if (DataOut.is_open())
		{
			DataOut << m_com << endl; 
		}
		else
			cout << "Could not write to file" << endl;
	}
	if (DataOut.is_open())
	{
		DataOut << "Deleted " << c_tar << " from AirList\n" << endl;
	}
	else
		cout << "Could not write to file" << endl;
}

void Controller::PrintDataTo(City * data)
{
	if (m_echo)
	{
		if (DataOut.is_open())
		{
			DataOut << m_com << endl; 
		}
		else
			cout << "Could not write to file" << endl;
	}
	if (DataOut.is_open())
	{
		DataOut << "Found:\n";
		DataOut << data << "\n";
		data->GetFlightList()->PrintAll(DataOut);
		DataOut << "--\n" << endl; 
	}
	else
	cout << "Could not write to file" << endl;
}

void Controller::PrintAll()
{
	if (m_echo)
	{
		if (DataOut.is_open())
		{
			DataOut << m_com << endl;
		}
		else
			cout << "could not open file" << endl; 
	}

	if (DataOut.is_open())
	{
		const char * names[] = { "Generic Iterator", "Skip Iterator", "A to L Iterator",
				"M to Z Iterator", "Reverse Iterator" };
		
		for (int i(0); i < 5; i++)
		{
			DataOut << "___________________________________________________________________\n";
			DataOut << setw(40) << right << names[i] << endl << endl;
			for (iterators[i]->First(); !iterators[i]->IsDone(); iterators[i]->MoveNext())
			{
				DataOut << iterators[i]->GetCurrent()->GetData() << endl;
				iterators[i]->GetCurrent()->GetData()->GetFlightList()->PrintAll(DataOut); 
			}
			DataOut << "___________________________________________________________________\n\n";
		}
	}
	
}

void Controller::PrintExit()
{
	if (m_echo)
	{
		if (DataOut.is_open())
		{
			DataOut << m_com << endl; 
		}
		else
			cout << "Could not write to file" << endl;
	}
	
	if (DataOut.is_open())
	{
		DataOut << "\n****-Exiting Program-****\n";
		DataOut << "****-Goodbye-****";
	}
	else
		cout << "Could not write to file" << endl;
}

Controller::~Controller()
{
	cout << "Controller d'tor" << endl;

	for (int i(0); i < 5; i++)
	{
		delete iterators[i];
	}
	delete m_AirList; 
	delete m_flight_hash_table;
	DataOut.close(); 
}
