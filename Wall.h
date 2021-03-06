#pragma once
#include "Ball.h"
class Wall
{
protected:
	sf::FloatRect* wall;
public:
	Wall(float left, float top, float width, float height);
	virtual bool intersects(Ball* ball);
	virtual void bounceTheBall(Ball* ball) = 0;
	~Wall();
};

