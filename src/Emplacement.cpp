#include "Emplacement.hpp"

Emplacement::Emplacement(Vector2f pos){
    sprite.setFillColor(Color::Blue);
    sprite.setSize(Vector2f(100.f,100.f));
	auto bounds = sprite.getLocalBounds();
	sprite.setOrigin( bounds.width / 2.f, bounds.height / 2.f );
    sprite.setPosition(pos);
    
}

RectangleShape Emplacement::getShape()
{
    return sprite;
}