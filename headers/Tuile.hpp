#ifndef _TUILE
#define _TUILE
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace sf;

class Tuile{
    private:
        vector<int> haut;
        vector<int> droite;
        vector<int> bas;
        vector<int> gauche;
        // Vector2f position;
        RectangleShape tuileShape;
        
    public:
        Tuile(vector<int> h,vector<int> d,vector<int> b,vector<int> g);
        virtual ~Tuile();
        vector<int> getHaut();
        vector<int> getDroite();
        vector<int> getBas();
        vector<int> getGauche();
        void setH(vector<int> t);
        void setD(vector<int> t);
        void setB(vector<int> t);
        void setG(vector<int> t);
        void tourner();

    friend ostream& operator <<(ostream& out, Tuile &t) ;        
};
#endif