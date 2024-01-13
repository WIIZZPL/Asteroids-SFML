#pragma once

#include "Scene.h"

#include <vector>

#include "Asteroid.h"
#include "GameScene.h"
#include "Bullet.h"
#include "Barrier.h"
#include "Upgrade.h"
/// <summary>
/// Klasa sceny rozgrywki
/// </summary>
class GameScene : public Scene {
private:
	Player player;
	unsigned int score;
	unsigned short int lives;

	std::vector<Asteroid> asteroids;
	std::vector<Bullet> bullets;
	BulletStats stats;
	std::vector<Upgrade> upgrades;
	Barrier barrier;

	float radiusAvailable;
	float asteroidTimer;
	
	float bulletTimer;
	static char keyboardState[sf::Keyboard::KeyCount];

	void checkColissions();
	void gameEnd();

public:
	GameScene();
	~GameScene();
	/// <summary>
	/// Funkcja do przyjnuj¹ca i obs³uguj¹ca wejœcie.
	/// </summary>
	/// <param name="event">Zdarzenie do przetworzenia</param>
	void processInput(sf::Event& event);
	/// <summary>
	/// Uaktualnia stan sceny.
	/// </summary>
	/// <param name="dt">Delta czasu od ostatniego wywo³ania</param>
	void update(float dt);
	/// <summary>
	/// Od sf::Drawable. Funkcja do rysowania sceny.
	/// </summary>
	/// <param name="target">Cel na co funkcja ma rysowaæ.</param>
	/// <param name="states">Informacje o stanie celu.</param>
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};