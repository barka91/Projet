#ifndef _EMPLACEMENTVIDE
#define _EMPLACEMENTVIDE
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace sf;

class EmplacementVide{

  
    private:
        RectangleShape sprite;
  
    public:
        EmplacementVide(Vector2f pos);

        RectangleShape getShape();
        
        
        

    friend ostream& operator <<(ostream& out, EmplacementVide &e) ;        
};
#endif