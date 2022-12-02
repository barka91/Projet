#include "DominosCarres.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

DominosCarres::DominosCarres(int nj, vector <Joueur *> tj): nbJoueurs{nj}{
    for(unsigned int i =0; i < tj.size() ; i++)
        tabJoueurs.push_back(tj[i]);
    
    for ( unsigned int i = 0; i < 15; i++){
        vector<int> c;
        for (int i = 0; i < 3; i++){
          c.push_back(rand()%6);
        }
        
        tabCote.push_back(c);
        // cout<<"................."<<tabCote[i]<<endl;
    }

    for(unsigned int i =0; i<20 ; i++)
    // 
        sac.push_back( new Tuile{tabCote[rand()%15],tabCote[rand()%15],tabCote[rand()%15],tabCote[rand()%15]} );
    
}

DominosCarres::~DominosCarres(){
    cout<<"destruction dominos carres" << endl;
}

void DominosCarres::tourner(Tuile t){ t.tourner() ;}

int DominosCarres::getNbJoueur(){return nbJoueurs;}
vector<Joueur*> DominosCarres::getTabJoueur(){return tabJoueurs;}
void DominosCarres::setnbJoueur(int nj){this->nbJoueurs = nj;}
vector<Tuile*> DominosCarres::getSac(){return sac;}


ostream& operator<<(ostream& out, DominosCarres &dc){
    out << "DominosCarres se joue avec " << dc.getNbJoueur()<<endl;
    for( unsigned int i =0 ; i < dc.getSac().size() ; i++)
        out << *dc.getSac()[i]<<endl;
    return out;
}