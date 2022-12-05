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
	top.setFont(font);
    // top.setString("1   2   3");
    setTuileString(getHaut(),&top);
	top.setCharacterSize(20);
  	top.setFillColor(Color::Red);
	auto boundsTop = top.getLocalBounds();
	top.setOrigin( boundsTop.width / 2.f, boundsTop.height / 2.f );

    // initialisation de la partie gauche de la tuile
    left.setFont(font);
    setTuileString(getGauche(),&left);
    // top.setString("1   2   3");
	left.setCharacterSize(20);
  	left.setFillColor(Color::Green);
	auto boundsLeft = left.getLocalBounds();
	left.setOrigin( boundsLeft.width / 2.f, boundsLeft.height / 2.f );
    left.setRotation(-90.f);


    // initialisation de la partie droite de la tuile
    right.setFont(font);
    // top.setString("1   2   3");
    setTuileString(getDroite(),&right);
	right.setCharacterSize(20);
  	right.setFillColor(Color::Magenta);
	auto boundsRight = right.getLocalBounds();
	right.setOrigin( boundsRight.width / 2.f, boundsRight.height / 2.f );
    right.setRotation(90.f);

    // initialisation du bas de la tuile
	down.setFont(font);
    setTuileString(getBas(),&down);
	// down.setString("1   2   3");
	down.setCharacterSize(20);
  	down.setFillColor(Color::Cyan);
	auto boundsDown = down.getLocalBounds();
	down.setOrigin( boundsDown.width / 2.f, boundsDown.height / 2.f );

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

void Tuile::setB(vector<int> t) { bas = t; }
void Tuile::setD(vector<int> t){ droite = t;}
void Tuile::setG(vector<int> t){ gauche = t;}
void Tuile::setH(vector<int> t){ haut = t;}

void Tuile::tourner(){
    vector<int> tmpH = getHaut();
    setH( getGauche() );
    vector<int> tmpD = getDroite();
    setD( tmpH );
    vector<int> tmpB = getBas();
    setB( tmpD );
    setG( tmpB );
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

