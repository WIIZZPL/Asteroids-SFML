#pragma once

#include <SFML/Graphics.hpp>

/// <summary>
/// Struktura statystyk pocisk�w.
/// </summary>
typedef struct BulletStats {
	float bulletFireSpeed;
} BulletStats;

/// <summary>
/// Enumarator typ�w ulepsze� pocisk�w.
/// </summary>
enum UpgradeTypes {
	FASTER_FIRE,
	SLOWER_FIRE,
	UPGRADES_NUMBER
};

/// <summary>
/// Klasa reprezentuj�ca ulepszenie pocisk�w gracza.
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
	/// <param name="dt">Delta czasu od ostatniego wywo�ania</param>
	void update(float dt);
	/// <summary>
	/// Od sf::Drawable. Funkcja do rysowania ulepszenia.
	/// </summary>
	/// <param name="target">Cel na co funkcja ma rysowa�.</param>
	/// <param name="states">Informacje o stanie celu.</param>
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	/// <summary>
	/// Zwraca referencj� do kszta�u ulepszenia.
	/// </summary>
	/// <returns>Referencja do kszta�u ulepszenia.</returns>
	sf::ConvexShape& getShape() { return shape; }
	/// <summary>
	/// Zwraca informacje czy powinna zosta� usuni�ta.
	/// </summary>
	/// <returns>czy instancja powinna zosta� usuni�ta</returns>
	bool shouldDelete() { return timer < 0; }
	/// <summary>
	/// Nak�ada efekt ulepszenia na statystyki pocisku
	/// </summary>
	/// <param name="stats">Referencja do statystyk pocisku</param>
	void apply(BulletStats& stats);
};