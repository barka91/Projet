#include "Trax/TraxTuile.hpp"

TraxTuile::TraxTuile(Vector2f pos,string s) : Tuile(pos,Color::Red)
{
    if(!texture.loadFromFile(s)) cout<<"erreur chargement Trax1"<<endl;
    sprite.setTexture(texture);
    auto bounds = sprite.getLocalBounds();
    sprite.setOrigin( bounds.width / 2.f, bounds.height / 2.f );
    sprite.setPosition(pos);

// init les image dans traxtuile 
} 

TraxTuile::~TraxTuile()
{
}

Sprite TraxTuile::getSprite()
{
    return sprite;
}
void TraxTuile::setPosition(Vector2f pos)
{
    sprite.setPosition(pos);
}

void TraxTuile::tourner()
{
    sprite.rotate(90);
}
