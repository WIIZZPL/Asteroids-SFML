#pragma once

#include <SFML/Graphics.hpp>
/// <summary>
/// Klasa bariery os�aniaj�cej gracza na pocz�tku gry.
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
	/// <param name="dt">Delta czasu od ostatniego wywo�ania</param>
	void update(float dt);
	/// <summary>
	/// Od sf::Drawable. Funkcja do rysowania sceny.
	/// </summary>
	/// <param name="target">Cel na co funkcja ma rysowa�.</param>
	/// <param name="states">Informacje o stanie celu.</param>
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	/// <summary>
	/// Zwraca referencj� do kszta�u bariery.
	/// </summary>
	/// <returns>Referencja do kszta�u bariery.</returns>
	sf::ConvexShape getShape() { return shape; }
	/// <summary>
	/// Zwraca stan aktywno�ci bariery.
	/// </summary>
	/// <returns>stan aktywno�ci</returns>
	bool isActive() { return active; }
	/// <summary>
	/// Ustawia aktywno�� bariery.
	/// </summary>
	/// <param name="active">Porz�dany stan bariery.</param>
	void setActive(bool active) { this->active = active; }
};