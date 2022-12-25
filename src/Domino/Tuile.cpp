#include "Domino/Tuile.hpp"
#include<iostream>
#include <vector>
#include<string>

using namespace std;

Tuile::Tuile(vector<int> h,vector<int> d,vector<int> b,vector<int> g, Vector2f pos) {

    haut=h;
    droite=d;
    bas=b;
    gauche=g;

    // initialisation de la forme de la tuile
    sprite.setFillColor(Color::White);
    sprite.setSize(Vector2f(100.f,100.f));
	auto bounds = sprite.getLocalBounds();
	sprite.setOrigin( bounds.width / 2.f, bounds.height / 2.f );
    // sf::Vector2f(SCRWIDTH/2.0f,SCRHEIGHT/2.0f)

    // chargement de la police
	font.loadFromFile("assets/fonts/roboto.ttf");

    // initialisation du haut de la tuile 
    setupTextV(&top,font,getHaut(),20,Color::Red,0);

    // initialisation de la partie gauche de la tuile
    setupTextS(&left0,font,to_string(getGauche().at(0)),20,Color::Green,0);
    setupTextS(&left1,font,to_string(getGauche().at(1)),20,Color::Green,0);
    setupTextS(&left2,font,to_string(getGauche().at(2)),20,Color::Green,0);

    // initialisation de la partie droite de la tuile
    setupTextS(&right0,font,to_string(getDroite().at(0)),20,Color::Magenta,0);
    setupTextS(&right1,font,to_string(getDroite().at(1)),20,Color::Magenta,0);
    setupTextS(&right2,font,to_string(getDroite().at(2)),20,Color::Magenta,0);

    // initialisation du bas de la tuile
    setupTextV(&down,font,getBas(),20,Color::Cyan,0);

    // initialisation de la position de la tuile 
    setPosition(pos);

    cout<<"Construction de "<< *this<<endl;
}

Tuile::Tuile(Tuile &t):
    haut{t.getHaut()},
    droite{t.getDroite()},
    bas{t.getBas()},
    gauche{t.getGauche()},
    sprite{t.getSprite()},
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

Tuile::Tuile(){
    sprite.setFillColor(Color::Blue);
    sprite.setSize(Vector2f(100.f,100.f));
	auto bounds = sprite.getLocalBounds();
	sprite.setOrigin( bounds.width / 2.f, bounds.height / 2.f );
}

Tuile::~Tuile(){
     cout<<"Destruction de tuile "<<*this<<endl;
}

vector<int> Tuile::getBas(){return bas;}
vector<int> Tuile::getDroite(){return droite;}
vector<int> Tuile::getHaut(){return haut;}
vector<int> Tuile::getGauche(){return gauche;}

RectangleShape Tuile::getSprite(){return sprite;}

Font Tuile::getFont(){return font;}

Text Tuile::getTop(){return top;}
Text Tuile::getLeft0(){return left0;}
Text Tuile::getLeft1(){return left1;}
Text Tuile::getLeft2(){return left2;}
Text Tuile::getRight0(){return right0;}
Text Tuile::getRight1(){return right1;}
Text Tuile::getRight2(){return right2;}
Text Tuile::getDown(){return down;}

Vector2f Tuile::getPosition(){return sprite.getPosition();}

void Tuile::setPosition(Vector2f pos){
    sprite.setPosition(pos);
	top.setPosition(pos.x,pos.y-40.f);
	left0.setPosition(pos.x-40.f,pos.y-20);
	left1.setPosition(pos.x-40.f,pos.y);
	left2.setPosition(pos.x-40.f,pos.y+20);
    right0.setPosition(pos.x+40.f,pos.y-20);
    right1.setPosition(pos.x+40.f,pos.y);
    right2.setPosition(pos.x+40.f,pos.y+20);
	down.setPosition(pos.x,pos.y+35.f);
}

void Tuile::setTuileString(vector<int> v,Text* t)
{
    string buffer;
    for(int i=0; i<3; i++)
        buffer.append(to_string(v.at(i))+" ");
	t->setString(buffer);
}

void Tuile::setTuileGD(vector<int> v, string cote)
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

void Tuile::setBas(vector<int> t) { bas = t; }
void Tuile::setDroite(vector<int> t){ droite = t;}
void Tuile::setGauche(vector<int> t){ gauche = t;}
void Tuile::setHaut(vector<int> t){ haut = t;}

// Tuile* Tuile::getNord(){return nord;}

void Tuile::tourner(){
    vector<int> tmpH = getHaut();
    setHaut( getGauche() );
    setTuileString(haut,&top);
    vector<int> tmpD = getDroite();
    setDroite( tmpH );
    setTuileGD(droite,"droite");
    vector<int> tmpB = getBas();
    setBas( tmpD );
    setTuileString(bas,&down);
    setGauche( tmpB );
    setTuileGD(gauche,"gauche");
    cout<<getBas().at(0)<<getBas().at(1)<<getBas().at(2)<<endl;
}

void Tuile::setupTextV(Text *textItem, const Font &font, const vector<int> v, int size, Color colour,float angle) {
    textItem->setFont(font);
    setTuileString(v,textItem);
    textItem->setCharacterSize(size);
    textItem->setFillColor(colour);

    auto bounds = textItem->getLocalBounds();
    textItem->setOrigin( bounds.width / 2.f, bounds.height / 2.f );
    textItem->setRotation(angle);
}

void Tuile::setupTextS(Text *textItem, const Font &font, const string s, int size, Color colour, float angle)
{
    textItem->setFont(font);
    textItem->setString(s);
    textItem->setCharacterSize(size);
    textItem->setFillColor(colour);

    auto bounds = textItem->getLocalBounds();
    textItem->setOrigin( bounds.width / 2.f, bounds.height / 2.f );
    textItem->setRotation(angle);
}

ostream& operator<<( ostream& out , Tuile &t){
    // out<<"Tuile\n  ";
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

