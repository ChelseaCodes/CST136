#pragma once

//3.3.17 - Conversion operators 
//.dll's: way to package libraries (i.e. iostream) 
//
//

class LibraryClass
{
	public: 
		LibraryClass(int number) 
		{
			cout << "Library Class 1 arg c'tor" << endl;
			m_number = number;
		}
		int GetNumber() const { return m_number; }
	private:
		int m_number;
};