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
	/// <param name="radius">Promie� asteroidy</param>
	Asteroid(float radius);
	/// <summary>
	/// Uaktualnia stan asteroidy.
	/// </summary>
	/// <param name="dt">Delta czasu od ostatniego wywo�ania</param>
	void update(float dt);
	/// <summary>
	/// Od sf::Drawable. Funkcja do rysowania asteroidy.
	/// </summary>
	/// <param name="target">Cel na co funkcja ma rysowa�.</param>
	/// <param name="states">Informacje o stanie celu.</param>
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	/// <summary>
	/// Zwraca referencj� do kszta�u asteroidy.
	/// </summary>
	/// <returns>Referencja do kszta�u asteroidy.</returns>
	sf::ConvexShape& getShape() { return shape; }
	/// <summary>
	/// Zwraca �rednic� asteroidy.
	/// </summary>
	/// <returns>�rednica asteroidy.</returns>
	float getRadius() { return radius; }
	/// <summary>
	/// Funkcja wykonuj�ca roz�am asteroidy.
	/// </summary>
	/// <description>
	/// Asteroida sprawdza sw�j rozmiar, je�li po�owa jest nie mniejsza ni� dozwolone minimum:
	/// asteroida tworzy dwie nowe o takim w�a�nie rozmiarze.
	/// Je�li nie, dodaje swoj� warto�� punktow� do socre i sw�j promie� do radiusAvaliable
	/// </description>
	/// <param name="asteroids">lista asteroid</param>
	/// <param name="socre">referencja do ilo�ci punkt�w gracza</param>
	/// <param name="radiusAvaliable">referencja do dost�pnej ilo�ci promienia dla asteroid</param>
	void asteroidBreak(std::vector<Asteroid>& asteroids, unsigned int& socre, float& radiusAvaliable);
};

/// <summary>
/// Fabryka asteroid, na podstawie dost�pnego promienia, tworzy asteroid�.
/// </summary>
/// <param name="radiousAvaliable">referencja do ilo�ci dost�pnego promienia dla asteroid</param>
/// <param name="player">referencja do gracza</param>
/// <returns>wska�nik na now� asteroid�, nullptr je�i nie zosta�a utworzona</returns>
Asteroid* AsteroidFactory(float& radiousAvaliable, Player& player);