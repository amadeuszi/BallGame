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
	void collisions();
	template<typename T>
	void ballCollisions(vector<T*>* v, bool isEraseActivated);
public:
	Controller();
	~Controller();
};