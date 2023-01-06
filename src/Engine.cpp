#include "Engine.hpp"

Engine::Engine(int nj,string nom):nbJoueurs{nj}{
    this->videoMode.height = SCRHEIGHT;
	this->videoMode.width = SCRWIDTH;
	this->window = new sf::RenderWindow(this->videoMode, nom, sf::Style::Default);
	mainFont.loadFromFile("assets/fonts/roboto.ttf");
	setupText(&gameOverText, mainFont, "GAME OVER", 72, Color::Yellow);
	FloatRect gameOverTextBounds = gameOverText.getLocalBounds();
	gameOverText.setOrigin(gameOverTextBounds.width / 2.0f,gameOverTextBounds.height / 2.0f);
	gameOverText.setPosition(Vector2f(SCRWIDTH/2.0f,SCRHEIGHT/2.0f));
	gameOverText.setOutlineColor(Color::Black);
	gameOverText.setOutlineThickness(2);

	button1.setSize(Vector2f(100, 40));
	button1.setPosition(50, 175);
	button1.setFillColor(sf::Color::Black);

	buttonText1.setString("Tourner");
	buttonText1.setFont(mainFont);
	buttonText1.setCharacterSize(20);
	buttonText1.setFillColor(sf::Color::White);


	sf::FloatRect textRect1 = buttonText1.getLocalBounds();
	buttonText1.setOrigin(textRect1.left + textRect1.width / 2.0f,
						textRect1.top + textRect1.height / 2.0f);
	buttonText1.setPosition(sf::Vector2f(button1.getPosition().x + button1.getSize().x / 2.0f, 
							button1.getPosition().y + button1.getSize().y / 2.0f));

	button2.setSize(Vector2f(100, 40));
	button2.setPosition(50, 225);
	button2.setFillColor(sf::Color::Black);

	buttonText2.setString("Changer");
	buttonText2.setFont(mainFont);
	buttonText2.setCharacterSize(20);
	buttonText2.setFillColor(sf::Color::White);

	sf::FloatRect textRect2 = buttonText2.getLocalBounds();
	buttonText2.setOrigin(textRect2.left + textRect2.width / 2.0f,
						textRect2.top + textRect2.height / 2.0f);
	buttonText2.setPosition(sf::Vector2f(button2.getPosition().x + button2.getSize().x / 2.0f, 
							button2.getPosition().y + button2.getSize().y / 2.0f));



	
}

Engine::~Engine(){
    delete this->window;
	for(int i =0; i < nbJoueurs ; i++) delete tabJoueurs.at(i);
}

void Engine::run()
{
	while (window->isOpen())
	{
		if ( currentGameState == GameState::GAMEOVER) {
			draw();
			input();
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
