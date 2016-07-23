#include "Vectors.h"



Vectors::Vectors() {
	norm = new sf::Vector2f(0.f, 0.f);
}


Vectors::~Vectors() {
	delete norm;
}

void Vectors::setLength(sf::Vector2f* v, float len) {
	normalize(v);
	v->x *= len;
	v->y *= len;
}

//Warning! this vector is deleted only in Ball.cpp, it doesn't delete automatically like my other pointers
sf::Vector2f* Vectors::bounceVector(sf::Vector2f* ballVelocity, sf::Vector2f* norm) {
	float x = ballVelocity->x - 2 * norm->x * dotProduct(norm, ballVelocity);
	float y = ballVelocity->y - 2 * norm->y * dotProduct(norm, ballVelocity);
	return new sf::Vector2f(x, y);
}

sf::Vector2f* Vectors::computeNormToSurface(Circle* ball, Circle* surface) {
	delete norm;
	sf::Vector2f* ballV = ball->getCenter();
	sf::Vector2f* rocketV = surface->getCenter();
	
	norm = new sf::Vector2f(ballV->x - rocketV->x, ballV->y - rocketV->y);
	normalize(norm);
	return norm;
}

float Vectors::dotProduct(sf::Vector2f* v, sf::Vector2f* w) {
	return v->x * w->x + v->y * w->y;
}

void Vectors::normalize(sf::Vector2f* v) {
	float len = length(v);
	v->x /= len;
	v->y /= len;
}

float Vectors::length(sf::Vector2f* v) {
	return sqrt(dotProduct(v, v));
}