#ifndef _TRAXTUILECOURBE
#define _TRAXTUILECOURBE
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "TraxTuile.hpp"

using namespace std;
using namespace sf;

class TraxTuileCourbe : public TraxTuile {

    private:
    

    public:
        TraxTuileCourbe(Vector2f pos);
        virtual ~TraxTuileCourbe();
        

        void setPosition(Vector2f pos);
        void tourner();
    

    friend ostream& operator <<(ostream& out, Tuile &t) ;        
};
#endif