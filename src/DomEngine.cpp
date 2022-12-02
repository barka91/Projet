#include "DomEngine.hpp"
#include <iostream>

vector<int> h = {1,2,3}, d = {4,5,6}, b = {7,8,9}, g = {0,1,2};

DomEngine::DomEngine():tuile{h,d,b,g}{
    this->videoMode.height = SCRHEIGHT;
	this->videoMode.width = SCRWIDTH;
	this->window = new sf::RenderWindow(this->videoMode, "Dominos Carres", sf::Style::Titlebar | sf::Style::Close);
}

DomEngine::~DomEngine(){
    delete this->window;
}


void DomEngine::drawTuile(Tuile t)
{
	window->draw(t.getSprite());
	window->draw(t.getTop());
	window->draw(t.getLeft());
	window->draw(t.getRight());
	window->draw(t.getDown());
}



void DomEngine::input()
{
    //Event polling
	while (this->window->pollEvent(this->ev))
    {
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void DomEngine::update()
{
    input();
}

void DomEngine::draw()
{
    window->clear();

	drawTuile(tuile);

    window->display();
}

void DomEngine::run()
{
	while (window->isOpen())
	{
		// input
		input();

		//Update
		// update();

		//Render
		draw();
	}

}
