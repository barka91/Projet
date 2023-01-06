#include "Domino/DomEngine.hpp"

DomEngine::DomEngine(int nj):Engine(nj,"Dominos Carrees"){
	startTheGame();
}

DomEngine::~DomEngine(){
    
}

void DomEngine::startTheGame() {

	Engine::startTheGame();

	// initialisation de la pioche
	for (int i = 0; i < 15; i++){
        vector<int> c;
        for (int i = 0; i < 3; i++){
          c.push_back(rand()%6);
        }
        tabCote.push_back(c);
    }

    for(unsigned int i =0; i<10 ; i++){
		sac.push_back( new DomTuile{tabCote[rand()%15],tabCote[rand()%15],tabCote[rand()%15],tabCote[rand()%15],sf::Vector2f(100,100)} );
	}
    
	// initalisation de la DomTuile de depart
	DomTuileDeDepart=sac.at(0);
	DomTuileDeDepart->setPosition(sf::Vector2f(SCRWIDTH/2.0f,SCRHEIGHT/2.0f));
	plateau.push_back(DomTuileDeDepart);
	sac.erase(sac.begin());
	
	//initialisation des 4 emplacements disponible de base 
	initVoisin(DomTuileDeDepart);

}

void DomEngine::verification(DomEmplacement* ev){
	// on verifie et on ajoute si c'est bon 
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

bool DomEngine::isBonnePlace(DomEmplacement *ev, DomTuile *t)
{
    if ( t->getHaut().size() == 3 && ev->getHaut().size() == 3 && !(isEqualHB(ev->getHaut(),t->getHaut()))) {
		return false;
	}	
		
    if (ev->getDroite().size() == 3 && t->getDroite().size() == 3 && !(isEqualHB(ev->getDroite(),t->getDroite()))) {
		return false;
	}
    if (ev->getGauche().size() == 3 && t->getGauche().size() == 3 && !(isEqualHB(ev->getGauche(),t->getGauche()))) {
		return false;
	}
    if (ev->getBas().size() == 3 && t->getBas().size() == 3 && !(isEqualHB(ev->getBas(),t->getBas()))) {
		return false;
	}
	return true;
    
}

bool DomEngine::isEqualHB(vector<int> v1, vector<int> v2)
{
    return ( v1.at(0)==v2.at(0) && v1.at(1)==v2.at(1) && v1.at(2)==v2.at(2));
}

bool DomEngine::isEqualGD(vector<int> v1, vector<int> v2)
{
    return ( v1.at(0)==v2.at(2) && v1.at(1)==v2.at(1) && v1.at(1)==v2.at(2));
}



void DomEngine::initVoisin(DomTuile* t)
{
	// emplacement en dessous de la DomTuile place
	DomEmplacement* a = new DomEmplacement{Vector2f(t->getPosition().x,t->getPosition().y+100)};
	a->setHaut(t->getBas());
	verification(a);

	// emplacement au dessus de la DomTuile place
	DomEmplacement* b = new DomEmplacement{Vector2f(t->getPosition().x,t->getPosition().y-100)};
	b->setBas(t->getHaut());
	verification(b);

	// emplacement a droite de la DomTuile place
	DomEmplacement* c = new DomEmplacement{Vector2f(t->getPosition().x+100,t->getPosition().y)};
	c->setGauche(t->getDroite());
	verification(c);

	// emplacement a gauche de la DomTuile place
	DomEmplacement* d = new DomEmplacement{Vector2f(t->getPosition().x-100,t->getPosition().y)};
	d->setDroite(t->getGauche());
	verification(d);

}

void DomEngine::defausser()
{	
	if (sac.size()>0)
	{
		sac.erase(sac.begin());	
		joueurSuivant(0);
	}
}

void DomEngine::joueurSuivant(int pts)
{
	for (int i = 0; i < tabJoueurs.size(); i++){
		if( tabJoueurs.at(i)->getCurrent()){
			tabJoueurs.at(i)->setPoint(pts);
			if (i+1 == tabJoueurs.size()){
				tabJoueurs.at(i)->setCurrent(false);
				tabJoueurs.at(0)->setCurrent(true);
				return ;
			}
			else {
				tabJoueurs.at(i)->setCurrent(false);
				tabJoueurs.at(i+1)->setCurrent(true);
				break;
			}
		}
  	}
}

void DomEngine::drawDomTuile(DomTuile* t)
{
	window->draw(t->getSprite());
	window->draw(t->getTop());
	window->draw(t->getLeft0());
	window->draw(t->getLeft1());
	window->draw(t->getLeft2());
	window->draw(t->getRight0());
	window->draw(t->getRight1());
	window->draw(t->getRight2());
	window->draw(t->getDown());
}

void DomEngine::update()
{
	if (sac.size()==0){
		int max =1;
		Joueur* gagnant = nullptr;
		for (auto & j : tabJoueurs){
			if (j->getPoint()>=max)
			{
				max=j->getPoint();
				gagnant=j;
			}
		}
		if (gagnant != 0) setupText(&gameOverText, mainFont, "Le joueur "+to_string(gagnant->getId())+" gagne la partie", 72, Color::Yellow);
		else setupText(&gameOverText, mainFont, "Aucun joueur n'a gagne la partie", 72, Color::Yellow);
		currentGameState = GameState::GAMEOVER;
	}
}

void DomEngine::draw()
{
    window->clear();

	window->draw(wall);
	
	for (auto & w : wallSection) {
    	window->draw(w.getShape());
  	}

	if (sac.size()>0)
	{
		drawDomTuile(sac.at(0));
	}

	for (auto & e : tabEmplacement) {
    	window->draw(e->getShape());
  	}
	
	for (auto & p : plateau) {
    	drawDomTuile(p);
  	}

	for (auto & j : tabJoueurs) {
    	window->draw(j->getJText());
    	window->draw(j->getJScore());
  	}

	window->draw(button1);
	window->draw(buttonText1);
	window->draw(button2);
	window->draw(buttonText2);

	// Draw GameOver
	if (currentGameState == GameState::GAMEOVER) {
		window->draw(gameOverText);
	}

    window->display();
}

