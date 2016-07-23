#include "Ball.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
Ball::Ball(sf::Vector2f* v) : Object("ball.png") {
	texture = new sf::Texture();
	velocity = v;
	vectors = new Vectors();

	sprite->setScale(0.7f, 0.7f);
	sprite->setPosition(100.f, 100.f);
}

void Ball::goDown() {
	velocity->y = abs(velocity->y);
}
void Ball::goUp() {
	velocity->y = -abs(velocity->y);
}
void Ball::goLeft() {
	velocity->x = -abs(velocity->x);
}
void Ball::goRight() {
	velocity->x = abs(velocity->x);
}

void Ball::move() {
	sprite->move(*velocity);
}

void Ball::setVelocity(sf::Vector2f* v) {
	delete velocity;
	velocity = v;
}

void Ball::setPosition(float x, float y) {
	sprite->setPosition(x, y);
}

bool Ball::isGoingTowards(Object* object) {
	sf::Vector2f* ball = getCircleBounds()->getCenter();
	sf::Vector2f* bouncer = object->getCircleBounds()->getCenter();
	sf::Vector2f* ballToObjectVector = new sf::Vector2f(bouncer->x - ball->x, bouncer->y - ball->y);

	bool result = vectors->dotProduct(ballToObjectVector, velocity) >= 0.f;

	delete ballToObjectVector;
	return result;
}

void Ball::bounceFrom(Object* object) {
	if (!isGoingTowards(object)) {
		return;
	}

	Circle* ballCircle = getCircleBounds();
	Circle* objectCircle = object->getCircleBounds();

	sf::Vector2f* normal = vectors->computeNormToSurface(ballCircle, objectCircle);
	sf::Vector2f* newVector = vectors->bounceVector(velocity, normal);
	
	setVelocity(newVector);
}

void Ball::geOutOf(Object* object) {
	Circle* bouncer = object->getCircleBounds();
	Circle* ball = getCircleBounds();
	sf::Vector2f* normal = vectors->computeNormToSurface(ball, bouncer);

	vectors->setLength(normal, bouncer->getRadius() + ball->getRadius());
	sf::Vector2f* bouncerCenter = bouncer->getCenter();

	setPosition(bouncerCenter->x + normal->x - ball->getRadius(), bouncerCenter->y + normal->y - ball->getRadius());
}

Ball::~Ball() {
	delete velocity;
	delete vectors;
}
