#ifndef _JOUEUR
#define _JOUEUR
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Joueur{
    private:
        int id;
        const string pseudo;
        int point;
        
    public:
        Joueur(string p,int i);
        virtual ~Joueur();
        string getPseudo();
        void setPoint(int p);

    friend ostream& operator <<(ostream& out, Joueur &j) ;
        
};

#endif