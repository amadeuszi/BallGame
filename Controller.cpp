#include "Controller.h"
#include <iostream>
#include <math.h>
#include <vector>
#include "LeftWall.h"
#include "RightWall.h"
#include "DownWall.h"
#include "UpWall.h"

Controller::Controller() {
	model = new Model();
	view = new Viewer(model);

	walls = new vector<Wall*>();
	float n;
	walls->push_back(new LeftWall(-20.f, -20.f, 20.f, 1000.f));
	walls->push_back(new DownWall(-20.f, 240.f, 1000.f, 20.f));
	walls->push_back(new RightWall(320.f, -20.f, 20.f, 1000.f));
	walls->push_back(new UpWall(-20.f, -20.f, 1000.f, 20.f));

	sf::RenderWindow* window = model->getWindow();
	window->setFramerateLimit(60);
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();

		} //while

		window->clear();

		view->displayAll();

		ballWallCollisions();
		ballRocketCollisions();
		ballBrickCollisions();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && isRocketMoveableLeft()) {
			model->getRocket()->moveLeft();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && isRocketMoveableRight()) {
			model->getRocket()->moveRight();
		}
		
		model->getBall()->move();
		
		window->display();
	} //while
}

bool Controller::isRocketMoveableLeft() {
	return model->getRocket()->getGlobalBounds().left + 10 > 0;
}

bool Controller::isRocketMoveableRight() {
	sf::FloatRect bounds = model->getRocket()->getGlobalBounds();
	return bounds.left + bounds.width - 10 < 320;
}

void Controller::ballWallCollisions() {
	Ball* ball = model->getBall();
	sf::FloatRect bounds = ball->getGlobalBounds();

	for (int i = 0; i < walls->size(); i++) {
		if (walls->at(i)->intersects(&bounds)) {
			walls->at(i)->bounceTheBall(ball);
		}
	}
}

void Controller::ballRocketCollisions() {
	Ball* ball = model->getBall();
	Rocket* rocket = model->getRocket();

	Circle* rocketCircle = rocket->getCircleBounds();
	Circle* ballCircle = ball->getCircleBounds();

	if (ballCircle->intersects(rocketCircle)) {
		ball->bounceFrom(rocket);
		ball->geOutOf(rocket);
	}
}

void Controller::ballBrickCollisions() {
	Ball* ball = model->getBall();
	vector<Brick*>* brickArray = model->getBrickArray();
	sf::FloatRect bounds = ball->getGlobalBounds();

	for (int i = 0; i < brickArray->size(); i++) {
		if (brickArray->at(i)->intersects(&bounds)) {
			brickArray->at(i)->bounceTheBall(ball);
			brickArray->erase(brickArray->begin() + i);
		}
	}
}

void Controller::ballBrickCollisions2() {
	ballCollisions(model->getBrickArray());
}

void Controller::ballCollisions(vector<Wall*>* v) {
	Ball* ball = model->getBall();
	sf::FloatRect bounds = ball->getGlobalBounds();

	for (int i = 0; i < v->size(); i++) {
		if (v->at(i)->intersects(&bounds)) {
			v->at(i)->bounceTheBall(ball);
			v->erase(v->begin() + i);
		}
	}
}

Controller::~Controller()
{
	delete model;
	delete view;
}