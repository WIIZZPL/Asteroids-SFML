#pragma once

#include "Scene.h"
/// <summary>
/// Klasa sceny menu.
/// </summary>
class MenuScene : public Scene {
	sf::Font font;
	sf::Text gameTitleText;
	sf::Text controlsText;
	sf::Text startText;

	float startTextBlinkerTimer;

public:
	MenuScene();
	~MenuScene();
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