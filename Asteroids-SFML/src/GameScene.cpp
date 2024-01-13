#include "GameScene.h"

#include <SFML/Graphics.hpp>

#include "App.h"

#include "Player.h"
#include "Asteroid.h"

#define STARTING_LIVES 3
#define MAX_TOTAL_RADIUS 1000
#define NEW_ASTEROID_TIMER 5
#define MIN_NO_ASTEROIDS 1
#define START_NO_ASTEROIDS 5
#define UPGRADE_SPAWN_CHANCE 0.2f

char GameScene::keyboardState[sf::Keyboard::KeyCount];

bool shapesCollide(const sf::ConvexShape& shapeA, const  sf::ConvexShape& shapeB);
bool pointInShape(const sf::ConvexShape& shape, const  sf::Vector2f point);

GameScene::GameScene() {
	lives = STARTING_LIVES;
	score = 0;

	bulletTimer = 0;
	stats.bulletFireSpeed = 0.2;

	radiusAvailable = MAX_TOTAL_RADIUS;
	asteroidTimer = 0;
	while (asteroids.size() < START_NO_ASTEROIDS) {
		Asteroid* newAsteroid = AsteroidFactory(radiusAvailable, player);
		if (newAsteroid == nullptr) break;
		asteroids.push_back(*newAsteroid);
	}
	for (int i = 0; i < sf::Keyboard::KeyCount; i++) keyboardState[i] = 0;
}

GameScene::~GameScene() {

}

void GameScene::processInput(sf::Event& event) {
	if (event.type == sf::Event::KeyPressed) keyboardState[event.key.code] = 3;
	else if (event.type == sf::Event::KeyReleased) keyboardState[event.key.code] = keyboardState[event.key.code] ^ 1;
}

void GameScene::update(float dt) {
	player.update(dt);
	for (auto& asteroid : asteroids) asteroid.update(dt);
	for (auto& bullet : bullets) bullet.update(dt);
	for (auto& upgrade : upgrades) upgrade.update(dt);

	bulletTimer += dt;
	asteroidTimer += dt;

	if (keyboardState[sf::Keyboard::Space]) {
		keyboardState[sf::Keyboard::Space] = keyboardState[sf::Keyboard::Space] ^ 2;
   		if (stats.bulletFireSpeed < bulletTimer) {
			bullets.push_back(Bullet(player.getShape().getPosition(), player.getShape().getRotation()));
			bulletTimer = 0;
		}
	}
	if (keyboardState[sf::Keyboard::Escape]) {
		App::getInstance()->setNextSecene(ScenesEnum::MENU);
		keyboardState[sf::Keyboard::Escape] = keyboardState[sf::Keyboard::Escape] ^ 2;
	}

	if (asteroidTimer > NEW_ASTEROID_TIMER || asteroids.size() == 0) {
		Asteroid* newAsteroid = AsteroidFactory(radiusAvailable, player);
		if (newAsteroid != nullptr)
			asteroids.push_back(*newAsteroid);
		asteroidTimer = 0;
	}

	for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end();) {
		if (it->shouldDelete()) it = bullets.erase(it);
		else it++;
	}

	for (std::vector<Upgrade>::iterator it = upgrades.begin(); it != upgrades.end();) {
		if (it->shouldDelete()) it = upgrades.erase(it);
		else it++;
	}

	checkColissions();

	if (lives == 0) gameEnd();
}

void GameScene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(player);
	for (auto& asteroid : asteroids) target.draw(asteroid);
	for (auto& bullet : bullets) target.draw(bullet);
	target.draw(barrier);
	for (auto& upgrade : upgrades) target.draw(upgrade);
}

void GameScene::checkColissions() {
	if (barrier.isActive()) {
		std::vector<Bullet>::iterator bulletIterator = bullets.begin();
		while (bulletIterator != bullets.end()) {
			if (shapesCollide(barrier.getShape(), bulletIterator->getShape())) {
				barrier.setActive(false);
				break;
			}
			bulletIterator++;
		}

		if (!shapesCollide(player.getShape(), barrier.getShape()))
			barrier.setActive(false);
	}
	
	for (int i = 0; i < asteroids.size(); i++) {
		if (shapesCollide(asteroids[i].getShape(), player.getShape())) {
			lives--;

			player = Player();
			barrier.setActive(true);
		}

		if (barrier.isActive() && shapesCollide(asteroids[i].getShape(), barrier.getShape()))
			asteroids[i] = Asteroid(asteroids[i].getRadius());

			for (int j = 0; j < bullets.size(); j++) {
				if (shapesCollide(asteroids[i].getShape(), bullets[j].getShape())) {
					if ((float)rand() / RAND_MAX < UPGRADE_SPAWN_CHANCE)
						upgrades.push_back(Upgrade(asteroids[i].getShape().getPosition()));

        			asteroids[i].asteroidBreak(asteroids, score, radiusAvailable);
					asteroids.erase(asteroids.begin() + i);
					bullets.erase(bullets.begin() + j);
					i--;
					j--;

					break;
				}
			}
	}

	for (int i = 0; i < upgrades.size(); i++) {
		if (shapesCollide(upgrades[i].getShape(), player.getShape()))
			upgrades[i].apply(stats);
	}
}

void GameScene::gameEnd() {
	FILE* plik;
	unsigned int scores[10];
	for (int i = 0; i < 10; i++) scores[i] = 0;
	if (!fopen_s(&plik, "Asteroids-SFML_Scores.bin", "rb+")) {
		fread(scores, sizeof(unsigned int), 10, plik);
		int i = 0;
		while (scores[i] > score && i < 10) i++;
		for (int j = 9; j > i; j--) scores[j] = scores[j - 1];
		scores[i] = score;
	} else {
		fopen_s(&plik, "Asteroids-SFML_Scores.bin", "wb");
		scores[0] = score;
	}
	fflush(plik);
	rewind(plik);
	fwrite(scores, sizeof(unsigned int), 10, plik);
	fclose(plik);

	App::getInstance()->setNextSecene(ScenesEnum::HIGHSCORES);
}

bool shapesCollide(const sf::ConvexShape& shapeA, const sf::ConvexShape& shapeB) {
	for (int i = 0; i < shapeA.getPointCount(); i++) {
		if (pointInShape(shapeB, shapeA.getPoint(i)+shapeA.getPosition()))
			return true;
	}

	for (int i = 0; i < shapeB.getPointCount(); i++) {
		if (pointInShape(shapeA, shapeB.getPoint(i)+shapeB.getPosition()))
			return true;
	}

	return false;
}

bool pointInShape(const sf::ConvexShape& shape, const sf::Vector2f point) {
	int numberOfIntersections = 0;

	for (int i = 0; i < shape.getPointCount(); i++) {
		sf::Vector2f shapePointA = shape.getPoint(i)+shape.getPosition();
		sf::Vector2f shapePointB = shape.getPoint((i+1) % shape.getPointCount())+shape.getPosition();

		//Outside of y range
		if (point.y < fminf(shapePointA.y, shapePointB.y) || point.y > fmaxf(shapePointA.y, shapePointB.y)) continue;

		float a = (shapePointA.y - shapePointB.y) / (shapePointA.x - shapePointB.x);
		float b = (-a * shapePointA.x + shapePointA.y);
		float x = (point.y - b) / a;
		
		if (point.x <= x) {
			numberOfIntersections++;
		}
	}

	return numberOfIntersections % 2;
}