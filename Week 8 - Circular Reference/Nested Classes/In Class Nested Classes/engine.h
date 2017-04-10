#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
using std::cout;
using std::endl; 
class Engine
{
public:
	Engine(int pistons);
	void Display();
	~Engine();

private:
	class Piston
	{
	public:
		Piston();
		void Display(); 
		~Piston();
	};

	int m_num_of_pistons;
	Piston * m_pistonptr;
};
#endif // !ENGINE_H