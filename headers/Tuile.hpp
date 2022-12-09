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
        Text left;
        Text right;
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
        Text getLeft();
        Text getRight();
        Text getDown();

        void setFont();
        void setTop();
        void setLeft();
        void setRight();
        void setDown();

        Vector2f getPosition();

        void setTuileString(vector<int> v,Text* t);

        void setH(vector<int> t);
        void setD(vector<int> t);
        void setB(vector<int> t);
        void setG(vector<int> t);

        Tuile* getNord();

        void setPosition(Vector2f pos);

        void tourner();

    friend ostream& operator <<(ostream& out, Tuile &t) ;        
};
#endif