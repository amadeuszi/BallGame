#pragma once
#include <SFML/Graphics.hpp>
class Draw
{
public:
	virtual void draw(sf::RenderWindow* window) = 0;
	Draw();
	~Draw();
};

