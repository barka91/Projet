#include "Tuile.hpp"
#include<iostream>
#include<string>

using namespace std;

Tuile::Tuile(int* h,int* d,int* b,int* g) : haut{h},droite{d},bas{b},gauche{g}{
    cout<<"Construction de "<< *this<<endl;
}

Tuile::~Tuile(){
    cout<<"Destruction de "<<*this<<endl;
    delete haut;
    delete droite;
    delete bas;
    delete gauche;
}

int* Tuile::Bas(){return bas;}
int* Tuile::Droite(){return droite;}
int* Tuile::Haut(){return haut;}
int* Tuile::Gauche(){return gauche;}
void Tuile::setB(int* t){ bas = t;}
void Tuile::setD(int* t){ droite = t;}
void Tuile::setG(int* t){ gauche = t;}
void Tuile::setH(int* t){ haut = t;}

void Tuile::tourner(){
    int *tmpH = Haut();
    setH( Gauche() );
    int *tmpD = Droite();
    setD( tmpH );
    int *tmpB = Bas();
    setB( tmpD );
    setG( tmpB );
}

ostream& operator<<( ostream& out , Tuile &t){
    out<<"Tuile\n  ";
    for(int i=0; i<3; i++)
        out<<t.Haut()[i]<<" ";
    out<<" \n";
    for(int i=0; i<3; i++)
        out<<t.Gauche()[3-i-1]<<"       "<<t.Droite()[i]<<endl;
    out<<"  ";
    for( int i=2; i>=0; i--)
        out<<t.Bas()[i]<<" ";
    out<<" ";
    return out ;
}

