#include "Tuile.hpp"
#include<iostream>
#include <vector>
#include<string>

using namespace std;

Tuile::Tuile(vector<int> h,vector<int> d,vector<int> b,vector<int> g) {

    tuileShape.setSize(Vector2f(20, 20));
    tuileShape.setFillColor(Color::Green);
    // tuileShape.setPosition(startPosition);
    // position = startPosition;
    
    
    haut=h;
    droite=d;
    bas=b;
    gauche=g;
    cout<<"Construction de "<< *this<<endl;
}

Tuile::~Tuile(){
    cout<<"Destruction de "<<*this<<endl;
}

vector<int> Tuile::getBas(){return bas;}
vector<int> Tuile::getDroite(){return droite;}
vector<int> Tuile::getHaut(){return haut;}
vector<int> Tuile::getGauche(){return gauche;}
void Tuile::setB(vector<int> t){ bas = t;}
void Tuile::setD(vector<int> t){ droite = t;}
void Tuile::setG(vector<int> t){ gauche = t;}
void Tuile::setH(vector<int> t){ haut = t;}

void Tuile::tourner(){
    vector<int> tmpH = getHaut();
    setH( getGauche() );
    vector<int> tmpD = getDroite();
    setD( tmpH );
    vector<int> tmpB = getBas();
    setB( tmpD );
    setG( tmpB );
}

ostream& operator<<( ostream& out , Tuile &t){
    out<<"Tuile\n  ";
    for(int i=0; i<3; i++)
        out<<t.getHaut().at(i)<<" ";
    out<<" \n";
    for(int i=0; i<3; i++)
        out<<t.getGauche()[3-i-1]<<"       "<<t.getDroite()[i]<<endl;
    out<<"  ";
    for( int i=2; i>=0; i--)
        out<<t.getBas().at(i)<<" ";
    out<<" ";
    return out ;
}

