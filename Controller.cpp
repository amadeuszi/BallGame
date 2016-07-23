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
	float n = 50.f;
	float width = model->getWidth();
	float height = model->getHeight();
	walls->push_back(new LeftWall(-n, -n, n, height * 2.f));
	walls->push_back(new DownWall(-n, height, width * 2.f, n));
	walls->push_back(new RightWall(width, -n, n, height * 2.f));
	walls->push_back(new UpWall(-n, -n, width * 2.f, n));

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
		collisions();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && isRocketMoveableLeft()) {
			model->getRocket()->moveLeft();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && isRocketMoveableRight()) {
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
	return bounds.left + bounds.width - 10 < model->getWidth();
}

void Controller::collisions() {
	ballCollisions((vector<Brick*>*)model->getBrickArray(), true);
	ballCollisions((vector<Wall*>*)walls, false);
	vector<Rocket*>* r = new vector<Rocket*>();
	r->push_back(model->getRocket());
	ballCollisions((vector<Rocket*>*)r, false);
	delete r;
}

template<typename T>
void Controller::ballCollisions(vector<T*>* v, bool isEraseActivated) {
	Ball* ball = model->getBall();

	for (int i = 0; i < v->size(); i++) {
		if (v->at(i)->intersects(ball)) {
			v->at(i)->bounceTheBall(ball);
			if (isEraseActivated) {
				v->erase(v->begin() + i);
			}
		}
	}
}

Controller::~Controller()
{
	delete model;
	delete view;
}