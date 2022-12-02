#ifndef _DOMENGINE
#define _DOMENGINE
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<vector>
#include "Tuile.hpp"

using namespace std;
using namespace sf;

class DomEngine{
    const int SCRWIDTH = 800;
    const int SCRHEIGHT = 600;
    private:
        //Window
        RenderWindow* window;
        VideoMode videoMode;
        Event ev;

        Tuile tuile;
        
    public:
        // constructeur et destructeur
        DomEngine();
        virtual ~DomEngine();

        // fonctions
        void drawTuile(Tuile t);

        void input();
        void update();
        void draw();
        void run();
        
};


#endif