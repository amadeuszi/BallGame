#include "DownWall.h"



DownWall::DownWall(float left, float top, float width, float height) :
	Wall(left, top, width, height)
{
}


DownWall::~DownWall()
{
}

void DownWall::bounceTheBall(Ball* ball) {
	ball->goUp();
}