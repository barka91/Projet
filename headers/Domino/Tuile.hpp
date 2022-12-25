#ifndef _TUILE
#define _TUILE
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace sf;

class Tuile{

    const int SCRWIDTH = 800;
    const int SCRHEIGHT = 600;

    private:
        vector<int> haut;
        vector<int> droite;
        vector<int> bas;
        vector<int> gauche;

        RectangleShape sprite;
        Font font;
        Text top;
        Text left0;
        Text left1;
        Text left2;
        Text right0;
        Text right1;
        Text right2;
        Text down;     

        Tuile* nord;
        Tuile* ouest;
        Tuile* est;
        Tuile* sud;

        
    public:
        Tuile(vector<int> h,vector<int> d,vector<int> b,vector<int> g, Vector2f pos);
        Tuile(Tuile &t);
        Tuile();
        virtual ~Tuile();
        vector<int> getHaut() ;
        vector<int> getDroite();
        vector<int> getBas();
        vector<int> getGauche();

        RectangleShape getSprite();
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
        

        Vector2f getPosition();

        void setTuileString(vector<int> v,Text* t);
        void setTuileGD(vector<int> v,string cote);

        void setHaut(vector<int> t);
        void setDroite(vector<int> t);
        void setBas(vector<int> t);
        void setGauche(vector<int> t);

        Tuile* getNord();

        void setPosition(Vector2f pos);

        void tourner();

    friend ostream& operator <<(ostream& out, Tuile &t) ;        
};
#endif