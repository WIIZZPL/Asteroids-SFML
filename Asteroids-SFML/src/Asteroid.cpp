#include "Asteroid.h"

Asteroid::Asteroid() : velocity(1, 1), acceleration(0, 0), shape(sf::Vector2f(10, 10)) {

}

void Asteroid::update(float dt) {
	sf::Vector2f position = shape.getPosition();

	position += velocity * dt;
	velocity += acceleration * dt;
	
	shape.setPosition(position);
}

void Asteroid::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(shape, states);
}