#include "Circle.h"
#include <math.h>


Circle::Circle(sf::Vector2f* c, float r) {
	center = c;
	radius = r;
}

sf::Vector2f* Circle::getCenter() {
	return center;
}

float Circle::getRadius() {
	return radius;
}

bool Circle::intersects(Circle* circle) {
	return length(center, circle->getCenter()) <= radius + circle->getRadius();
}

float Circle::length(sf::Vector2f* first, sf::Vector2f* second) {
	return sqrt((first->x - second->x) * (first->x - second->x) + (first->y - second->y) * (first->y - second->y));
}

Circle::~Circle() {
	delete center;
}
