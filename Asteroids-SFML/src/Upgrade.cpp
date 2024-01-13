#include "Upgrade.h"
#define _USE_MATH_DEFINES
#include "math.h"

#include "App.h"

#define STAR_OUTER_RADIUS 30
#define STAR_INNER_RADIUS 15
#define STAR_POINTS_NUM 5
#define SPEED 10.0f
#define DIRECTION_INNACURACY 100
#define TIME_TO_LIVE 5

Upgrade::Upgrade(sf::Vector2f position) {
	type = static_cast<UpgradeTypes>(rand() % UpgradeTypes::UPGRADES_NUMBER);

	shape.setPointCount(STAR_POINTS_NUM * 2);
	shape.setPosition(position);

	float angle = 0;
	for (int i = 0; i < STAR_POINTS_NUM * 2; i += 2) {
		shape.setPoint(i, sf::Vector2f(STAR_OUTER_RADIUS*cosf(angle), STAR_OUTER_RADIUS*sinf(angle)));
		angle += 2*M_PI / (STAR_POINTS_NUM * 2);
		shape.setPoint(i+1, sf::Vector2f(STAR_INNER_RADIUS * cosf(angle), STAR_INNER_RADIUS * sinf(angle)));
		angle += 2*M_PI / (STAR_POINTS_NUM * 2);
	}

	switch (type) {
	case FASTER_FIRE:
		shape.setFillColor(sf::Color::Green);
		break;
	case SLOWER_FIRE:
		shape.setFillColor(sf::Color::Red);
		break;
	}

	angle = ((float)rand()) / RAND_MAX * 2 * M_PI;
	float speed = ((float)rand()) / RAND_MAX * SPEED;
	velocity = sf::Vector2f(speed*cosf(angle), speed*sinf(angle));

	timer = TIME_TO_LIVE;
}

void Upgrade::update(float dt) {
	shape.move(velocity * dt);
	timer -= dt;
	sf::Color color = shape.getFillColor();
	color.a = timer / TIME_TO_LIVE * 255;
	shape.setFillColor(color);
}

void Upgrade::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(shape);
}

void Upgrade::apply(BulletStats& stats) {
	switch (type) {
	case FASTER_FIRE:
		stats.bulletFireSpeed *= 0.8;
		break;
	case SLOWER_FIRE:
		stats.bulletFireSpeed *= 1.2;
		break;
	}
	timer = 0;
}
