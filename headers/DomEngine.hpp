#ifndef _DOMENGINE
#define _DOMENGINE
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include<iostream>
#include<string>
#include<vector>

using namespace std;
using namespace sf;

class DomEngine{
    private:
        //Window
        RenderWindow* window;
        VideoMode videoMode;
        Event ev;

        
    public:
        // constructeur et destructeur
        DomEngine();
        virtual ~DomEngine();


        const bool running() const;

        // fonctions
        void pollEvents();
        void update();
        void render();
        
};


#endif