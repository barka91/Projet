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

void Engine::run()
{
	while (window->isOpen())
	{
		if ( currentGameState == GameState::GAMEOVER) {
			draw();
			sleep(milliseconds(2)); // sleep so we don't peg the CPU
			continue;
		}
		// input
		input();

		// update
		update();

		//Render
		draw();


	}
}

void Engine::startTheGame()
{
	// initialisation des joueurs
	for(int i =0; i < nbJoueurs ; i++) tabJoueurs.push_back(new Joueur{i});
	
	tabJoueurs.at(0)->setCurrent(true);

	//  initialisation du decor
	wall.setFillColor(Color::Green);
	wall.setSize(Vector2f(200.0f,SCRHEIGHT));

	wallSection.emplace_back(Wall(Vector2f(200.f, 0), Vector2f(SCRWIDTH-200.0f,10.0f)));
	wallSection.emplace_back(Wall(Vector2f(200.f, 0), Vector2f(10.0f,SCRHEIGHT)));
	wallSection.emplace_back(Wall(Vector2f(200.f, SCRHEIGHT-30), Vector2f(SCRWIDTH-200.0f,10.0f)));
	wallSection.emplace_back(Wall(Vector2f(SCRWIDTH,SCRHEIGHT ), Vector2f(10.0f,SCRHEIGHT)));

  	currentGameState = GameState::RUNNING;
}

void Engine::setupText(Text *textItem, const Font &font, const String &value, int size, Color colour)
{
    textItem->setFont(font);
    textItem->setString(value);
    textItem->setCharacterSize(size);
    textItem->setFillColor(colour);
}
