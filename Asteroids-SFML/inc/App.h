#pragma once

#include <SFML/Graphics.hpp>

#include "Scene.h"

/// <summary>
/// Enumerator z dost�pnymi scenami.
/// </summary>
enum class ScenesEnum {
	NONE,
	GAME,
	MENU,
	HIGHSCORES
};

/// <summary>
/// Singleton aplikacji.
/// </summary>
class App {
private:
	static App* instance;
	App();
	~App();

	bool running;
	sf::RenderWindow window;

	Scene* scene;
	ScenesEnum currScene;
	ScenesEnum nextScene;

	void sceneSwitch();
	void processInput();
	void update(float dt);
	void render(float lag);

public:
	/// <summary>
	/// Getter instancji wska�nika na aplikacji.
	/// </summary>
	/// <returns> Wska�nik na instancj�. </returns>
	static App* getInstance();

	/// <summary>
	/// Uruchamia aplikacj�.
	/// </summary>
	void run();
	/// <summary>
	/// Zatrzymuje aplikacj�.
	/// </summary>
	void stop();
	/// <summary>
	/// Ustala nast�pn� scene do przej�cia.
	/// </summary>
	/// <param name="nextScene">Enumerator sceny</param>
	void setNextSecene(ScenesEnum nextScene);
	/// <summary>
	/// Zwraca szeroko�� okna.
	/// </summary>
	/// <returns>Szeroko�� okna.</returns>
	static int getWindowWidth();
	/// <summary>
	/// Zwraca wysoko�� okna.
	/// </summary>
	/// <returns>Wysoko�� okna.</returns>
	static int getWindowHeight();

};