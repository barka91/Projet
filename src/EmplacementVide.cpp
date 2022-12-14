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

string EmplacementVide::getVector(vector<int> v)
{
    string out = "";
    if (!(v.empty()))
    {
        out = to_string(v.at(0))+to_string(v.at(1))+to_string(v.at(2));
    }
    
    return out;
}

vector<int> EmplacementVide::getBas(){return bas;}
vector<int> EmplacementVide::getDroite(){return droite;}
vector<int> EmplacementVide::getHaut(){return haut;}
vector<int> EmplacementVide::getGauche(){return gauche;}

void EmplacementVide::setHaut(vector<int> t) { haut = t; }
void EmplacementVide::setBas(vector<int> t) { bas = t; }
void EmplacementVide::setDroite(vector<int> t){ droite = t;}
void EmplacementVide::setGauche(vector<int> t){ gauche = t; }

void EmplacementVide::reverseDroite()
{
    // droite.at(0) = t.at(2);
    // droite.at(1) = t.at(1);
    // droite.at(2) = t.at(0);

    int a = droite.at(0);
	droite.at(0)=droite.at(2);
	droite.at(2)=a;
}

void EmplacementVide::reverseGauche()
{
    int a = gauche.at(0);
	gauche.at(0)=gauche.at(2);
	gauche.at(2)=a;
}

void EmplacementVide::mix(EmplacementVide *ev){
    if (this->getHaut().empty()) this->setHaut(ev->getHaut());
    if (this->getDroite().empty()) this->setDroite(ev->getDroite());
    if (this->getGauche().empty()) this->setGauche(ev->getGauche());
    if (this->getBas().empty()) this->setBas(ev->getBas());
}



ostream &operator<<(ostream &out, EmplacementVide &e)
{
    
    out<<"haut"<<e.getVector(e.getHaut())
    <<"droite "<<e.getVector(e.getDroite())<<"bas "<<e.getVector(e.getBas())<<"gauche "<<e.getVector(e.getGauche())<<endl;
    return out;
}
