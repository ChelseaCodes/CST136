#ifndef STRCLASS_H
#define STRCLASS_H

class StrClass
{
	friend class Control; 
	public:
		StrClass();							//no arg c'tor
		StrClass(char * name);				//one arg c'tor
		int StrLen();						//returns length of string
		void Display();						//displays string(length)
		bool IsEmpty();						//checks if string is empty
		~StrClass();						//d'tor

		//Setters and Getters 
		void SetLength(int length); 
		int GetLength();
		char * GetBuffer(); 


	private:
		char m_sBuffer[75] = { '\0' };		//buffer 
		int m_nLength;						//length of string 
		StrClass * next = nullptr;			//pointer to next StrClass object
};
#endif
