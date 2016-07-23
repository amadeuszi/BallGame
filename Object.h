#pragma once
#include "Circle.h"
#include <iostream>
#include "Draw.h"
using namespace std;
class Object : public Draw
{
protected:
	sf::Sprite* sprite;
	sf::Texture* texture;
	Circle* circle;
public:
	Object(string textureName);
	Object();
	~Object();
	sf::FloatRect getGlobalBounds();
	virtual Circle* getCircleBounds();
	void draw(sf::RenderWindow* window);

};

