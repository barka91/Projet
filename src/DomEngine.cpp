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
	plateau.push_back(tuileDeDepart);
	sac.erase(sac.begin());
	
	//initialisation des 4 emplacements disponible de base 
	racks(tuileDeDepart);

	// initialisation de laffichage de la 1er tuile de la pioche
	// currentTuile=sac.at(0);

	 

	//  initialisation du decor
	wall.setFillColor(Color::Green);
	wall.setSize(Vector2f(200.0f,200.0f));
	
	
	// wall.setPosition(position);


}

void DomEngine::verification(EmplacementVide* ev){
	bool check = false;
	for (auto & e : tabEmplacement) {
		if (ev->getShape().getGlobalBounds().intersects(e->getShape().getGlobalBounds())){
			e->mix(ev);
			return;
		}
	}
	for (auto & t : plateau){
		if (ev->getShape().getGlobalBounds().intersects(t->getSprite().getGlobalBounds())){
			return;
		}
	}

	tabEmplacement.push_back(ev);
}

bool DomEngine::isBonnePlace(EmplacementVide *ev, Tuile *t){
    if (ev->getHaut().size() == 3 && !(isEqual(ev->getHaut(),t->getHaut()))) return false;
    if (ev->getDroite().size() == 3 && !(isEqual(ev->getDroite(),t->getDroite()))) return false;
    if (ev->getGauche().size() == 3 && !(isEqual(ev->getGauche(),t->getGauche()))) return false;
    if (ev->getBas().size() == 3 && !(isEqual(ev->getBas(),t->getBas()))) return false;
	return true;
    
}

bool DomEngine::isEqual(vector<int> v1, vector<int> v2)
{
	// cout<<v1.at(0)<<v1.at(1)<<v1.at(2)<<" "<<v2.at(0)<<v2.at(1)<<v2.at(2)<<endl;
	cout<<v1.size()<<" big brr "<<v2.size()<<endl;

    return ( equal(v1.begin(), v1.end(), v2.begin()));
}

void DomEngine::racks(Tuile* t)
{
	// emplacement en dessous de la tuile place
	EmplacementVide* a = new EmplacementVide{Vector2f(t->getPosition().x,t->getPosition().y+100)};
	a->setHaut(t->getBas());
	verification(a);

	// emplacement au dessus de la tuile place
	EmplacementVide* b = new EmplacementVide{Vector2f(t->getPosition().x,t->getPosition().y-100)};
	b->setBas(t->getHaut());
	verification(b);

	// emplacement a droite de la tuile place
	EmplacementVide* c = new EmplacementVide{Vector2f(t->getPosition().x+100,t->getPosition().y)};
	c->setGauche(t->getDroite());
	reverse(c->getGauche().begin(),c->getGauche().end());
	verification(c);

	// emplacement a gauche de la tuile place
	EmplacementVide* d = new EmplacementVide{Vector2f(t->getPosition().x-100,t->getPosition().y)};
	reverse(d->getGauche().begin(),d->getGauche().end());
	verification(d);
}

void DomEngine::repiocher()
{
	sac.push_back(sac.at(0));
	sac.erase(sac.begin());	

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
			

			if (this->ev.key.code == sf::Keyboard::Space){
				sac.at(0)->tourner();
			}
			
			if (this->ev.key.code == sf::Keyboard::Space){
				sac.at(0)->tourner();
			}

			if (this->ev.key.code == sf::Keyboard::P){
				repiocher();
			}

			break;
		
		case sf::Event::MouseButtonPressed:
			if (this->ev.mouseButton.button == sf::Mouse::Left){
				Vector2f mouse = window->mapPixelToCoords(Mouse::getPosition(*window));
				for (size_t i = 0; i < tabEmplacement.size(); i++) {
					EmplacementVide* e = tabEmplacement.at(i);
					FloatRect bounds=e->getShape().getGlobalBounds();
					if (bounds.contains(mouse)){
						// si verification ok:
						if (isBonnePlace(e,sac.at(0))){
							// on place la tuile a la place choisi
							cout<<"oue c'est la bonne place mon reuf gg"<<endl;
							sac.at(0)->setPosition(e->getShape().getPosition());
							plateau.push_back(sac.at(0));
							tabEmplacement.erase(tabEmplacement.begin() + i);
							// // on place les nouveaux emplacements vides 
							racks(sac.at(0));
							sac.erase(sac.begin());	
						}
						else
						{
							cout<<"t'es bete ou quoi "<<endl;
							
						}
						break;
						
					}
				}

				// on place les nouveaux emplacements vides 
				// racks(sac.at(0));
				
				
				// sac.erase(sac.begin());
			
		 
			}
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
	// drawTuile(tuileDeDepart);
	drawTuile(sac.at(0));
	for (auto & e : tabEmplacement) {
    	window->draw(e->getShape());
  	}
	
	for (auto & p : plateau) {
    	drawTuile(p);
  	}
	
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
