#include "Barrier.h"

#include "App.h"

Barrier::Barrier() : active(true) {
	float scaling = 50;
	shape = sf::ConvexShape(6);

	shape.setPoint(0, sf::Vector2f(0, scaling));
	shape.setPoint(1, sf::Vector2f(scaling * 0.86, scaling / 2));
	shape.setPoint(2, sf::Vector2f(scaling * 0.86, -scaling / 2));
	shape.setPoint(3, sf::Vector2f(0, -scaling));
	shape.setPoint(4, sf::Vector2f(-scaling * 0.86, -scaling / 2));
	shape.setPoint(5, sf::Vector2f(-scaling * 0.86, scaling / 2));
	
	shape.setPosition(App::getWindowWidth() / 2, App::getWindowHeight() / 2);
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(sf::Color::Cyan);
	shape.setOutlineThickness(2);
}

Barrier::~Barrier() {

}

void Barrier::update(float dt) {

}

void Barrier::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if(active) target.draw(shape);
}