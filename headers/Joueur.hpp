#ifndef _JOUEUR
#define _JOUEUR
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Joueur{
    private:
        int id;
        
        int point;
        
    public:
        Joueur(int i);
        virtual ~Joueur();
        int getId();
        void setPoint(int p);

    friend ostream& operator <<(ostream& out, Joueur &j) ;
        
};

#endif