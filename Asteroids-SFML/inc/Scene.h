#pragma once

#include <SFML/Graphics.hpp>

class Scene : public sf::Drawable {
private:

public:
	virtual void processInput(sf::Event& event);
	virtual void update(float dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};