#pragma once

#include <SFML/Graphics.hpp>

#include "Scene.h"

/// <summary>
/// Enumerator z dostêpnymi scenami.
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
	/// Getter instancji wskaŸnika na aplikacji.
	/// </summary>
	/// <returns> WskaŸnik na instancjê. </returns>
	static App* getInstance();

	/// <summary>
	/// Uruchamia aplikacjê.
	/// </summary>
	void run();
	/// <summary>
	/// Zatrzymuje aplikacjê.
	/// </summary>
	void stop();
	/// <summary>
	/// Ustala nastêpn¹ scene do przejœcia.
	/// </summary>
	/// <param name="nextScene">Enumerator sceny</param>
	void setNextSecene(ScenesEnum nextScene);
	/// <summary>
	/// Zwraca szerokoœæ okna.
	/// </summary>
	/// <returns>Szerokoœæ okna.</returns>
	static int getWindowWidth();
	/// <summary>
	/// Zwraca wysokoœæ okna.
	/// </summary>
	/// <returns>Wysokoœæ okna.</returns>
	static int getWindowHeight();

};