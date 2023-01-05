#include "Domino/DomEmplacement.hpp"

DomEmplacement::DomEmplacement(Vector2f pos):Emplacement(pos){
 
}


string DomEmplacement::getVector(vector<int> v)
{
    string out = "";
    if (!(v.empty()))
    {
        out = to_string(v.at(0))+to_string(v.at(1))+to_string(v.at(2));
    }
    
    return out;
}

vector<int> DomEmplacement::getBas(){return bas;}
vector<int> DomEmplacement::getDroite(){return droite;}
vector<int> DomEmplacement::getHaut(){return haut;}
vector<int> DomEmplacement::getGauche(){return gauche;}

void DomEmplacement::setHaut(vector<int> t) { haut = t; }
void DomEmplacement::setBas(vector<int> t) { bas = t; }
void DomEmplacement::setDroite(vector<int> t){ droite = t;}
void DomEmplacement::setGauche(vector<int> t){ gauche = t; }

void DomEmplacement::reverseDroite()
{
    // droite.at(0) = t.at(2);
    // droite.at(1) = t.at(1);
    // droite.at(2) = t.at(0);

    int a = droite.at(0);
	droite.at(0)=droite.at(2);
	droite.at(2)=a;
}

void DomEmplacement::reverseGauche()
{
    int a = gauche.at(0);
	gauche.at(0)=gauche.at(2);
	gauche.at(2)=a;
}

void DomEmplacement::mix(DomEmplacement *ev){
    if (this->getHaut().empty()) this->setHaut(ev->getHaut());
    if (this->getDroite().empty()) this->setDroite(ev->getDroite());
    if (this->getGauche().empty()) this->setGauche(ev->getGauche());
    if (this->getBas().empty()) this->setBas(ev->getBas());
}

int DomEmplacement::getPoints()
{
    int res=0;
    if(!(this->getHaut().empty())) res++;
    if(!(this->getDroite().empty())) res++;
    if(!(this->getGauche().empty())) res++;
    if(!(this->getBas().empty())) res++;
    return res;
}

ostream &operator<<(ostream &out, DomEmplacement &e)
{
    
    out<<"haut"<<e.getVector(e.getHaut())
    <<"droite "<<e.getVector(e.getDroite())<<"bas "<<e.getVector(e.getBas())<<"gauche "<<e.getVector(e.getGauche())<<endl;
    return out;
}
