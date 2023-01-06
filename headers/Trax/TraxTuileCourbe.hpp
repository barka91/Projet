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

    friend ostream& operator <<(ostream& out, Tuile &t) ;        
};
#endif