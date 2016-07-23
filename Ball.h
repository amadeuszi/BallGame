#pragma once
#include <SFML/Graphics.hpp>
#include "Circle.h"
#include "Draw.h"
#include "Object.h"
#include "Vectors.h"
using namespace std;
class Ball : public Object {
	sf::Vector2f* velocity;
	Vectors* vectors;
	void setVelocity(sf::Vector2f* v);
	bool isGoingTowards(Object* object);
	void setPosition(float x, float y);
public:
	Ball(sf::Vector2f* v);
	~Ball();
	void geOutOf(Object* object);
	void bounceFrom(Object* object);
	void move();
	void goDown();
	void goUp();
	void goLeft();
	void goRight();
};