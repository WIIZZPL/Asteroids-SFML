#include "Player.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include "App.h"

#define FRICTION 0.98f

Player::Player() {
	float scaling = 25;
	/*
	sf::Vector2f* points = new sf::Vector2f[4];

	points[0] = sf::Vector2f(0, -scaling);
	points[1] = sf::Vector2f(-scaling, scaling);
	points[2] = sf::Vector2f(0, scaling/2);
	points[3] = sf::Vector2f(scaling, scaling);
	
	shape = ComplexShape(points, 4);
	*/

	shape.setPointCount(4);
	shape.setPoint(0, sf::Vector2f(0, -scaling));
	shape.setPoint(1, sf::Vector2f(scaling, scaling));
	shape.setPoint(2, sf::Vector2f(0, scaling/2));
	shape.setPoint(3, sf::Vector2f(-scaling, scaling));

	shape.setPosition(App::getWindowWidth() / 2, App::getWindowHeight() / 2);
}

Player::~Player() {}

void Player::update(float dt) {
	sf::Vector2f position = shape.getPosition();

	acceleration *= 0.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) acceleration.y = -1500;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) acceleration.y = 1500;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) acceleration.x = -1500;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) acceleration.x = 1500;

	position += velocity * dt;
	velocity += acceleration * dt;
	velocity *= FRICTION;

	sf::FloatRect boundingBox = shape.getGlobalBounds();
	if (boundingBox.getPosition().x > App::getWindowWidth()) position.x -= App::getWindowWidth() + boundingBox.getSize().x;
	if (boundingBox.getPosition().x < -boundingBox.getSize().x) position.x += App::getWindowWidth() + boundingBox.getSize().x;
	if (boundingBox.getPosition().y > App::getWindowHeight()) position.y -= App::getWindowHeight() + boundingBox.getSize().y;
	if (boundingBox.getPosition().y < -boundingBox.getSize().y) position.y += App::getWindowHeight() + boundingBox.getSize().y;

	shape.setPosition(position);
	
	float angleRads = atan2f(velocity.y, velocity.x);
	shape.setRotation(angleRads * 360 / 2 / M_PI + 90);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(shape);
}
