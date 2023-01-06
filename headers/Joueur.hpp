#ifndef _JOUEUR
#define _JOUEUR
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<vector>

using namespace std;
using namespace sf;


class Joueur{
    private:
        const int id;
        int point;
        bool current;            
        // s'occuper de la couleur du joueur et afficher le score a la fin
        Font font;
        Text JText;
        Text JScore;

        
    public:
        Joueur(int i);
        virtual ~Joueur();
        int getId();
        int getPoint();
        bool getCurrent();
        
        void setPoint(int p);
        void setCurrent(bool c);

        Text getJText();
        Text getJScore();


        


    friend ostream& operator <<(ostream& out, Joueur &j) ;
        
};

#endif