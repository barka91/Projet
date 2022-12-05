#include "DomEngine.hpp"
#include <iostream>

vector<int> h = {1,2,3}, d = {4,5,6}, b = {7,8,9}, g = {0,1,2};

DomEngine::DomEngine(int nj):nbJoueurs{nj}{
    this->videoMode.height = SCRHEIGHT;
	this->videoMode.width = SCRWIDTH;
	this->window = new sf::RenderWindow(this->videoMode, "Dominos Carres", sf::Style::Default);

	startTheGame();
}

DomEngine::~DomEngine(){
    delete this->window;
}

void DomEngine::startTheGame() {
	// initialisation des joueurs
	for(int i =0; i < nbJoueurs ; i++)
        tabJoueurs.push_back(Joueur{i});

	// initialisation de la pioche
	for (int i = 0; i < 15; i++){
        vector<int> c;
        for (int i = 0; i < 3; i++){
          c.push_back(rand()%6);
        }
        
        tabCote.push_back(c);
        // cout<<"................."<<tabCote[i]<<endl;
    }

    for(unsigned int i =0; i<20 ; i++){
		sac.push_back( new Tuile{tabCote[rand()%15],tabCote[rand()%15],tabCote[rand()%15],tabCote[rand()%15],sf::Vector2f(100,100)} );
	}
    
	// initalisation de la tuile de depart
	tuileDeDepart=sac.at(0);
	tuileDeDepart->setPosition(sf::Vector2f(SCRWIDTH/2.0f,SCRHEIGHT/2.0f));
	sac.erase(sac.begin());

	// initialisation de laffichage de la 1er tuile de la pioche
	currentTuile=sac.at(0) ;

	//  initialisation du decor
	wall.setFillColor(Color::Green);
	wall.setSize(Vector2f(200.0f,200.0f));
	
	
	// wall.setPosition(position);


}

void DomEngine::drawTuile(Tuile* t)
{
	window->draw(t->getSprite());
	window->draw(t->getTop());
	window->draw(t->getLeft());
	window->draw(t->getRight());
	window->draw(t->getDown());
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
	window->draw(wall);
	drawTuile(tuileDeDepart);
	cout<<to_string(currentTuile->getPosition().x)<<endl;
	cout<<to_string(currentTuile->getPosition().y)<<endl;
	drawTuile(currentTuile);
	


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
