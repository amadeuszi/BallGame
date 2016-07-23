#include "Viewer.h"



Viewer::Viewer(Model* m)
{
	model = m;
}

void Viewer::displayAll() {
	sf::RenderWindow* window = model->getWindow();
	vector<Draw*>* objectsToDraw = model->getObjectsToDraw();
	for (int i = 0; i < objectsToDraw->size(); i++) {
		objectsToDraw->at(i)->draw(window);
	}
	vector<Brick*>* brickArray = model->getBrickArray();
	for (int i = 0; i < brickArray->size(); i++) {
		brickArray->at(i)->draw(window);
	}
}

Viewer::~Viewer()
{
}
