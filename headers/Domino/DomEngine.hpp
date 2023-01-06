#ifndef _DOMENGINE
#define _DOMENGINE
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include "DomTuile.hpp"
#include "Joueur.hpp"
#include "DomEmplacement.hpp"
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

        DomTuile* DomTuileDeDepart;
        DomTuile* currentDomTuile;

        vector<DomTuile*> sac;
        vector<vector<int>> tabCote ;
        vector<DomEmplacement*> tabEmplacement;
        vector<DomTuile*> plateau;

    public:


        // constructeur et destructeur
        DomEngine(int nj);
        virtual ~DomEngine();

        // fonctions
        void drawDomTuile(DomTuile* t);

        void input();
        void update();
        void draw();

        void startTheGame();

        void verification(DomEmplacement* ev);
        bool isBonnePlace(DomEmplacement* ev, DomTuile* t);
        bool isEqualHB(vector<int> v1,vector<int> v2);
        bool isEqualGD(vector<int> v1,vector<int> v2);
        void initVoisin(DomTuile* t);
        void defausser();
        void joueurSuivant(int pts);

        
};


#endif