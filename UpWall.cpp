#include "UpWall.h"

UpWall::UpWall(float left, float top, float width, float height) :
	Wall(left, top, width, height)
{
}

UpWall::~UpWall()
{
}

void UpWall::bounceTheBall(Ball* ball) {
	ball->goDown();
}