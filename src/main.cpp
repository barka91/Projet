#include <iostream>
#include "DomEngine.hpp"

//using namespace sf;

int main()
{
	//Init srand
	std::srand(static_cast<unsigned>(time(NULL)));

	//Init Game engine
	DomEngine domEngine;

	//Game loop
	while (domEngine.running())
	{
		//Update
		domEngine.update();

		//Render
		domEngine.render();
	}

	//End of application
	return 0;
}