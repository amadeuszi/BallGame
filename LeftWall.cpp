#include "LeftWall.h"



LeftWall::LeftWall(float left, float top, float width, float height) :
	Wall(left,top, width, height)
{
}


LeftWall::~LeftWall()
{
}


void LeftWall::bounceTheBall(Ball* ball) {
	ball->goRight();
}