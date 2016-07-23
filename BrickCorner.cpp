#include "BrickCorner.h"
#include <iostream>

BrickCorner::BrickCorner(float left, float top, float width, float height) : 
	Wall(left, top, width, height), 
	Object()
{
}


BrickCorner::~BrickCorner()
{
}

Circle* BrickCorner::getCircleBounds() {
	float radius = wall->width / 2.f;
	float x = wall->left + radius;
	float y = wall->top + radius;
	delete circle;
	circle = new Circle(new sf::Vector2f(x, y), radius);
	return circle;
}

void BrickCorner::bounceTheBall(Ball* ball) {
	ball->bounceFrom(this);
}

