#pragma once
#include "Wall.h"
#include "Object.h"
class BrickCorner : public Wall, public Object
{
public:
	BrickCorner(float left, float top, float width, float height);
	Circle* getCircleBounds();
	void bounceTheBall(Ball* ball);
	~BrickCorner();
};

