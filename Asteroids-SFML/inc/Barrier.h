#pragma once

#include <SFML/Graphics.hpp>
/// <summary>
/// Klasa bariery os³aniaj¹cej gracza na pocz¹tku gry.
/// </summary>
class Barrier : public sf::Drawable {
	sf::ConvexShape shape;
	bool active;
public:
	Barrier();
	~Barrier();
	/// <summary>
	/// Uaktualnia stan bariery.
	/// </summary>
	/// <param name="dt">Delta czasu od ostatniego wywo³ania</param>
	void update(float dt);
	/// <summary>
	/// Od sf::Drawable. Funkcja do rysowania sceny.
	/// </summary>
	/// <param name="target">Cel na co funkcja ma rysowaæ.</param>
	/// <param name="states">Informacje o stanie celu.</param>
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	/// <summary>
	/// Zwraca referencjê do kszta³u bariery.
	/// </summary>
	/// <returns>Referencja do kszta³u bariery.</returns>
	sf::ConvexShape getShape() { return shape; }
	/// <summary>
	/// Zwraca stan aktywnoœci bariery.
	/// </summary>
	/// <returns>stan aktywnoœci</returns>
	bool isActive() { return active; }
	/// <summary>
	/// Ustawia aktywnoœæ bariery.
	/// </summary>
	/// <param name="active">Porz¹dany stan bariery.</param>
	void setActive(bool active) { this->active = active; }
};