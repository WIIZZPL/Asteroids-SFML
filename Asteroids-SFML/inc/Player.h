#pragma once

#include <SFML/Graphics.hpp>

class Player : public sf::Drawable {
private:
	//sf::Vector2i Position;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::RectangleShape shape;

public:
	void update(float dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};