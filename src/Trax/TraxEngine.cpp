#include "Trax/TraxEngine.hpp"

TraxEngine::TraxEngine():Engine(2,"Trax"),isDebut{true}{
	
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

	TraxTuileSelected = new TraxTuileDroit(sf::Vector2f(100,100));
	setSelected('d','n','b','n','b');

	coordCF = make_pair(-1,-1);

}
bool TraxEngine::isBonnePlace(TraxEmplacement* e)
{
	if (!e->canTake() && !isDebut)return false;
	if(e->getHaut() != hautSelected && e->getHaut() !=0) {
		cout<<"h"<<e->getHaut()<<hautSelected<<endl;
		
		return false;
	}
	if(e->getDroite() != droiteSelected && e->getDroite() !=0) {
		cout<<"d"<<e->getDroite()<<droiteSelected<<endl;
		return false;
	}
	if(e->getBas() != basSelected && e->getBas() !=0) {
		cout<<"b"<<e->getBas()<<basSelected<<endl;

		return false;
	}
	if(e->getGauche() != gaucheSelected && e->getGauche() !=0) {
		cout<<"g"<<e->getGauche()<<gaucheSelected<<endl;

		return false;
	}
	cout<<"h"<<e->getHaut()<<hautSelected<<endl;
	cout<<"d"<<e->getDroite()<<droiteSelected<<endl;
	cout<<"b"<<e->getBas()<<basSelected<<endl;
	cout<<"g"<<e->getGauche()<<gaucheSelected<<endl;
	// isDebut=false;
	return true;
    
}

void TraxEngine::racks(int x,int y)
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
		cout<<"iscoup "<<coordCF.first<<coordCF.second<<endl;
		return true;

	}
	if (y<7 && tabTraxEmplacement.at(x).at(y+1)->isTuileForce()){
		tabTraxEmplacement.at(x).at(y+1)->setcolor(Color::Red);
		coordCF = make_pair(x,y+1);
		cout<<"iscoup "<<coordCF.first<<coordCF.second<<endl;

		return true;

	}
	
	if (x>0 && tabTraxEmplacement.at(x-1).at(y)->isTuileForce()){
		tabTraxEmplacement.at(x-1).at(y)->setcolor(Color::Red);
		coordCF = make_pair(x-1,y);
		cout<<"iscoup "<<coordCF.first<<coordCF.second<<endl;
		return true;
		

	}
	if (x<7 && tabTraxEmplacement.at(x+1).at(y)->isTuileForce()){
		tabTraxEmplacement.at(x+1).at(y)->setcolor(Color::Red);
		coordCF = make_pair(x+1,y);
		cout<<"iscoup "<<coordCF.first<<coordCF.second<<endl;
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
	else
	{
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
		tutu.push_back(TraxTuileSelected );

		// on initialise les autres coté
		e->setHaut(hautSelected);
		e->setDroite(droiteSelected);
		e->setBas(basSelected);
		e->setGauche(gaucheSelected);
									
		cout<<"x="<<x<<" y="<<y<<endl;
		// on ajoute les infos sur les emplacements a proximite
		racks(x,y);

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
			cout<<"victore circuit blanc"<<endl;
		}
		if(detectoLigne('b')){
			currentGameState = GameState::GAMEOVER;
			setupText(&gameOverText, mainFont, "victoire ligne blanc", 72, Color::Yellow);
			cout<<"victore ligne blanc"<<endl;
		}
		if(detectoCircuit('n',e)){
			currentGameState = GameState::GAMEOVER;
			setupText(&gameOverText, mainFont, "victoire circuit noir", 72, Color::Yellow);
			cout<<"victore circuit noir"<<endl;
		}
		if(detectoLigne('n')){
			currentGameState = GameState::GAMEOVER;
			setupText(&gameOverText, mainFont, "victoire ligne noir", 72, Color::Yellow);
			cout<<"victore ligne noir"<<endl;
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



void TraxEngine::update()
{
	// on update dans le input car on a besoin du la derniere tuile placé
	// currentGameState = GameState::GAMEOVER;
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

	for (auto & w : tutu) {
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

void TraxEngine::info(TraxEmplacement* e){
	cout<<"h"<<e->getHaut()<<endl;
	cout<<"d"<<e->getDroite()<<endl;
	cout<<"b"<<e->getBas()<<endl;
    cout << "g" << e->getGauche() << endl;
}

bool TraxEngine::detectoCircuit(char c, TraxEmplacement *e)
{
	TraxEmplacement* tmpe = e; 
	char cote_interdit = 'x';
	cout<<"isdebut?"<<isDebut<<endl;
	if (isDebut)return false;
	do{
	 	cout<<"brrrr"<<endl;
		cout<<"ci "<<cote_interdit<<" gy "<<tmpe->getY() <<tmpe->getX()<<" gh " <<tmpe->getHaut()<<endl;
		if ( cote_interdit!='h' && tmpe->getY()>0 && tmpe->getHaut()==c && !tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()-1)->getIsVide()){
		cout<<"brrrr h"<<endl;
			
			tmpe = tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()-1);
			cote_interdit ='b';
			continue;
		}
		// cout<<"brrrr545"<<endl;


		if(cote_interdit!='d' && tmpe->getX()<7 && tmpe->getDroite()==c &&
		!tabTraxEmplacement.at(tmpe->getX()+1).at(tmpe->getY())->getIsVide()){
		cout<<"brrrr d"<<endl;
			
			tmpe = tabTraxEmplacement.at(tmpe->getX()+1).at(tmpe->getY());
			cote_interdit ='g';
			continue;
		cout<<"brrrr545"<<endl;
		}

		if(cote_interdit!='b' && tmpe->getY()<7 &&tmpe->getBas()==c &&
		!tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()+1)->getIsVide()){
		cout<<"brrrr b"<<endl;


			tmpe = tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()+1);
			cote_interdit ='h';
			continue;
		}

		if(cote_interdit!='g' && tmpe->getX()>0 && tmpe->getGauche()==c &&
		!tabTraxEmplacement.at(tmpe->getX()-1).at(tmpe->getY())->getIsVide()){
		cout<<"brrrr g"<<endl;
			
			tmpe = tabTraxEmplacement.at(tmpe->getX()-1).at(tmpe->getY());
			cote_interdit ='d';
			continue;
		}
		return false;

	} while (e!=tmpe);
	cout<<"brrrr6"<<endl;
	
	cout<<"remind me what said khabib?"<<endl;
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
		cout<<"brrroo"<<endl;
		if (cote_interdit!='h' && tmpe->getY()>0 && tmpe->getHaut()==c && 
		!tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()-1)->getIsVide()){
		cout<<"brrrr h"<<endl;
			
			tmpe = tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()-1);
			cote_interdit ='b';
			continue;
		}

		if(cote_interdit!='d' && tmpe->getX()<7 && tmpe->getDroite()==c &&
		!tabTraxEmplacement.at(tmpe->getX()+1).at(tmpe->getY())->getIsVide()){
		cout<<"brrrr d"<<endl;
			
			tmpe = tabTraxEmplacement.at(tmpe->getX()+1).at(tmpe->getY());
			cote_interdit ='g';
			continue;
		}

		if(cote_interdit!='b' && tmpe->getY()<7 &&tmpe->getBas()==c &&
		!tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()+1)->getIsVide()){
		cout<<"brrrr b"<<endl;

			tmpe = tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()+1);
			cote_interdit ='h';
			continue;
		}

		if(cote_interdit!='g' && tmpe->getX()>0 && tmpe->getGauche()==c &&
		!tabTraxEmplacement.at(tmpe->getX()-1).at(tmpe->getY())->getIsVide()){
		cout<<"brrrr g"<<endl;
			
			tmpe = tabTraxEmplacement.at(tmpe->getX()-1).at(tmpe->getY());
			cote_interdit ='d';
			continue;
		}

		return false;
	}		
	cout<<"remind me what said khabib?"<<endl;
	return true;
}

bool TraxEngine::detectoLigneVert(TraxEmplacement* tmpe,char c){
	char cote_interdit = 'h';

	while (!(tmpe->getY()==7 && tmpe->getBas()==c)){
		cout<<"brrroovert"<<endl;
		if (cote_interdit!='h' && tmpe->getY()>0 && tmpe->getHaut()==c && 
		!tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()-1)->getIsVide()){
		cout<<"brrrr h"<<endl;
			
			tmpe = tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()-1);
			cote_interdit ='b';
			continue;
		}

		if(cote_interdit!='d' && tmpe->getX()<7 && tmpe->getDroite()==c &&
		!tabTraxEmplacement.at(tmpe->getX()+1).at(tmpe->getY())->getIsVide()){
		cout<<"brrrr d"<<endl;
			
			tmpe = tabTraxEmplacement.at(tmpe->getX()+1).at(tmpe->getY());
			cote_interdit ='g';
			continue;
		}

		if(cote_interdit!='b' && tmpe->getY()<7 &&tmpe->getBas()==c &&
		!tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()+1)->getIsVide()){
		cout<<"brrrr b"<<endl;

			tmpe = tabTraxEmplacement.at(tmpe->getX()).at(tmpe->getY()+1);
			cote_interdit ='h';
			continue;
		}

		if(cote_interdit!='g' && tmpe->getX()>0 && tmpe->getGauche()==c &&
		!tabTraxEmplacement.at(tmpe->getX()-1).at(tmpe->getY())->getIsVide()){
		cout<<"brrrr g"<<endl;
			
			tmpe = tabTraxEmplacement.at(tmpe->getX()-1).at(tmpe->getY());
			cote_interdit ='d';
			continue;
		}

		return false;
	}		
	cout<<"remind me what said khabib?"<<endl;
	return true;
}