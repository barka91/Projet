#ifndef _TUILE
#define _TUILE
#include<iostream>
#include<string>

using namespace std;

class Tuile{
    private:
        int *haut,*droite,*bas,*gauche;
    
    public:
        Tuile(int* h,int* d,int* b,int* g);
        virtual ~Tuile();
        int* Haut();
        int* Droite();
        int* Bas();
        int* Gauche();
        void setH(int* t);
        void setD(int* t);
        void setB(int* t);
        void setG(int* t);
        void tourner();

    friend ostream& operator <<(ostream& out, Tuile &t) ;        
};

#endif