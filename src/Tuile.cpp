#include "Tuile.hpp"

Tuile::Tuile(Vector2f pos,Color c)
{
    // initialisation de la forme de la DomTuile
    sprite.setFillColor(c);
    sprite.setSize(Vector2f(100.f,100.f));
	auto bounds = sprite.getLocalBounds();
	sprite.setOrigin( bounds.width / 2.f, bounds.height / 2.f );

    
}
Tuile::Tuile(Tuile &t):sprite{t.getSprite()}
{
}
Tuile::Tuile()
{
    sprite.setFillColor(Color::Blue);
    sprite.setSize(Vector2f(100.f,100.f));
	auto bounds = sprite.getLocalBounds();
	sprite.setOrigin( bounds.width / 2.f, bounds.height / 2.f );
}

Tuile::~Tuile()
{
}

RectangleShape Tuile::getSprite(){return sprite;}

Vector2f Tuile::getPosition(){return sprite.getPosition();}

void Tuile::setPosition(Vector2f pos){
    sprite.setPosition(pos);
}