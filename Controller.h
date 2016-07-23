#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Model.h"
#include "Viewer.h"
#include "Wall.h"
class Controller {
	vector<Wall*>* walls;
	bool isRocketMoveableLeft();
	bool isRocketMoveableRight();
	Model* model;
	Viewer* view;
	void ballWallCollisions();
	void ballRocketCollisions();
	void ballBrickCollisions();
	void ballBrickCollisions2();
	void ballCollisions(vector<Wall*>* v);
public:
	Controller();
	~Controller();
};