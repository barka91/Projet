#include "Trax/TraxEngine.hpp"


TraxEngine::TraxEngine():Engine(2,"Trax"){
	
	button1.setSize(Vector2f(100, 40));
	button1.setPosition(50, 175);
	button1.setFillColor(sf::Color::Black);

	buttonText1.setString("Tourner");
	buttonText1.setFont(mainFont);
	buttonText1.setCharacterSize(20);
	buttonText1.setFillColor(sf::Color::White);

	// Centrer le texte dans le bouton
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

	// Centrer le texte dans le bouton
	sf::FloatRect textRect2 = buttonText2.getLocalBounds();
	buttonText2.setOrigin(textRect2.left + textRect2.width / 2.0f,
						textRect2.top + textRect2.height / 2.0f);
	buttonText2.setPosition(sf::Vector2f(button2.getPosition().x + button2.getSize().x / 2.0f, 
							button2.getPosition().y + button2.getSize().y / 2.0f));

	startTheGame();
	
}

TraxEngine::~TraxEngine()
{
}


void TraxEngine::startTheGame()
{
	Engine::startTheGame();
	vector<Emplacement*> t ;
	for (int i = 0; i < 8; i++)
	{	
		for (int j = 0; j < 8; j++)
		{
			t.push_back( new Emplacement{sf::Vector2f((SCRWIDTH/4.0f)+100*i,(SCRHEIGHT/6.0f)+100*j)});
		}
		tabEmplacement.push_back(t);
		t.clear();
	}

	TraxTuileSelected = new TraxTuileDroit(sf::Vector2f(100,100));
	typeSelected = "droit";

}

void TraxEngine::change()
{	
	delete TraxTuileSelected;
	if (typeSelected == "droit"){
		
		TraxTuileSelected = new TraxTuileCourbe(sf::Vector2f(100,100));
		typeSelected = "courbe";
	}
	else
	{
		TraxTuileSelected = new TraxTuileDroit(sf::Vector2f(100,100));
		typeSelected = "droit";
	}
	
}

void TraxEngine::joueurSuivant(int pts)
{
}



void TraxEngine::update()
{
	// currentGameState = GameState::GAMEOVER;
}

void TraxEngine::draw()
{
    window->clear();

	
	
	window->draw(wall);
	for (auto & w : wallSection) {
    	window->draw(w.getShape());
  	}

	for(auto & v : tabEmplacement){
		for(auto & e : v){
			window->draw(e->getShape());
		}
	}

	for (auto & w : tutu) {
    	drawTraxTuile(w);
  	}

	drawTraxTuile(TraxTuileSelected);

	window->draw(button1);
	window->draw(buttonText1);
	window->draw(button2);
	window->draw(buttonText2);
    
    window->display();
}

void TraxEngine::drawTraxTuile(TraxTuile* t){
	window->draw(t->getSprite());
}