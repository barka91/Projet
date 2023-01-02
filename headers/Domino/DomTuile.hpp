#ifndef _DOMTUILE
#define _DOMTUILE
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Tuile.hpp"

using namespace std;
using namespace sf;

class DomTuile : public Tuile{

    private:
        vector<int> haut;
        vector<int> droite;
        vector<int> bas;
        vector<int> gauche;

        Font font;
        Text top;
        Text left0;
        Text left1;
        Text left2;
        Text right0;
        Text right1;
        Text right2;
        Text down;     

        DomTuile* nord;
        DomTuile* ouest;
        DomTuile* est;
        DomTuile* sud;

        
    public:
        DomTuile(vector<int> h,vector<int> d,vector<int> b,vector<int> g, Vector2f pos);
        DomTuile(DomTuile &t);
        DomTuile();
        virtual ~DomTuile();
        vector<int> getHaut() ;
        vector<int> getDroite();
        vector<int> getBas();
        vector<int> getGauche();


        Font getFont();
        Text getTop();
        Text getLeft0();
        Text getLeft1();
        Text getLeft2();
        Text getRight0();
        Text getRight1();
        Text getRight2();
        Text getDown();

        void setupTextV(Text *textItem, const Font &font, const vector<int> v, int size, Color colour,float angle) ;
        void setupTextS(Text *textItem, const Font &font, const string s, int size, Color colour,float angle) ;

        void setDomTuileString(vector<int> v,Text* t);
        void setDomTuileGD(vector<int> v,string cote);

        void setHaut(vector<int> t);
        void setDroite(vector<int> t);
        void setBas(vector<int> t);
        void setGauche(vector<int> t);


        void setPosition(Vector2f pos);
        void tourner();

    friend ostream& operator <<(ostream& out, DomTuile &t) ;        
};
#endif