#include "RightWall.h"



RightWall::RightWall(float left, float top, float width, float height) :
	Wall(left, top, width, height)
{
}


RightWall::~RightWall()
{
}

void RightWall::bounceTheBall(Ball* ball) {
	ball->goLeft();
}