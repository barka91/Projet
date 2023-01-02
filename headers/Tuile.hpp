#ifndef _TUILE
#define _TUILE
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace sf;

class Tuile{

    protected:  

    RectangleShape sprite;
        
 
    public:
        Tuile(Vector2f pos,Color c);
        Tuile(Tuile& t);
        Tuile();
        virtual ~Tuile();

        RectangleShape getSprite();

        Vector2f getPosition();

        void setPosition(Vector2f pos);

        



    friend ostream& operator <<(ostream& out, Tuile &t) ;        
};
#endif