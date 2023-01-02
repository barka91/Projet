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
        // cout<<"................."<<tabCote[i]<<endl;
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
	racks(DomTuileDeDepart);

	// initialisation de laffichage de la 1er DomTuile de la pioche
	// currentDomTuile=sac.at(0);

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

bool DomEngine::isBonnePlace(EmplacementVide *ev, DomTuile *t){
	cout<<"ouhouuuuh"<<endl;
    if ( t->getHaut().size() == 3 && ev->getHaut().size() == 3 && !(isEqualHB(ev->getHaut(),t->getHaut()))) {
		cout<<"hautttt"<<endl;
		return false;
	}
		
		
    if (ev->getDroite().size() == 3 && t->getDroite().size() == 3 && !(isEqualHB(ev->getDroite(),t->getDroite()))) {
		cout<<"droittttt"<<endl;

		return false;
	}
    if (ev->getGauche().size() == 3 && t->getGauche().size() == 3 && !(isEqualHB(ev->getGauche(),t->getGauche()))) {
		cout<<"gaucheee"<<endl;

		return false;
	}
    if (ev->getBas().size() == 3 && t->getBas().size() == 3 && !(isEqualHB(ev->getBas(),t->getBas()))) {
		cout<<"baasss"<<endl;

		return false;
	}
	return true;
    
}

bool DomEngine::isEqualHB(vector<int> v1, vector<int> v2)
{
	cout<<v1.at(0)<<v1.at(1)<<v1.at(2)<<" "<<v2.at(0)<<v2.at(1)<<v2.at(2)<<endl;
	cout<<v1.size()<<" big brr "<<v2.size()<<endl;

    return ( v1.at(0)==v2.at(0) && v1.at(1)==v2.at(1) && v1.at(2)==v2.at(2));
}

bool DomEngine::isEqualGD(vector<int> v1, vector<int> v2)
{
	cout<<v1.at(0)<<v1.at(1  )<<v1.at(2)<<" "<<v2.at(0)<<v2.at(1)<<v2.at(2)<<endl;
	cout<<v1.size()<<" big brr "<<v2.size()<<endl;

    return ( v1.at(0)==v2.at(2) && v1.at(1)==v2.at(1) && v1.at(1)==v2.at(2));
}

void DomEngine::reverse(vector<int>* v)
{
	int a = v->at(0);
	v->at(0)=v->at(2);
	v->at(2)=a;
}

void DomEngine::racks(DomTuile* t)
{
	// emplacement en dessous de la DomTuile place
	EmplacementVide* a = new EmplacementVide{Vector2f(t->getPosition().x,t->getPosition().y+100)};
	a->setHaut(t->getBas());
	verification(a);

	// emplacement au dessus de la DomTuile place
	EmplacementVide* b = new EmplacementVide{Vector2f(t->getPosition().x,t->getPosition().y-100)};
	b->setBas(t->getHaut());
	verification(b);

	// emplacement a droite de la DomTuile place
	EmplacementVide* c = new EmplacementVide{Vector2f(t->getPosition().x+100,t->getPosition().y)};
	c->setGauche(t->getDroite());
	cout<<c->getVector(c->getGauche())<<"aaaaaah"<<endl;
	// c->reverseGauche();
	cout<<c->getVector(c->getGauche())<<"beeeeeeeh"<<endl;
	verification(c);

	// emplacement a gauche de la DomTuile place
	EmplacementVide* d = new EmplacementVide{Vector2f(t->getPosition().x-100,t->getPosition().y)};
	d->setDroite(t->getGauche());
	// d->reverseDroite();
	verification(d);
	cout<<c->getVector(c->getGauche())<<"aaaaajefeiufieah"<<endl;

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
				cout<<"allo wsh jsuis le dernier la  "<<endl;
				return ;
			}
			else {
				cout<<"allo wsh "<<endl;
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


	// Draw GameOver
	if (currentGameState == GameState::GAMEOVER) {
		window->draw(gameOverText);
	}

    window->display();
}

