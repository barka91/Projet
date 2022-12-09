#ifndef _DOMENGINE
#define _DOMENGINE
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<vector>
#include "Tuile.hpp"
#include "Joueur.hpp"
#include "EmplacementVide.hpp"


using namespace std;
using namespace sf;

class DomEngine{
    const int SCRWIDTH = 800;
    const int SCRHEIGHT = 600;
    private:
        // window
        RenderWindow* window;
        VideoMode videoMode;
        Event ev;

        // graphic
        RectangleShape wall;

        // system
        int nbJoueurs;
        Tuile* tuileDeDepart;
        Tuile* currentTuile;
        vector<Joueur> tabJoueurs;
        vector<Tuile*> sac;
        vector<vector<int>> tabCote ;
        vector<EmplacementVide*> tabEmplacement;
        vector<Tuile*> plateau;

    public:
        // constructeur et destructeur
        DomEngine(int nj);
        virtual ~DomEngine();

        // fonctions
        void drawTuile(Tuile* t);

        void input();
        void update();
        void draw();
        void run();

        void startTheGame();
        void verification(EmplacementVide* ev);

        
};


#endif