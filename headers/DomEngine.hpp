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
    const int SCRWIDTH = sf::VideoMode::getDesktopMode().width;

    const int SCRHEIGHT = sf::VideoMode::getDesktopMode().height;
    private:
        // window
        RenderWindow* window;
        VideoMode videoMode;
        Event ev;

        // graphic
        RectangleShape wall;
        RectangleShape tournerBtn;
        RectangleShape repiocheBtn;
        

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
        bool isBonnePlace(EmplacementVide* ev, Tuile* t);
        bool isEqual(vector<int> v1,vector<int> v2);
        void racks(Tuile* t);
        void repiocher();

        
};


#endif