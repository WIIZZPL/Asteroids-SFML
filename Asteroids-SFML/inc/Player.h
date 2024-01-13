#pragma once

#include <SFML/Graphics.hpp>
/// <summary>
/// Klasa gracza - statku kt�rym gracz steruje
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
	/// <param name="dt">Delta czasu od ostatniego wywo�ania</param>
	void update(float dt);
	/// <summary>
	/// Od sf::Drawable. Funkcja do rysowania gracza.
	/// </summary>
	/// <param name="target">Cel na co funkcja ma rysowa�.</param>
	/// <param name="states">Informacje o stanie celu.</param>
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	/// <summary>
	/// Zwraca referencj� do kszta�u gracza.
	/// </summary>
	/// <returns>Referencja do kszta�u gracza.</returns>
	sf::ConvexShape getShape() { return shape; }

};