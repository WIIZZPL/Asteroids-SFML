#include "App.h"

#include "Scene.h"
#include "GameScene.h"
#include "MenuScene.h"
#include "HighscoreScene.h"

#define SPT (1/120.0f)

App* App::instance;

App::App() : window(sf::VideoMode(1280, 720), "Asteroids-SFML") {
	srand(time(nullptr));
	running = false;
	window.setFramerateLimit(120);
	
	setNextSecene(ScenesEnum::MENU);
}

App::~App() {
	window.close();
}

void App::sceneSwitch() {
	if (currScene == nextScene) return;

	delete scene;

	switch (nextScene) {
	case ScenesEnum::GAME:
		scene = new GameScene();
		break;
	case ScenesEnum::MENU:
		scene = new MenuScene();
		break;
	case ScenesEnum::HIGHSCORES:
		scene = new HighscoreScene();
		break;
	default:
		exit(555);
		break;
	}

	currScene = nextScene;
}

void App::processInput() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) stop();

		scene->processInput(event);
	}
}

void App::update(float dt) {
	scene->update(dt);
}

void App::render(float lag) {
	window.clear();

	window.draw(*scene);
	
	window.display();
}

App* App::getInstance() {
	if (instance == nullptr) instance = new App();
	return instance;
}

void App::run() {

	running = true;

	sf::Clock clock;

	float accTime = 0.0f;

	while (running) {
		float deltaTime = clock.getElapsedTime().asSeconds();
		accTime += deltaTime;
		clock.restart();

		sceneSwitch();

		processInput();

		while (accTime >= SPT) {
			update(SPT);
			accTime -= SPT;
		}

		render(accTime);
	}

}

void App::stop() {
	running = false;
}

void App::setNextSecene(ScenesEnum nextScene) {
	this->nextScene = nextScene;
}

int App::getWindowWidth() {
	return getInstance()->window.getSize().x;
}

int App::getWindowHeight() {
	return getInstance()->window.getSize().y;
}