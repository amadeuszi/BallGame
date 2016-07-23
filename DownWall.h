#pragma once
#include "Wall.h"
class DownWall :
	public Wall
{
public:
	DownWall(float left, float top, float width, float height);
	~DownWall();
	void bounceTheBall(Ball* ball);
};

