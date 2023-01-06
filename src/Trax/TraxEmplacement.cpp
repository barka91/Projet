#include "Trax/TraxEmplacement.hpp"


TraxEmplacement::TraxEmplacement(Vector2f pos,int x,int y):Emplacement(pos), isVide{true},x{x},y{y},haut{0},droite{0},bas{0},gauche{0}{
    sprite.setOutlineColor(Color::Black);
    sprite.setOutlineThickness(1.f);

}



char TraxEmplacement::getFace(){return face;}
char TraxEmplacement::getHaut(){return haut;}
char TraxEmplacement::getDroite(){return droite;}
char TraxEmplacement::getGauche(){return gauche;}
char TraxEmplacement::getBas(){return bas;}

int TraxEmplacement::getX(){return x;}
int TraxEmplacement::getY(){return y;}


void TraxEmplacement::setface(char t){ face = t;}
void TraxEmplacement::setHaut(char t){ haut = t;}
void TraxEmplacement::setDroite(char t){ droite= t;}
void TraxEmplacement::setGauche(char t){ gauche = t;}
void TraxEmplacement::setBas(char t){ bas = t;}

bool TraxEmplacement::getIsVide()
{
    return isVide;
}
void TraxEmplacement::setIsVide(bool b)
{
    isVide=b;
}

// permet de savoir si l'emplacement est generatrice d'un coup force
bool TraxEmplacement::isTuileForce()
{
    if (!isVide) return false;
    if (haut==droite && haut!=0 && droite!=0 ) return true;
    if (haut==bas && haut!=0 && bas!=0) return true;
    if (haut==gauche && haut!=0 && gauche!=0) return true;
    if (droite==bas && droite!=0 && bas!=0) return true;
    if (droite==gauche && droite!=0 && gauche!=0) return true;
    if (bas==gauche && bas!=0 && gauche!=0) return true;
    else return false;
}

// permet de savoir si un emplacement peut recevoir une tuile 
bool TraxEmplacement::canTake()
{
    // si au moins un coté a une valeur c'est qu'il est a coté d'une tuile
    if (haut!=0)return true;
    if (droite!=0)return true;
    if (bas!=0)return true;
    if (gauche!=0)return true;
    return false;

}