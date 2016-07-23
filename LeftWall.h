#pragma once
#include "Wall.h"
class LeftWall : public Wall {
public:
	LeftWall(float left, float top, float width, float height);
	~LeftWall();
	void bounceTheBall(Ball* ball);
};

