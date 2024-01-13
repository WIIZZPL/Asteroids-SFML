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
	/// Konstruktor pocisku przujmuj¹cy pozycje, i kont wystrza³u.
	/// </summary>
	/// <param name="position">Pozycj¹ gdzie pocisk wystrzelono</param>
	/// <param name="angle">K¹t gdzie pocisk wystrzelono</param>
	Bullet(sf::Vector2f position, float angle);
	/// <summary>
	/// Uaktualnia stan pocisku.
	/// </summary>
	/// <param name="dt">Delta czasu od ostatniego wywo³ania</param>
	void update(float dt);
	/// <summary>
	/// Od sf::Drawable. Funkcja do rysowania pocisku.
	/// </summary>
	/// <param name="target">Cel na co funkcja ma rysowaæ.</param>
	/// <param name="states">Informacje o stanie celu.</param>
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	/// <summary>
	/// Funkcja sprawdzaj¹ca czy pocisk powinien zostaæ usuniêty - jest nieprzydatny.
	/// </summary>
	/// <returns>Czy pocisk nale¿y usun¹æ</returns>
	bool shouldDelete();
	/// <summary>
	/// Zwraca referencjê do kszta³u pocisku.
	/// </summary>
	/// <returns>Referencja do kszta³u pocisku.</returns>
	sf::ConvexShape getShape() { return shape; }

};

