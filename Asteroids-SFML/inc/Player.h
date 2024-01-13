#pragma once

#include <SFML/Graphics.hpp>
/// <summary>
/// Klasa gracza - statku którym gracz steruje
/// </summary>
class Player : public sf::Drawable {
private:
	//sf::Vector2i Position;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	//ComplexShape shape;
	sf::ConvexShape shape;

public:
	Player();
	~Player();
	/// <summary>
	/// Uaktualnia stan gracza.
	/// </summary>
	/// <param name="dt">Delta czasu od ostatniego wywo³ania</param>
	void update(float dt);
	/// <summary>
	/// Od sf::Drawable. Funkcja do rysowania gracza.
	/// </summary>
	/// <param name="target">Cel na co funkcja ma rysowaæ.</param>
	/// <param name="states">Informacje o stanie celu.</param>
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	/// <summary>
	/// Zwraca referencjê do kszta³u gracza.
	/// </summary>
	/// <returns>Referencja do kszta³u gracza.</returns>
	sf::ConvexShape getShape() { return shape; }

};