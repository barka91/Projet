#ifndef _TRAXENGINE
#define _TRAXENGINE
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include "Tuile.hpp"
#include "Joueur.hpp"
#include "EmplacementVide.hpp"
#include "Wall.hpp"
#include "Engine.hpp"


using namespace std;
using namespace sf;

class TraxEngine : public Engine{
   
    private:

        // graphic (mettre en place ces bouttons)


        // system


    public:


        // constructeur et destructeur
        TraxEngine(int nj);
        virtual ~TraxEngine();

        // fonctions
        void drawTuile(Tuile* t);

        void input();
        void update();
        void draw();
        void run();

        void startTheGame();

        void joueurSuivant(int pts);

        
};


#endif