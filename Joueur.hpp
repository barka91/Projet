#ifndef _JOUEUR
#define _JOUEUR
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Joueur{
    private:
    int id;
    string pseudo;
    int point;
        
    public:
        Joueur(int a);
        virtual ~Joueur();
        int get();
        void set(int a);
};

ostream& operator <<(ostream& out, Joueur &x) ;

#endif