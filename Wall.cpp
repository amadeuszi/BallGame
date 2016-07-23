#include "Wall.h"



Wall::Wall(float left, float top, float width, float height)
{
	wall = new sf::FloatRect(left, top, width, height);
}


Wall::~Wall()
{
}

bool Wall::intersects(sf::FloatRect* ballBounds) {
	return ballBounds->intersects(*wall);
}