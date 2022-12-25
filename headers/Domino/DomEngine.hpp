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
#include "Engine.hpp"


using namespace std;
using namespace sf;

class DomEngine : public Engine{
   
    private:

        // graphic (mettre en place ces bouttons)
        RectangleShape tournerBtn;
        RectangleShape repiocheBtn;

        // system

        Tuile* tuileDeDepart;
        Tuile* currentTuile;

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
        bool isEqualHB(vector<int> v1,vector<int> v2);
        bool isEqualGD(vector<int> v1,vector<int> v2);
        void reverse(vector<int>* v);
        void racks(Tuile* t);
        void defausser();
        void joueurSuivant(int pts);

        
};


#endif