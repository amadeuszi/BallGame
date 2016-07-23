#pragma once
#include "Wall.h"
class RightWall :
	public Wall
{
public:
	RightWall(float left, float top, float width, float height);
	~RightWall();
	void bounceTheBall(Ball* ball);
};

