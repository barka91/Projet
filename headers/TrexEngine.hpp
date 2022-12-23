#ifndef _TREXENGINE
#define _TREXENGINE
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include "Joueur.hpp"



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
        Text gameOverText;
       

        // system
        int nbJoueurs;

        int currentGameState;


    public:
        enum GameState { RUNNING, GAMEOVER };

        // constructeur et destructeur
        TrexEngine(int nj);
        virtual ~TrexEngine();

        // fonctions
        void drawTuile(Tuile* t);

        void input();
        void update();
        void draw();
        void run();

        void setupText(Text *textItem, const Font &font, const String &value, int size, Color colour);

        
};


#endif