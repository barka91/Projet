#ifndef _EMPLACEMENT
#define _EMPLACEMENT
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace sf;

class Emplacement{
 
    protected:
        RectangleShape sprite;

  
    public:
        Emplacement(Vector2f pos);

        RectangleShape getShape();

    friend ostream& operator <<(ostream& out, Emplacement &e) ;        
};
#endif