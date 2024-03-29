#pragma once

#include <SFML/Graphics.hpp>
/// <summary>
/// Klasa abstrakcyjna scen gry
/// </summary>
class Scene : public sf::Drawable {
private:

public:
	/// <summary>
	/// Funkcja do przyjnująca i obsługująca wejście.
	/// </summary>
	/// <param name="event">Zdarzenie do przetworzenia</param>
	virtual void processInput(sf::Event& event) = 0;
	/// <summary>
	/// Funkcja do uaktualniająca stanu sceny.
	/// </summary>
	/// <param name="dt">Delta czasu od ostatniego wywołania.</param>
	virtual void update(float dt) = 0;
	/// <summary>
	/// Od sf::Drawable. Funkcja do rysowania sceny.
	/// </summary>
	/// <param name="target">Cel na co funkcja ma rysować.</param>
	/// <param name="states">Informacje o stanie celu.</param>
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};