#ifndef _DOMINOSCARRES
#define _DOMINOSCARRES
#include "Tuile.hpp"
#include "Joueur.hpp"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class DominosCarres{
    private:
        int nbJoueurs;
        vector<Joueur*> tabJoueurs;
        vector<Tuile *> sac;
        vector<vector<int>> tabCote ; 

    public:
        DominosCarres(int nj, vector <Joueur*> tj);
        virtual ~DominosCarres();
        Tuile pioche();
        int getNbJoueur();
        vector<Joueur*> getTabJoueur();
        void setnbJoueur(int a);
        vector<Tuile*> getSac();
        void tourner(Tuile t);

    friend ostream& operator <<(ostream& out, DominosCarres &dc) ;
};
#endif