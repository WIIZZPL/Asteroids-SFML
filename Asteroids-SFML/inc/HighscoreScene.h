#pragma once

#include "Scene.h"
/// <summary>
/// Klasa sceny z rankingiem graczy.
/// </summary>
class HighscoreScene : public Scene {
	unsigned int scores[10];
	sf::Font font;
	sf::Text highscoreText;
	sf::Text continueText;

public:
	HighscoreScene();
	~HighscoreScene();
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
