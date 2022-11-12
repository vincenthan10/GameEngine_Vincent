#pragma once
#include "SFML/Graphics.hpp"

class Button
{
private:
	sf::Color defaultColor, highlightedColor;

public:
	sf::RectangleShape buttonBG;
	sf::Text buttonText;
	bool bPressed, bClicked, bReleased, bHighlighted;

	Button() = default;
	Button(sf::Vector2f size, sf::Color color, std::string text);
	~Button() = default;

	bool isHighlighted();
	void HighlightedButton(sf::RenderWindow* window);
	void Update(sf::Event event, float deltaTime);
	void Render(sf::RenderWindow* window, float deltaTime);
	void CheckPressed(sf::Event event);

};

