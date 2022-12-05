#ifndef _WALL
#define _WALL

#include <SFML/Graphics.hpp>


using namespace sf;

class Wall {
private:
  RectangleShape wallShape;

public:
    Wall(Vector2f position, Vector2f size);

    RectangleShape getShape();
};


#endif //NIBBLES_WALL_HPP
