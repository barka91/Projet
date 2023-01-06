#ifndef _TRAXEMPLACEMENT
#define _TRAXEMPLACEMENT
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Emplacement.hpp"

using namespace std;
using namespace sf;

class TraxEmplacement : public Emplacement{
 
    private:
        char face;
        char haut;
        char droite;
        char bas;
        char gauche;

        bool isVide;

        int x;
        int y;

  
    public:
        TraxEmplacement(Vector2f pos,int x,int y);

        char getFace();
        char getHaut() ;
        char getDroite();
        char getBas();
        char getGauche();

        int getX();
        int getY();

        void setface(char d);
        void setHaut(char t);
        void setDroite(char t);
        void setBas(char t);
        void setGauche(char t);

        bool getIsVide();
        void setIsVide(bool b);

        bool isTuileForce();
        bool canTake();


    friend ostream& operator <<(ostream& out, TraxEmplacement &e) ;        
};
#endif