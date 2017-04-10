#ifndef cube_h
#define cube_h

class Cube
{
	public:
		Cube();
		Cube(int side);
		Cube(const Cube& c); 
		Cube& operator=(const Cube& c); 
		void Display();
		int GetSide(); 
		~Cube();

	private:
		int m_side; 

};
#endif // !cube_h

