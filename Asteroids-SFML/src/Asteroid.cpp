#include "Asteroid.h"

#define _USE_MATH_DEFINES

#include "App.h"
#include <math.h>

#define MIN_RADIUS 10
#define MIN_SPAWN_RADIUS 50
#define MAX_SPAWN_RADIUS 100
#define MIN_SIDES 8
#define MAX_SIDES 16
#define DEVIATION 0.75f

#define MIN_V 50
#define MAX_V 200
#define MAX_THETA_V 20

#define POINTS_FOR_BREAK 10

Asteroid::Asteroid(float radius) : radius(radius) {
	int noSides = rand() % (MAX_SIDES - MIN_SIDES) + MIN_SIDES;
	shape = sf::ConvexShape(noSides);
	sf::Vector2f ray(0, radius);

	for (int i = 0; i < noSides; i++) {
		sf::Vector2f newPoint(ray);
		newPoint *= (1 + DEVIATION * ((float)rand() / RAND_MAX));
		shape.setPoint(i, newPoint);
		float x = cosf(2 * M_PI / noSides) * ray.x - sinf(2 * M_PI / noSides) * ray.y;
		float y = sinf(2 * M_PI / noSides) * ray.x + cosf(2 * M_PI / noSides) * ray.y;
		ray = sf::Vector2f(x, y);
	}

	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	shape.setOutlineThickness(5);

	velocity = sf::Vector2f();
	velocity.x = rand() % (MAX_V - MIN_V) + MIN_V;
	velocity.y = rand() % (MAX_V - MIN_V) + MIN_V;
	if (rand() % 2) velocity.x *= -1;
	if (rand() % 2) velocity.y *= -1;

	if (rand() % 2) {
		shape.move(rand() % App::getWindowWidth(), 0);
	} else {
		shape.move(0, rand() % App::getWindowWidth());
	}
	shape.move(-shape.getGlobalBounds().getSize()/2.0f);

}

void Asteroid::update(float dt) {
	sf::Vector2f position = shape.getPosition();

	position += velocity * dt;

	sf::FloatRect boundingBox = shape.getGlobalBounds();
	if (boundingBox.getPosition().x > App::getWindowWidth()) position.x -= App::getWindowWidth() + boundingBox.getSize().x;
	if (boundingBox.getPosition().x < -boundingBox.getSize().x) position.x += App::getWindowWidth() + boundingBox.getSize().x;
	if (boundingBox.getPosition().y > App::getWindowHeight()) position.y -= App::getWindowHeight() + boundingBox.getSize().y;
	if (boundingBox.getPosition().y < -boundingBox.getSize().y) position.y += App::getWindowHeight() + boundingBox.getSize().y;
	
	shape.setPosition(position);
}

void Asteroid::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(shape, states);
}

void Asteroid::asteroidBreak(std::vector<Asteroid>& asteroids, unsigned int& score, float& radiusAvaliable) {
	if (this->radius / 2 < MIN_RADIUS) {
		radiusAvaliable += this->radius;
		score += POINTS_FOR_BREAK * this->radius;
	} else {
		asteroids.push_back(Asteroid(this->radius / 2));
		asteroids.back().shape.setPosition(this->shape.getPosition());
		asteroids.push_back(Asteroid(this->radius / 2));
		asteroids.back().shape.setPosition(this->shape.getPosition());
	}
}


Asteroid* AsteroidFactory(float& radiousAvaliable, Player& player) {
	if (radiousAvaliable < MIN_SPAWN_RADIUS) return nullptr;
	float radius = rand() % (MAX_SPAWN_RADIUS - MIN_SPAWN_RADIUS) + MIN_SPAWN_RADIUS;
	return new Asteroid(radius);
}