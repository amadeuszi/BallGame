#pragma once
#include "Model.h"
class Viewer
{
	Model* model;
public:
	Viewer(Model* m);
	void displayAll();
	~Viewer();
};

