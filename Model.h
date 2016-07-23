#pragma once
#include "Ball.h"
#include <SFML/Graphics.hpp>
#include "Draw.h"
#include "Rocket.h"
#include "Brick.h"

class Model
{
	void createBricks();
	sf::RenderWindow* window;
	Ball* ball;
	Rocket* rocket;
	vector<Brick*>* brickArray;
	vector<Draw*>* objectsToDraw;
	float height;
	float width;
public:
	float getHeight();
	float getWidth();
	vector<Draw*>* getObjectsToDraw();
 	Ball* getBall();
	Rocket* getRocket();
	sf::RenderWindow* getWindow();
	vector<Brick*>* getBrickArray();
	Model();
	~Model();
};

