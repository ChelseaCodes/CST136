//1.13.17 - Friday Week 1
//creating a square class 
#ifndef	SQUARE_H						
#include <iostream>
using namespace std; 

//Method Declarations 
class Square
{
	public:
		Square();									//default no arg c'tor. Once you create a one arg c'tor you HAVE to create this NO arg c'tor.
		Square(int size);							//one arg c'tor that takes an int. 
		Square(const Square& s);					//Copy constructor; Takes a constant of its own type. Called when passed by reference, returned by value, or when an instance is created.
													//using const to have passed by value efficiency. dont want the passed value to change. ***CONST REF***

		Square& operator = (const Square& s);		//additional parameter not seen: This pointer. 

		int GetSize();								//Getter for retrieving the size of the square, returns an int 
		void SetSize(int size);						//Setter for size, sets the data member size, using int passed
		void Display(); 
		~Square();									//Destructor, d'tor. Typically used to delete memory, but must have even if empty! 

	private:		
		int m_size;									//hidden data member. if you don't say something is public, its defaulted to private. 
};
#endif