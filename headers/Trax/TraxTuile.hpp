#ifndef _TRAXTUILE
#define _TRAXTUILE
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Tuile.hpp"

using namespace std;
using namespace sf;

class TraxTuile : public Tuile {

    private:
        Texture texture;
        Sprite sprite;
    public:
        TraxTuile(Vector2f pos,string s);
        virtual ~TraxTuile();

        Sprite getSprite();
        void setPosition(Vector2f pos);
        void tourner();

        



    friend ostream& operator <<(ostream& out, Tuile &t) ;        
};
#endif