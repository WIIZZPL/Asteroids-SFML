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

GameScene::GameScene() {

	player = new Player();
	lives = STARTING_LIVES;

	radiusAvailable = MAX_TOTAL_RADIUS;
	asteroidTimer = 0;
	while (asteroids.size() < START_NO_ASTEROIDS) {
		Asteroid* newAsteroid = new Asteroid();
		if (newAsteroid != nullptr) asteroids.push_back(newAsteroid);
	}
}

GameScene::~GameScene() {
	delete player;
	for (auto& asteroid : asteroids) delete asteroid;
}

void GameScene::processInput(sf::Event& event) {
	
}

void GameScene::update(float dt) {
	player->update(dt);
	for (auto& asteroid : asteroids) asteroid->update(dt);
}

void GameScene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(*player);
	for (auto& asteroid : asteroids) target.draw(*asteroid);
}