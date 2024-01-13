#include "MenuScene.h"

#include "App.h"

#define BLINKING_INTERVAL 0.75

MenuScene::MenuScene() : startTextBlinkerTimer(0) {
	if (!font.loadFromFile("font.ttf")) {
		printf("No font found\n");
		exit(34);
	}

	gameTitleText.setFont(font);
	controlsText.setFont(font);
	startText.setFont(font);

	gameTitleText.setString("ASTEROIDS");
	gameTitleText.setStyle(sf::Text::Bold);
	gameTitleText.setCharacterSize(80);
	gameTitleText.setLetterSpacing(5);
	gameTitleText.setPosition((App::getWindowWidth()-gameTitleText.getGlobalBounds().width) / 2, 100);

	startText.setString("- - - Press fire to start - - -");
	startText.setPosition((App::getWindowWidth() - startText.getGlobalBounds().width) / 2, 350);

	controlsText.setString("WSAD - Move\tSpace - Fire");
	controlsText.setCharacterSize(20);
	controlsText.setPosition((App::getWindowWidth() - controlsText.getGlobalBounds().width) / 2, 600);
}

MenuScene::~MenuScene() {

}

void MenuScene::processInput(sf::Event& event) {
	if (event.type == sf::Event::KeyPressed)
		if (event.key.code == sf::Keyboard::Escape)
			App::getInstance()->stop();
		if (event.key.code == sf::Keyboard::Space)
			App::getInstance()->setNextSecene(ScenesEnum::GAME);
}

void MenuScene::update(float dt) {
	startTextBlinkerTimer += dt;
	if (BLINKING_INTERVAL < startTextBlinkerTimer) {
		startTextBlinkerTimer -= BLINKING_INTERVAL;

		if (startText.getFillColor() == sf::Color::White) startText.setFillColor(sf::Color::Transparent);
		else startText.setFillColor(sf::Color::White);
	}
}

void MenuScene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(gameTitleText);
	target.draw(controlsText);
	target.draw(startText);
}
