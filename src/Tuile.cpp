#include "Tuile.hpp"
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
    setupText(&top,font,getHaut(),20,Color::Red,0);

    // initialisation de la partie gauche de la tuile
    setupText(&left,font,getGauche(),20,Color::Green,-90.f);

    // initialisation de la partie droite de la tuile
    setupText(&right,font,getDroite(),20,Color::Magenta,90.f);

    // initialisation du bas de la tuile
    setupText(&down,font,getBas(),20,Color::Cyan,0);

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
    left{t.getLeft()},
    right{t.getRight()},
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
Text Tuile::getLeft(){return left;}
Text Tuile::getRight(){return right;}
Text Tuile::getDown(){return down;}

Vector2f Tuile::getPosition(){return sprite.getPosition();}

void Tuile::setPosition(Vector2f pos){
    sprite.setPosition(pos);
	top.setPosition(pos.x,pos.y-40.f);
	left.setPosition(pos.x-40.f,pos.y);	
    right.setPosition(pos.x+40.f,pos.y);
	down.setPosition(pos.x,pos.y+30.f);
}

void Tuile::setTuileString(vector<int> v,Text* t)
{
    string buffer;
    for(int i=0; i<3; i++)
        buffer.append(to_string(v.at(i))+" ");
	t->setString(buffer);
    
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
    setTuileString(droite,&right);
    vector<int> tmpB = getBas();
    setBas( tmpD );
    setTuileString(bas,&down);
    setGauche( tmpB );
    setTuileString(gauche,&left);
    cout<<getBas().at(0)<<getBas().at(1)<<getBas().at(2)<<endl;
}

void Tuile::setupText(Text *textItem, const Font &font, const vector<int> v, int size, Color colour,float angle) {
    textItem->setFont(font);
    setTuileString(v,textItem);
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

