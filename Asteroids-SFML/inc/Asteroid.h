#pragma once

#include "Player.h"
#include <SFML/Graphics.hpp>

/// <summary>
/// Klasa asteroid
/// </summary>
class Asteroid : public sf::Drawable {
private:
	//sf::Vector2i Position;
	sf::Vector2f velocity;
	sf::ConvexShape shape;
	float radius;

public:
	/// <summary>
	/// Konstruktor asteroidy wedle promienia wymaganego.
	/// </summary>
	/// <param name="radius">Promieñ asteroidy</param>
	Asteroid(float radius);
	/// <summary>
	/// Uaktualnia stan asteroidy.
	/// </summary>
	/// <param name="dt">Delta czasu od ostatniego wywo³ania</param>
	void update(float dt);
	/// <summary>
	/// Od sf::Drawable. Funkcja do rysowania asteroidy.
	/// </summary>
	/// <param name="target">Cel na co funkcja ma rysowaæ.</param>
	/// <param name="states">Informacje o stanie celu.</param>
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	/// <summary>
	/// Zwraca referencjê do kszta³u asteroidy.
	/// </summary>
	/// <returns>Referencja do kszta³u asteroidy.</returns>
	sf::ConvexShape& getShape() { return shape; }
	/// <summary>
	/// Zwraca œrednicê asteroidy.
	/// </summary>
	/// <returns>Œrednica asteroidy.</returns>
	float getRadius() { return radius; }
	/// <summary>
	/// Funkcja wykonuj¹ca roz³am asteroidy.
	/// </summary>
	/// <description>
	/// Asteroida sprawdza swój rozmiar, jeœli po³owa jest nie mniejsza ni¿ dozwolone minimum:
	/// asteroida tworzy dwie nowe o takim w³aœnie rozmiarze.
	/// Jeœli nie, dodaje swoj¹ wartoœæ punktow¹ do socre i swój promieñ do radiusAvaliable
	/// </description>
	/// <param name="asteroids">lista asteroid</param>
	/// <param name="socre">referencja do iloœci punktów gracza</param>
	/// <param name="radiusAvaliable">referencja do dostêpnej iloœci promienia dla asteroid</param>
	void asteroidBreak(std::vector<Asteroid>& asteroids, unsigned int& socre, float& radiusAvaliable);
};

/// <summary>
/// Fabryka asteroid, na podstawie dostêpnego promienia, tworzy asteroidê.
/// </summary>
/// <param name="radiousAvaliable">referencja do iloœci dostêpnego promienia dla asteroid</param>
/// <param name="player">referencja do gracza</param>
/// <returns>wskaŸnik na now¹ asteroidê, nullptr jeœi nie zosta³a utworzona</returns>
Asteroid* AsteroidFactory(float& radiousAvaliable, Player& player);