#include "Bullet.h"

#include "App.h"

#define BULLET_SIZE 5
#define BULLET_SPEED 1000

Bullet::Bullet(sf::Vector2f position, float angle) {
	shape.setPointCount(4);
	shape.setPoint(0, sf::Vector2f(0, BULLET_SIZE));
	shape.setPoint(1, sf::Vector2f(-BULLET_SIZE, 0));
	shape.setPoint(2, sf::Vector2f(0, -BULLET_SIZE));
	shape.setPoint(3, sf::Vector2f(BULLET_SIZE, 0));
	shape.setPosition(position);

	shape.setFillColor(sf::Color::Red);

	angle -= 90;
	velocity = sf::Vector2f(cosf(angle/360*2*3.14) * BULLET_SPEED, sinf(angle/360*2*3.14) * BULLET_SPEED);
}

void Bullet::update(float dt) {
	shape.move(velocity * dt);
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(shape);
}

bool Bullet::shouldDelete() {
	return !shape.getGlobalBounds().intersects(sf::FloatRect(0, 0, App::getWindowWidth(), App::getWindowHeight()));
}
