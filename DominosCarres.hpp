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
        vector <Joueur > tabJoueurs;
        vector <Tuile *> sac;
        vector <int *> tabCote ; 

        
    public:
        DominosCarres(int nj, vector <Joueur*> tj);
        virtual ~DominosCarres();
        Tuile pîoche();
        int get();
        void set(int a);
};

ostream& operator <<(ostream& out, DominosCarres &x) ;

#endif