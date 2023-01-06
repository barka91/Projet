#ifndef _TRAXENGINE
#define _TRAXENGINE
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include "Joueur.hpp"
#include "Wall.hpp"
#include "TraxEmplacement.hpp"
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
        vector<vector<TraxEmplacement*>> tabTraxEmplacement;
        
        char faceSelected;
        char hautSelected;
        char gaucheSelected;
        char droiteSelected;
        char basSelected;

        // coordonnee de l'enplacement du coup force
        pair <int,int> coordCF;

        bool isDebut;




    public:
    

        // constructeur et destructeur
        TraxEngine();
        virtual ~TraxEngine();

        // fonctions

        void input();
        void update();
        void draw();

        void drawTraxTuile(TraxTuile* t);
        
        void setSelected(char f,char h, char g, char d, char b);

        void change();
        void tourne();
        void placement(TraxEmplacement* e);
        void startTheGame();
        bool isBonnePlace(TraxEmplacement* e);
        bool isCoupForce(int x,int y);
        void racks(int x,int y);
        void info(TraxEmplacement* e);

        bool detectoCircuit(char c,TraxEmplacement* e);
        bool detectoLigne(char c);
        bool detectoLigneHori(TraxEmplacement* e,char c);
        bool detectoLigneVert(TraxEmplacement* e,char c);

        void joueurSuivant();

        
};


#endif