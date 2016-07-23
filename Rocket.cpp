#include "Rocket.h"
#include <iostream>


Rocket::Rocket(float x, float y) : Object("rocket.png"), Wall(0.f, 0.f, 10.f, 10.f)
{
	sprite->setPosition(x, y);
	velocity = 4.f;
}

Circle* Rocket::getCircleBounds() {
	delete circle;
	
	sf::FloatRect bounds = sprite->getGlobalBounds();
	float radius = 85;
	float x = bounds.left + 60;
	float y = bounds.top + 85;

	circle = new Circle(new sf::Vector2f(x, y), radius);
	return circle;
}

void Rocket::moveLeft() {
		sprite->move(-velocity, 0);
}

void Rocket::moveRight() {
		sprite->move(velocity, 0);
}

bool Rocket::intersects(Ball* ball) {
	return getCircleBounds()->intersects(ball->getCircleBounds());
}

void Rocket::bounceTheBall(Ball* ball) {
	ball->bounceFrom(this);
	ball->geOutOf(this);
}

Rocket::~Rocket()
{
}