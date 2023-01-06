#ifndef _TRAXTUILEDROIT
#define _TRAXTUILEDROIT
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "TraxTuile.hpp"

using namespace std;
using namespace sf;

class TraxTuileDroit : public TraxTuile {

    private:

    public:
        TraxTuileDroit(Vector2f pos);
        virtual ~TraxTuileDroit();

    friend ostream& operator <<(ostream& out, Tuile &t) ;        
};
#endif