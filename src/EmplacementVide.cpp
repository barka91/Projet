#include "EmplacementVide.hpp"

EmplacementVide::EmplacementVide(Vector2f pos)
{
    sprite.setFillColor(Color::Blue);
    sprite.setSize(Vector2f(100.f,100.f));
	auto bounds = sprite.getLocalBounds();
	sprite.setOrigin( bounds.width / 2.f, bounds.height / 2.f );
    sprite.setPosition(pos);
    
}

RectangleShape EmplacementVide::getShape()
{
    return sprite;
}

vector<int> EmplacementVide::getBas(){return bas;}
vector<int> EmplacementVide::getDroite(){return droite;}
vector<int> EmplacementVide::getHaut(){return haut;}
vector<int> EmplacementVide::getGauche(){return gauche;}

void EmplacementVide::setBas(vector<int> t) { bas = t; }
void EmplacementVide::setDroite(vector<int> t){ droite = t;}
void EmplacementVide::setGauche(vector<int> t){ gauche = t;}

void EmplacementVide::mix(EmplacementVide *ev){
    if (this->getHaut().empty()) this->setHaut(ev->getHaut());
    if (this->getDroite().empty()) this->setDroite(ev->getDroite());
    if (this->getGauche().empty()) this->setGauche(ev->getGauche());
    if (this->getBas().empty()) this->setBas(ev->getBas());
}
void EmplacementVide::setHaut(vector<int> t) { haut = t; }
