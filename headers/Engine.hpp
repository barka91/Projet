#ifndef _ENGINE
#define _ENGINE
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include "Wall.hpp"
#include "Joueur.hpp"



using namespace std;
using namespace sf;

class Engine{
    
    protected:
        const int SCRWIDTH = sf::VideoMode::getDesktopMode().width;

        const int SCRHEIGHT = sf::VideoMode::getDesktopMode().height;
        // window
        RenderWindow* window;
        VideoMode videoMode;
        Event ev;

        // graphic
        Font mainFont;
        RectangleShape wall;
        vector<Wall> wallSection;
        Text gameOverText;

        // system
        int nbJoueurs;
       
        vector<Joueur*> tabJoueurs;

        int currentGameState;


    public:
        enum GameState { RUNNING, GAMEOVER };

        // constructeur et destructeur
        Engine(int nj,string nom);
        virtual ~Engine();

        // fonctions
        virtual void input()=0;
        virtual void update()=0;
        virtual void draw()=0;
        void run();

        void startTheGame();
        virtual void joueurSuivant()=0;
        void setupText(Text *textItem, const Font &font, const String &value, int size, Color colour);

        
};


#endif