#include <iostream>
#include "DomEngine.hpp"

//using namespace sf;

int main()
{
	//Init srand
	std::srand(static_cast<unsigned>(time(NULL)));

	//Init Game engine
	DomEngine domEngine{2};

	//Game loop
	domEngine.run();

	//End of application
	return 0;
}