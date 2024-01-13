#pragma once

#include <SFML/Graphics.hpp>

/// <summary>
/// Struktura statystyk pocisków.
/// </summary>
typedef struct BulletStats {
	float bulletFireSpeed;
} BulletStats;

/// <summary>
/// Enumarator typów ulepszeñ pocisków.
/// </summary>
enum UpgradeTypes {
	FASTER_FIRE,
	SLOWER_FIRE,
	UPGRADES_NUMBER
};

/// <summary>
/// Klasa reprezentuj¹ca ulepszenie pocisków gracza.
/// </summary>
class Upgrade : public sf::Drawable {
private:
	sf::Vector2f velocity;
	sf::ConvexShape shape;
	UpgradeTypes type;
	float timer;

public:
	Upgrade(sf::Vector2f position);
	/// <summary>
	/// Uaktualnia stan ulepszenia.
	/// </summary>
	/// <param name="dt">Delta czasu od ostatniego wywo³ania</param>
	void update(float dt);
	/// <summary>
	/// Od sf::Drawable. Funkcja do rysowania ulepszenia.
	/// </summary>
	/// <param name="target">Cel na co funkcja ma rysowaæ.</param>
	/// <param name="states">Informacje o stanie celu.</param>
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	/// <summary>
	/// Zwraca referencjê do kszta³u ulepszenia.
	/// </summary>
	/// <returns>Referencja do kszta³u ulepszenia.</returns>
	sf::ConvexShape& getShape() { return shape; }
	/// <summary>
	/// Zwraca informacje czy powinna zostaæ usuniêta.
	/// </summary>
	/// <returns>czy instancja powinna zostaæ usuniêta</returns>
	bool shouldDelete() { return timer < 0; }
	/// <summary>
	/// Nak³ada efekt ulepszenia na statystyki pocisku
	/// </summary>
	/// <param name="stats">Referencja do statystyk pocisku</param>
	void apply(BulletStats& stats);
};