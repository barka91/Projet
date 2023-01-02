#ifndef _TRAXENGINE
#define _TRAXENGINE
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include "Joueur.hpp"
#include "Wall.hpp"
#include "Emplacement.hpp"
#include "Engine.hpp"
#include "TraxTuileDroit.hpp"
#include "TraxTuileCourbe.hpp"
#include "Tuile.hpp"



using namespace std;
using namespace sf;

class TraxEngine : public Engine{
   
    private:

        // graphic (mettre en place ces bouttons)
        TraxTuile* TraxTuileSelected;
        RectangleShape button1;
        Text buttonText1;
        RectangleShape button2;
        Text buttonText2;
        

        // system
        vector<TraxTuile*> tutu;
        vector<vector<Emplacement*>> tabEmplacement;
        string typeSelected;


    public:


        // constructeur et destructeur
        TraxEngine();
        virtual ~TraxEngine();

        // fonctions

        void input();
        void update();
        void draw();

        void drawTraxTuile(TraxTuile* t);
        
        void change();
        void startTheGame();

        void joueurSuivant(int pts);

        
};


#endif