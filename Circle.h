#pragma once
#include <SFML/Graphics.hpp>
class Circle
{
	sf::Vector2f* center;
	float radius;
	float length(sf::Vector2f* first, sf::Vector2f* second);
public:
	Circle(sf::Vector2f* c, float r);
	sf::Vector2f* getCenter();
	float getRadius();
	bool intersects(Circle* circle);
	~Circle();
};

