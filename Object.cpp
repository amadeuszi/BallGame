#include "Object.h"



Object::Object(string textureName)
{
	texture = new sf::Texture();
	
	if (!texture->loadFromFile(textureName.c_str())) {
		cout << "couldn't load file" << textureName << endl;
	}
	texture->setSmooth(true);
	sprite = new sf::Sprite(*texture);


	sprite->setPosition(10.f, 10.f);
	circle = new Circle(new sf::Vector2f(0.f, 0.f), 1.f);
}

Object::Object() {
	texture = new sf::Texture();
	sprite = new sf::Sprite();
	circle = new Circle(new sf::Vector2f(0.f, 0.f), 1.f);
}

Circle* Object::getCircleBounds() {
	delete circle;
	
	sf::FloatRect bounds = sprite->getGlobalBounds();
	float x = bounds.left + (bounds.width / 2);
	float y = bounds.top + (bounds.height / 2);
	float r = bounds.width / 2;
	
	circle = new Circle(new sf::Vector2f(x, y), r);
	return circle;
}

sf::FloatRect Object::getGlobalBounds() {
	return sprite->getGlobalBounds();
}

void Object::draw(sf::RenderWindow* window) {
	window->draw(*sprite);
}

Object::~Object()
{
	delete sprite;
	delete texture;
	delete circle;
}
