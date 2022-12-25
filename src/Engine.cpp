#include "Engine.hpp"

Engine::Engine(int nj,string nom):nbJoueurs{nj}{
    this->videoMode.height = SCRHEIGHT;
	this->videoMode.width = SCRWIDTH;
	this->window = new sf::RenderWindow(this->videoMode, nom, sf::Style::Default);
	mainFont.loadFromFile("assets/fonts/roboto.ttf");
	setupText(&gameOverText, mainFont, "GAME OVER", 72, Color::Yellow);
	FloatRect gameOverTextBounds = gameOverText.getLocalBounds();
	gameOverText.setPosition(Vector2f(SCRWIDTH/2.0f,SCRHEIGHT/2.0f));
	gameOverText.setOutlineColor(Color::Black);
	gameOverText.setOutlineThickness(2);

	
}

Engine::~Engine(){
    delete this->window;
}

void Engine::setupText(Text *textItem, const Font &font, const String &value, int size, Color colour) {
  textItem->setFont(font);
  textItem->setString(value);
  textItem->setCharacterSize(size);
  textItem->setFillColor(colour);
}

