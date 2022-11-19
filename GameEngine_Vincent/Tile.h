#pragma once
#include "SFML/system.hpp"
#include "SFML/window.hpp"
#include "SFML/graphics.hpp"
#include <iostream>
#include <sstream>

class Tile
{
public:
	bool bColliding;
	sf::RectangleShape shape;

	Tile() = default;
	Tile(float xPos, float yPos, float gridSizef, bool bColliding);
	~Tile() = default;

	void Render(sf::RenderTarget& target);
	const bool& GetCollision() const;
	const sf::Vector2f& GetPosition() const;
	std::string toString();

};

