#pragma once
#include <string>
#include "Draw.h"
#include "Object.h"
#include <vector>
#include "Wall.h"
#include "LeftWall.h"
#include "RightWall.h"
#include "UpWall.h"
#include "DownWall.h"
#include "BrickCorner.h"
using namespace std;

class Brick : public Object, public Wall {
	vector<Wall*>* walls;
public:
	bool intersects(Ball* ball);
	void bounceTheBall(Ball* ball);
	Brick(float x, float y);
	~Brick();
};

