#pragma once

#include <SFML/Graphics.hpp>

#include "Scene.h"
#include "GameScene.h"

enum class ScenesEnum;

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
	static App* getInstance();

	void run();
	void stop();

	void setNextSecene(ScenesEnum nextScene);

	static int getWindowWidth();
	static int getWindowHeight();

};