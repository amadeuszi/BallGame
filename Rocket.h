#pragma once
#include "Draw.h"
#include "Circle.h"
#include "Object.h"
#include "Wall.h"
using namespace std;
class Rocket : public Object, public Wall {
	float velocity;
public:
	Circle* getCircleBounds();
	bool intersects(sf::FloatRect* bounds);
	void bounceTheBall(Ball* ball);
	void moveRight();
	void moveLeft();
	Rocket();
	~Rocket();
};