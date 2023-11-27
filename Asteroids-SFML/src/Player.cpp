#include "Player.h"

void Player::update(float dt) {
	sf::Vector2f position = shape.getPosition();

	position += velocity * dt;
	velocity += acceleration * dt;

	shape.setPosition(position);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(shape);
}
