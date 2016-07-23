#include "Brick.h"
#include <iostream>

Brick::Brick(float x, float y) : Object("brick.png"), Wall(0.f, 0.f, 10.f, 10.f) {
	sprite->setPosition(x, y);
	walls = new vector<Wall*>();
	sf::FloatRect bounds = sprite->getGlobalBounds();

	float n = bounds.height * 10.f / 27.f;
	float nn = 2 * n;

	walls->push_back(new RightWall(bounds.left, bounds.top + n, n, bounds.height - nn));
	walls->push_back(new LeftWall(bounds.left + bounds.width - n, bounds.top + n, n, bounds.height - nn));
	walls->push_back(new DownWall(bounds.left + n, bounds.top, bounds.width - nn, n));
	walls->push_back(new UpWall(bounds.left + n, bounds.top + bounds.height - n, bounds.width - nn, n));
	walls->push_back(new BrickCorner(bounds.left, bounds.top, nn, nn));
	walls->push_back(new BrickCorner(bounds.left, bounds.top + bounds.height - nn, nn, nn));
	walls->push_back(new BrickCorner(bounds.left + bounds.width - nn, bounds.top + bounds.height - nn, nn, nn));
	walls->push_back(new BrickCorner(bounds.left + bounds.width - nn, bounds.top, nn, nn));
}

Brick::~Brick() {
}


bool Brick::intersects(sf::FloatRect* bounds) {
	return sprite->getGlobalBounds().intersects(*bounds);
}

void Brick::bounceTheBall(Ball* ball) {
	sf::FloatRect ballBounds = ball->getGlobalBounds();
	for (int i = 0; i < walls->size(); i++) {
		if (walls->at(i)->intersects(&ballBounds)) {
			walls->at(i)->bounceTheBall(ball);
			break;
		}
	}
}