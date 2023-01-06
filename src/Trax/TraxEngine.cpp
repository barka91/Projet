#include "Trax/TraxEngine.hpp"

TraxEngine::TraxEngine():Engine(2,"Trax"),isDebut{true}{
	
	startTheGame();
	
}

TraxEngine::~TraxEngine()
{
	for (int i = 0; i < 8; i++)
	{	
		for (int j = 0; j < 8; j++)
		{
		delete tabTraxEmplacement.at(i).at(j);	
		}
		
	}
	delete TraxTuileSelected;
}


void TraxEngine::startTheGame()
{
	Engine::startTheGame();

	// on initialise le plateau qui est un matrice 8*8 de traxEmplacement
	vector<TraxEmplacement*> t ;
	for (int i = 0; i < 8; i++)
	{	
		for (int j = 0; j < 8; j++)
		{
			t.push_back( new TraxEmplacement{sf::Vector2f((SCRWIDTH/4.0f)+100*i,(SCRHEIGHT/6.0f)+100*j),i,j});
		}
		tabTraxEmplacement.push_back(t);
		t.clear();
	}

	// on initialise la tuile selectionne
	TraxTuileSelected = new TraxTuileDroit(sf::Vector2f(100,100));
	setSelected('d','n','b','n','b');

	// ces coordonnees vont indiquer la position d'un coup force
	coordCF = make_pair(-1,-1);

}

bool TraxEngine::isBonnePlace(TraxEmplacement* e)
{
	// si cette tuile ne peut pas etre utilisee et que ce n'est pas le debut du jeu on sort de la fonction
	if (!e->canTake() && !isDebut)return false;

	if(e->getHaut() != hautSelected && e->getHaut() !=0) {
		return false;
	}

	if(e->getDroite() != droiteSelected && e->getDroite() !=0) {
		return false;
	}

	if(e->getBas() != basSelected && e->getBas() !=0) {
		return false;
	}

	if(e->getGauche() != gaucheSelected && e->getGauche() !=0) {
		return false;
	}

	return true;
    
}

void TraxEngine::initVoisin(int x,int y)
{
	if (y>0){
		tabTraxEmplacement.at(x).at(y-1)->setBas(hautSelected);
	}

	if (y<7){
		tabTraxEmplacement.at(x).at(y+1)->setHaut(basSelected);
	}
	
	if (x>0){
		tabTraxEmplacement.at(x-1).at(y)->setDroite(gaucheSelected);
	}

	if (x<7){
		tabTraxEmplacement.at(x+1).at(y)->setGauche(droiteSelected);
	}
}

bool TraxEngine::isCoupForce(int x, int y)
{
	if (y>0 && tabTraxEmplacement.at(x).at(y-1)->isTuileForce()){
		tabTraxEmplacement.at(x).at(y-1)->setcolor(Color::Red);
		coordCF = make_pair(x,y-1);
		return true;
	}

	if (y<7 && tabTraxEmplacement.at(x).at(y+1)->isTuileForce()){
		tabTraxEmplacement.at(x).at(y+1)->setcolor(Color::Red);
		coordCF = make_pair(x,y+1);
		return true;
	}
	
	if (x>0 && tabTraxEmplacement.at(x-1).at(y)->isTuileForce()){
		tabTraxEmplacement.at(x-1).at(y)->setcolor(Color::Red);
		coordCF = make_pair(x-1,y);
		return true;
	}

	if (x<7 && tabTraxEmplacement.at(x+1).at(y)->isTuileForce()){
		tabTraxEmplacement.at(x+1).at(y)->setcolor(Color::Red);
		coordCF = make_pair(x+1,y);
		return true;
	}	

	return false;
}

void TraxEngine::change()
{	
	delete TraxTuileSelected;
	if (faceSelected == 'd'){
		TraxTuileSelected = new TraxTuileCourbe(sf::Vector2f(100,100));
		setSelected('c','n','b','b','n');
	}
	else{
		TraxTuileSelected = new TraxTuileDroit(sf::Vector2f(100,100));
		setSelected('d','n','b','n','b');
	}

}
void TraxEngine::tourne()
{
	TraxTuileSelected->tourner();
	
	char tmpH = hautSelected;
	hautSelected = gaucheSelected;
    
    char tmpD = droiteSelected;
	droiteSelected = tmpH;
    
    char tmpB = basSelected;
    basSelected =  tmpD ;
    
    gaucheSelected =  tmpB ;

}
void TraxEngine::placement(TraxEmplacement *e)
{
	if (!e->getIsVide())return ;

	int x=e->getX();
	int y=e->getY();

	if (isBonnePlace(e))
	{	
		// on place la tuile a l'endroit choisi
		TraxTuileSelected->setPosition(e->getShape().getPosition());
		plateau.push_back(TraxTuileSelected );

		// on initialise les autres coté
		e->setHaut(hautSelected);
		e->setDroite(droiteSelected);
		e->setBas(basSelected);
		e->setGauche(gaucheSelected);
									
		// on ajoute les infos sur les emplacements a proximite
		initVoisin(x,y);

		// on redefini une nouvelle tuile a placer
		
		TraxTuileSelected = new TraxTuileDroit(sf::Vector2f(100,100));
		setSelected('d','n','b','n','b');

		// on remet a -(1,-1) coordCF
		coordCF = make_pair(-1,-1);
	
		// on dit que la tuile n'est plus vide
		e->setIsVide(false);

		//on verifie si il y a un circuit
		if (detectoCircuit('b',e)) {
			currentGameState = GameState::GAMEOVER;
			setupText(&gameOverText, mainFont, "victoire circuit blanc", 72, Color::White);
		}
		if(detectoLigne('b')){
			currentGameState = GameState::GAMEOVER;
			setupText(&gameOverText, mainFont, "victoire ligne blanc", 72, Color::White);
		}
		if(detectoCircuit('n',e)){
			currentGameState = GameState::GAMEOVER;
			setupText(&gameOverText, mainFont, "victoire circuit noir", 72, Color::Yellow);
		}
		if(detectoLigne('n')){
			currentGameState = GameState::GAMEOVER;
			setupText(&gameOverText, mainFont, "victoire ligne noir", 72, Color::Yellow);
		}
		
		// on change de joueur si il n'y a pas de coup forcé
		if (!isCoupForce(x,y))joueurSuivant();

		// on mets isDebut a false
		isDebut=false;
	}

}

void TraxEngine::joueurSuivant()
{
	bool b = tabJoueurs.at(0)->getCurrent();
	tabJoueurs.at(0)->setCurrent(!b);
	tabJoueurs.at(1)->setCurrent(b);
}

void TraxEngine::drawTraxTuile(TraxTuile* t){
    window->draw(t->getSprite());
}

void TraxEngine::setSelected(char f, char h, char d, char b, char g)
{
	faceSelected = f;
	hautSelected = h;
	droiteSelected = d;
	basSelected = b;
	gaucheSelected = g;
}

bool TraxEngine::detectoCircuit(char c, TraxEmplacement *e)
{
	TraxEmplacement* tmpe = e; 
	char cote_interdit = 'x';

	if (isDebut)return false;
	do{
		if ( cote_interdit!='h' && tmpe->getY()>0 && tmpe->getHaut()==c && 
		!tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()-1)->getIsVide()){
			tmpe = tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()-1);
			cote_interdit ='b';
			continue;
		}

		if(cote_interdit!='d' && tmpe->getX()<7 && tmpe->getDroite()==c &&
		!tabTraxEmplacement.at(tmpe->getX()+1).at(tmpe->getY())->getIsVide()){
			tmpe = tabTraxEmplacement.at(tmpe->getX()+1).at(tmpe->getY());
			cote_interdit ='g';
			continue;
		}

		if(cote_interdit!='b' && tmpe->getY()<7 &&tmpe->getBas()==c &&
		!tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()+1)->getIsVide()){
			tmpe = tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()+1);
			cote_interdit ='h';
			continue;
		}

		if(cote_interdit!='g' && tmpe->getX()>0 && tmpe->getGauche()==c &&
		!tabTraxEmplacement.at(tmpe->getX()-1).at(tmpe->getY())->getIsVide()){
			tmpe = tabTraxEmplacement.at(tmpe->getX()-1).at(tmpe->getY());
			cote_interdit ='d';
			continue;
		}
		return false;

	} while (e!=tmpe);

	return true;

}

bool TraxEngine::detectoLigne(char c)
{
	for (int i = 0; i < 7; i++){	
		TraxEmplacement* tmpe =  tabTraxEmplacement.at(0).at(i);
		if (!tmpe->getIsVide() && tmpe->getDroite()==c){
			if(detectoLigneHori(tmpe,c)) return true;
		}
	}

	for (int i = 0; i < 7; i++){	
		TraxEmplacement* tmpe =  tabTraxEmplacement.at(i).at(0);
		if (!tmpe->getIsVide() && tmpe->getHaut()==c){
			if(detectoLigneVert(tmpe,c)) return true;
		}
	}

	return false;
}

bool TraxEngine::detectoLigneHori(TraxEmplacement* tmpe,char c){
	char cote_interdit = 'g';

	while (!(tmpe->getX()==7 && tmpe->getGauche()==c)){

		if (cote_interdit!='h' && tmpe->getY()>0 && tmpe->getHaut()==c && 
		!tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()-1)->getIsVide()){	
			tmpe = tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()-1);
			cote_interdit ='b';
			continue;
		}

		if(cote_interdit!='d' && tmpe->getX()<7 && tmpe->getDroite()==c &&
		!tabTraxEmplacement.at(tmpe->getX()+1).at(tmpe->getY())->getIsVide()){
			tmpe = tabTraxEmplacement.at(tmpe->getX()+1).at(tmpe->getY());
			cote_interdit ='g';
			continue;
		}

		if(cote_interdit!='b' && tmpe->getY()<7 &&tmpe->getBas()==c &&
		!tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()+1)->getIsVide()){
			tmpe = tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()+1);
			cote_interdit ='h';
			continue;
		}

		if(cote_interdit!='g' && tmpe->getX()>0 && tmpe->getGauche()==c &&
		!tabTraxEmplacement.at(tmpe->getX()-1).at(tmpe->getY())->getIsVide()){
			tmpe = tabTraxEmplacement.at(tmpe->getX()-1).at(tmpe->getY());
			cote_interdit ='d';
			continue;
		}

		return false;
	}		

	return true;
}

bool TraxEngine::detectoLigneVert(TraxEmplacement* tmpe,char c){
	char cote_interdit = 'h';

	while (!(tmpe->getY()==7 && tmpe->getBas()==c)){

		if (cote_interdit!='h' && tmpe->getY()>0 && tmpe->getHaut()==c && 
		!tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()-1)->getIsVide()){
			tmpe = tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()-1);
			cote_interdit ='b';
			continue;
		}

		if(cote_interdit!='d' && tmpe->getX()<7 && tmpe->getDroite()==c &&
		!tabTraxEmplacement.at(tmpe->getX()+1).at(tmpe->getY())->getIsVide()){
			tmpe = tabTraxEmplacement.at(tmpe->getX()+1).at(tmpe->getY());
			cote_interdit ='g';
			continue;
		}

		if(cote_interdit!='b' && tmpe->getY()<7 &&tmpe->getBas()==c &&
		!tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()+1)->getIsVide()){
			tmpe = tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()+1);
			cote_interdit ='h';
			continue;
		}

		if(cote_interdit!='g' && tmpe->getX()>0 && tmpe->getGauche()==c &&
		!tabTraxEmplacement.at(tmpe->getX()-1).at(tmpe->getY())->getIsVide()){		
			tmpe = tabTraxEmplacement.at(tmpe->getX()-1).at(tmpe->getY());
			cote_interdit ='d';
			continue;
		}

		return false;
	}		

	return true;
}

void TraxEngine::update()
{
	// on update dans le input car on a besoin du la derniere tuile placé
}

void TraxEngine::draw()
{
    window->clear();

	window->draw(wall);
	for (auto & w : wallSection) {
    	window->draw(w.getShape());
  	}

	for(auto & v : tabTraxEmplacement){
		for(auto & e : v){
			window->draw(e->getShape());
		}
	}

	for (auto & w : plateau) {
    	drawTraxTuile(w);
  	}

	for (auto & j : tabJoueurs) {
    	window->draw(j->getJText());
    	
  	}

	drawTraxTuile(TraxTuileSelected);

	window->draw(button1);
	window->draw(buttonText1);
	window->draw(button2);
	window->draw(buttonText2);

	if (currentGameState == GameState::GAMEOVER) {
		window->draw(gameOverText);
	}
    
    window->display();
}