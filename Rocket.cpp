#include "Rocket.h"
#include <iostream>


Rocket::Rocket() : Object("rocket.png"), Wall(0.f, 0.f, 10.f, 10.f)
{
	sprite->setPosition(float((320 - 120) / 2), float(240 - 32 + 13));
	velocity = 3.f;
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

bool Rocket::intersects(sf::FloatRect* bounds) {
	return sprite->getGlobalBounds().intersects(*bounds);
}

void Rocket::bounceTheBall(Ball* ball) {
	ball->bounceFrom(this);
}

Rocket::~Rocket()
{
}