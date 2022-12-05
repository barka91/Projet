#include"Joueur.hpp"
#include<iostream>

using namespace std;

Joueur::Joueur(int i):id{i}, point{0}{}

Joueur::~Joueur(){
    cout<<"destruction de joueur "<<*this;
}

ostream& operator<<(ostream& out, Joueur &j){
    out << "Joueur est " << j.getId() << endl;
    return out;
}

int Joueur::getId(){return id;}

void Joueur::setPoint(int p){
    point += p;
}



