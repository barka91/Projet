#include"Joueur.hpp"
#include<iostream>

using namespace std;

Joueur::Joueur(int i):id{i}, point{0}, current{false}{
     
	font.loadFromFile("assets/fonts/roboto.ttf");
    JText.setFont(font);
    string name = "Joueur "+to_string(id);
    JText.setString(name);
    JText.setFillColor(Color::White);
    JText.setCharacterSize(25);
    JText.setPosition(Vector2f(10.0f,300.0f + 70.f * i));

    JScore.setFont(font);
    JScore.setString(to_string(point));
    JScore.setFillColor(Color::White);
    JScore.setCharacterSize(25);
    JScore.setPosition(Vector2f(150.0f,300.0f + 70.f * i));

}

Joueur::~Joueur(){}

ostream& operator<<(ostream& out, Joueur &j){
    out << "Joueur est " << j.getId() << endl;
    return out;
}

int Joueur::getId(){return id;}
int Joueur::getPoint(){return point;}

void Joueur::setPoint(int p){
    point += p;
    JScore.setString(to_string(point));

}

void Joueur::setCurrent(bool c)
{   
    current = c;
    if (c)
    {
        JText.setFillColor(Color::Red);
        JScore.setFillColor(Color::Red);
    }
    else
    {
        JText.setFillColor(Color::White);
        JScore.setFillColor(Color::White);
    }

}

bool Joueur::getCurrent(){
    return current;
}

Text Joueur::getJText(){
    return JText;
}

Text Joueur::getJScore(){
    return JScore;
}


