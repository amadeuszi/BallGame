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
	bool intersects(Ball* ball);
	void bounceTheBall(Ball* ball);
	void moveRight();
	void moveLeft();
	Rocket(float x, float y);
	~Rocket();
};