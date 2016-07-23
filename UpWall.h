#pragma once
#include "Wall.h"
class UpWall :
	public Wall
{
public:
	UpWall(float left, float top, float width, float height);
	~UpWall();
	void bounceTheBall(Ball* ball);
};

