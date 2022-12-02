#include"Joueur.hpp"
#include<iostream>

using namespace std;

Joueur::Joueur(string p,int i):id{i}, pseudo{p},point{0}{}

Joueur::~Joueur(){
    cout<<"destruction de joueur "<<*this;
}

ostream& operator<<(ostream& out, Joueur &j){
    out << "Joueur est " << j.getPseudo() << endl;
    return out;
}

string Joueur::getPseudo(){return pseudo;}

void Joueur::setPoint(int p){
    point += p;
}



