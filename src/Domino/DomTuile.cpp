#include "Domino/DomTuile.hpp"
#include<iostream>
#include <vector>
#include<string>

using namespace std;

DomTuile::DomTuile(vector<int> h,vector<int> d,vector<int> b,vector<int> g, Vector2f pos): Tuile(pos,Color::White) {

    haut=h;
    droite=d;
    bas=b;
    gauche=g;

    // chargement de la police
	font.loadFromFile("assets/fonts/roboto.ttf");

    // initialisation du haut de la DomTuile 
    setupTextV(&top,font,getHaut(),20,Color::Red,0);

    // initialisation de la partie gauche de la DomTuile
    setupTextS(&left0,font,to_string(getGauche().at(0)),20,Color::Green,0);
    setupTextS(&left1,font,to_string(getGauche().at(1)),20,Color::Green,0);
    setupTextS(&left2,font,to_string(getGauche().at(2)),20,Color::Green,0);

    // initialisation de la partie droite de la DomTuile
    setupTextS(&right0,font,to_string(getDroite().at(0)),20,Color::Magenta,0);
    setupTextS(&right1,font,to_string(getDroite().at(1)),20,Color::Magenta,0);
    setupTextS(&right2,font,to_string(getDroite().at(2)),20,Color::Magenta,0);

    // initialisation du bas de la DomTuile
    setupTextV(&down,font,getBas(),20,Color::Cyan,0);

    // initialisation de la position de la DomTuile 
    setPosition(pos);

    cout<<"Construction de "<< *this<<endl;
}

DomTuile::DomTuile(DomTuile &t): Tuile(t),
    haut{t.getHaut()},
    droite{t.getDroite()},
    bas{t.getBas()},
    gauche{t.getGauche()},
    
    font{t.getFont()},
    top{t.getTop()},
    left0{t.getLeft0()},
    left1{t.getLeft1()},
    left2{t.getLeft2()},
    right0{t.getRight0()},
    right1{t.getRight1()},
    right2{t.getRight2()},
    down{t.getDown()}
{
    // constructeur par copie
}

DomTuile::DomTuile():Tuile(){
;
}

DomTuile::~DomTuile(){
     cout<<"Destruction de DomTuile "<<*this<<endl;
}

vector<int> DomTuile::getBas(){return bas;}
vector<int> DomTuile::getDroite(){return droite;}
vector<int> DomTuile::getHaut(){return haut;}
vector<int> DomTuile::getGauche(){return gauche;}

Font DomTuile::getFont(){return font;}

Text DomTuile::getTop(){return top;}
Text DomTuile::getLeft0(){return left0;}
Text DomTuile::getLeft1(){return left1;}
Text DomTuile::getLeft2(){return left2;}
Text DomTuile::getRight0(){return right0;}
Text DomTuile::getRight1(){return right1;}
Text DomTuile::getRight2(){return right2;}
Text DomTuile::getDown(){return down;}



void DomTuile::setPosition(Vector2f pos){
    Tuile::setPosition(pos);
	top.setPosition(pos.x,pos.y-40.f);
	left0.setPosition(pos.x-40.f,pos.y-20);
	left1.setPosition(pos.x-40.f,pos.y);
	left2.setPosition(pos.x-40.f,pos.y+20);
    right0.setPosition(pos.x+40.f,pos.y-20);
    right1.setPosition(pos.x+40.f,pos.y);
    right2.setPosition(pos.x+40.f,pos.y+20);
	down.setPosition(pos.x,pos.y+35.f);
}

void DomTuile::setDomTuileString(vector<int> v,Text* t)
{
    string buffer;
    for(int i=0; i<3; i++)
        buffer.append(to_string(v.at(i))+" ");
	t->setString(buffer);
}

void DomTuile::setDomTuileGD(vector<int> v, string cote)
{
    if (cote=="gauche"){
        left0.setString(to_string(v.at(0)));
        left1.setString(to_string(v.at(1)));
        left2.setString(to_string(v.at(2)));
    }
    if (cote=="droite"){
        right0.setString(to_string(v.at(0)));
        right1.setString(to_string(v.at(1)));
        right2.setString(to_string(v.at(2)));
    }
        
}

void DomTuile::setBas(vector<int> t) { bas = t; }
void DomTuile::setDroite(vector<int> t){ droite = t;}
void DomTuile::setGauche(vector<int> t){ gauche = t;}
void DomTuile::setHaut(vector<int> t){ haut = t;}

// DomTuile* DomTuile::getNord(){return nord;}

void DomTuile::tourner(){
    vector<int> tmpH = getHaut();
    setHaut( getGauche() );
    setDomTuileString(haut,&top);
    vector<int> tmpD = getDroite();
    setDroite( tmpH );
    setDomTuileGD(droite,"droite");
    vector<int> tmpB = getBas();
    setBas( tmpD );
    setDomTuileString(bas,&down);
    setGauche( tmpB );
    setDomTuileGD(gauche,"gauche");
    cout<<getBas().at(0)<<getBas().at(1)<<getBas().at(2)<<endl;
}

void DomTuile::setupTextV(Text *textItem, const Font &font, const vector<int> v, int size, Color colour,float angle) {
    textItem->setFont(font);
    setDomTuileString(v,textItem);
    textItem->setCharacterSize(size);
    textItem->setFillColor(colour);

    auto bounds = textItem->getLocalBounds();
    textItem->setOrigin( bounds.width / 2.f, bounds.height / 2.f );
    textItem->setRotation(angle);
}

void DomTuile::setupTextS(Text *textItem, const Font &font, const string s, int size, Color colour, float angle)
{
    textItem->setFont(font);
    textItem->setString(s);
    textItem->setCharacterSize(size);
    textItem->setFillColor(colour);

    auto bounds = textItem->getLocalBounds();
    textItem->setOrigin( bounds.width / 2.f, bounds.height / 2.f );
    textItem->setRotation(angle);
}

ostream& operator<<( ostream& out , DomTuile &t){
    // out<<"DomTuile\n  ";
    // for(int i=0; i<3; i++)
    //     out<<t.getHaut().at(i)<<" ";
    // out<<" \n";
    // for(int i=0; i<3; i++)
    //     out<<t.getGauche()[3-i-1]<<"       "<<t.getDroite()[i]<<endl;
    // out<<"  ";
    // for( int i=2; i>=0; i--)
    //     out<<t.getBas().at(i)<<" ";
    // out<<" ";
    // return out ;
}

