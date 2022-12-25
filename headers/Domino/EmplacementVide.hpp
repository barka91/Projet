#ifndef _EMPLACEMENTVIDE
#define _EMPLACEMENTVIDE
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Emplacement.hpp"

using namespace std;
using namespace sf;

class EmplacementVide : public Emplacement{
 
    private:

        vector<int> haut;
        vector<int> droite;
        vector<int> bas;
        vector<int> gauche;

  
    public:
        EmplacementVide(Vector2f pos);

        vector<int> getHaut() ;
        vector<int> getDroite();
        vector<int> getBas();
        vector<int> getGauche();
        void setHaut(vector<int> t);
        void setDroite(vector<int> t);
        void setBas(vector<int> t);
        void setGauche(vector<int> t);
        void reverseDroite();
        void reverseGauche();


        void mix(EmplacementVide* e);
        int getPoints();
        
        string getVector(vector<int> v);
        

    friend ostream& operator <<(ostream& out, EmplacementVide &e) ;        
};
#endif