#pragma once

#include <SFML/Graphics.hpp>

#include "Scene.h"

class Player;
class Asteroid;

class GameScene : public Scene {
private:
	Player* player;

	std::vector<Asteroid*> asteroids;
	float radiusAvailable;
	float asteroidTimer;

	void asteroidsSpawn(double dt);

public:
	GameScene();
	~GameScene();
	void processInput(sf::Event event);
	void update(float dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};