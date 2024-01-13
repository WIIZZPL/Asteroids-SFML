#include "HighscoreScene.h"

#include <string>
#include <format>
#include "App.h"

HighscoreScene::HighscoreScene() {
	if (!font.loadFromFile("font.ttf")) {
		printf("No font found\n");
		exit(34);
	}

	FILE* plik;
	for (int i = 0; i < 10; i++) scores[i] = 0;
	if (!fopen_s(&plik, "Asteroids-SFML_Scores.bin", "rb")) {
		fread(scores, sizeof(unsigned int), 10, plik);
		fclose(plik);
	}

	std::string textString;
	for (int i = 0; i < 10; i++) textString.append(std::to_string(i+1)+".\t"+std::to_string(scores[i]) + "\n");

	highscoreText.setFont(font);
	highscoreText.setString(textString);
	highscoreText.setCharacterSize(40);
	float highscoreTextXPos = App::getWindowWidth() / 2.0;
	highscoreTextXPos -= highscoreText.getGlobalBounds().width / 2;
	float highscoreTextYPos = highscoreText.getGlobalBounds().height / 8;

	highscoreText.setPosition(highscoreTextXPos, highscoreTextYPos);

	continueText.setFont(font);
	continueText.setString("PRESS ANY KEY TO CONITNUE");
	float continueTextXPos = App::getWindowWidth() / 2.0;
	continueTextXPos -= continueText.getGlobalBounds().width / 2;
	float continueTextYPos = App::getWindowHeight();
	continueTextYPos -= continueText.getGlobalBounds().height * 4;

	continueText.setPosition(continueTextXPos, continueTextYPos);
}

HighscoreScene::~HighscoreScene() {}

void HighscoreScene::processInput(sf::Event& event) {
	if (event.type == sf::Event::KeyPressed) App::getInstance()->setNextSecene(ScenesEnum::MENU);
}

void HighscoreScene::update(float dt) {}

void HighscoreScene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(highscoreText);
	target.draw(continueText);
}
