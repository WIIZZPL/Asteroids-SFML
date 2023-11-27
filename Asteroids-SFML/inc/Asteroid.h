#pragma once

#include <SFML/Graphics.hpp>

class Asteroid : public sf::Drawable {
private:
	//sf::Vector2i Position;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::RectangleShape shape;

public:
	Asteroid();
	void update(float dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

