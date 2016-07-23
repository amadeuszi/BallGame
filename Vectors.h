#pragma once
#include <SFML/Graphics.hpp>
#include "Circle.h"
#include <math.h>
class Vectors
{
	sf::Vector2f* norm;
public:
	Vectors();
	~Vectors();
	sf::Vector2f* bounceVector(sf::Vector2f* ballVelocity, sf::Vector2f* norm);
	void setLength(sf::Vector2f* v, float len);
	sf::Vector2f* computeNormToSurface(Circle* ball, Circle* surface);
	float Vectors::dotProduct(sf::Vector2f* v, sf::Vector2f* w);
	void Vectors::normalize(sf::Vector2f* v);
	float Vectors::length(sf::Vector2f* v);
};

