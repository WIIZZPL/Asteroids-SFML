#pragma once

#include <SFML/Graphics.hpp>
/// <summary>
/// Klasa pocisku.
/// </summary>
class Bullet : public sf::Drawable {
	sf::Vector2f velocity;
	sf::ConvexShape shape;

public:
	/// <summary>
	/// Konstruktor pocisku przujmuj�cy pozycje, i kont wystrza�u.
	/// </summary>
	/// <param name="position">Pozycj� gdzie pocisk wystrzelono</param>
	/// <param name="angle">K�t gdzie pocisk wystrzelono</param>
	Bullet(sf::Vector2f position, float angle);
	/// <summary>
	/// Uaktualnia stan pocisku.
	/// </summary>
	/// <param name="dt">Delta czasu od ostatniego wywo�ania</param>
	void update(float dt);
	/// <summary>
	/// Od sf::Drawable. Funkcja do rysowania pocisku.
	/// </summary>
	/// <param name="target">Cel na co funkcja ma rysowa�.</param>
	/// <param name="states">Informacje o stanie celu.</param>
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	/// <summary>
	/// Funkcja sprawdzaj�ca czy pocisk powinien zosta� usuni�ty - jest nieprzydatny.
	/// </summary>
	/// <returns>Czy pocisk nale�y usun��</returns>
	bool shouldDelete();
	/// <summary>
	/// Zwraca referencj� do kszta�u pocisku.
	/// </summary>
	/// <returns>Referencja do kszta�u pocisku.</returns>
	sf::ConvexShape getShape() { return shape; }

};

