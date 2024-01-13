#pragma once

#include <SFML/Graphics.hpp>
/// <summary>
/// Klasa abstrakcyjna scen gry
/// </summary>
class Scene : public sf::Drawable {
private:

public:
	/// <summary>
	/// Funkcja do przyjnuj¹ca i obs³uguj¹ca wejœcie.
	/// </summary>
	/// <param name="event">Zdarzenie do przetworzenia</param>
	virtual void processInput(sf::Event& event) = 0;
	/// <summary>
	/// Funkcja do uaktualniaj¹ca stanu sceny.
	/// </summary>
	/// <param name="dt">Delta czasu od ostatniego wywo³ania.</param>
	virtual void update(float dt) = 0;
	/// <summary>
	/// Od sf::Drawable. Funkcja do rysowania sceny.
	/// </summary>
	/// <param name="target">Cel na co funkcja ma rysowaæ.</param>
	/// <param name="states">Informacje o stanie celu.</param>
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};