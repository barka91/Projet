#include "DomEngine.hpp"



DomEngine::DomEngine(){
    this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "Dominos Carres", sf::Style::Titlebar | sf::Style::Close);
}

DomEngine::~DomEngine(){
    delete this->window;
}

const bool DomEngine::running() const{
    return this->window->isOpen();
}

void DomEngine::pollEvents(){
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
    pollEvents();
}

void DomEngine::render()
{
    window->clear();
    window->display();
}
