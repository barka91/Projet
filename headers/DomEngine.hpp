#ifndef _DOMENGINE
#define _DOMENGINE
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include "Tuile.hpp"
#include "Joueur.hpp"
#include "EmplacementVide.hpp"
#include "Wall.hpp"


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
        Font mainFont;
        RectangleShape wall;
        RectangleShape tournerBtn;
        RectangleShape repiocheBtn;
        vector<Wall> wallSection;
        Text gameOverText;


        

        // system
        int nbJoueurs;
        Tuile* tuileDeDepart;
        Tuile* currentTuile;
        vector<Joueur*> tabJoueurs;
        vector<Tuile*> sac;
        vector<vector<int>> tabCote ;
        vector<EmplacementVide*> tabEmplacement;
        vector<Tuile*> plateau;

        int currentGameState;


    public:
        enum GameState { RUNNING, GAMEOVER };

        // constructeur et destructeur
        DomEngine(int nj);
        virtual ~DomEngine();

        // fonctions
        void drawTuile(Tuile* t);

        void input();
        void update();
        void draw();
        void run();

        void setupText(Text *textItem, const Font &font, const String &value, int size, Color colour);
        void startTheGame();
        void verification(EmplacementVide* ev);
        bool isBonnePlace(EmplacementVide* ev, Tuile* t);
        bool isEqualHB(vector<int> v1,vector<int> v2);
        bool isEqualGD(vector<int> v1,vector<int> v2);
        void reverse(vector<int>* v);
        void racks(Tuile* t);
        void defausser();
        void joueurSuivant();

        
};


#endif