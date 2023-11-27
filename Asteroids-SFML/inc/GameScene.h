#pragma once

#include "Scene.h"

#include <vector>

class Player;
class Asteroid;

class GameScene : public Scene {
private:
	Player* player;
	unsigned short int lives;

	std::vector<Asteroid*> asteroids;
	float radiusAvailable;
	float asteroidTimer;

public:
	GameScene();
	~GameScene();
	void processInput(sf::Event& event);
	void update(float dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};