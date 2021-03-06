#include "Model.h"
#include "Draw.h"
#include <iostream>

Model::Model() {
	height = 400.f;
	width = 500.f;
	window = new sf::RenderWindow(sf::VideoMode(width, height), "Ball");
	sf::Vector2f* ballVelocity = new sf::Vector2f(2.8f, 2.8f);  // it is deleted in ball.cpp
	ball = new Ball(ballVelocity);
	rocket = new Rocket(float((width - 120) / 2), float(height - 32 + 13));

	createBricks();

	objectsToDraw = new vector<Draw*>();

	objectsToDraw->push_back(rocket);
	objectsToDraw->push_back(ball);
}

void Model::createBricks() {
	brickArray = new vector<Brick*>();
	Brick* brick = new Brick(0.f, 0.f);

	int n = 5;
	int m = 3;
	
	sf::FloatRect bound = brick->getGlobalBounds();
	float horizontalPause = (getWidth() - (n * bound.width)) / (n + 1);
	float verticalPause = 10.f;
	float horizontalPosition = 0.f;
	float verticalPosition = 0.f;

	for (int i = 0; i < m; i++) {
		verticalPosition += verticalPause;
		horizontalPosition += horizontalPause;
		for (int j = 0; j < n; j++) {
			brickArray->push_back(new Brick(horizontalPosition, verticalPosition));
			horizontalPosition += bound.width + horizontalPause;
		}
		verticalPosition += bound.height;
		horizontalPosition = 0.f;
	}
	delete brick;
}

Rocket* Model::getRocket() {
	return rocket;
}

vector<Draw*>* Model::getObjectsToDraw() {
	return objectsToDraw;
}

sf::RenderWindow* Model::getWindow() {
	return window;
}

vector<Brick*>* Model::getBrickArray() {
	return brickArray;
}

Ball* Model::getBall() {
	return ball;
}

float Model::getHeight() {
	return height;
}

float Model::getWidth() {
	return width;
}

Model::~Model() {
	delete ball;
	delete window;
	delete objectsToDraw;
	delete rocket;
}