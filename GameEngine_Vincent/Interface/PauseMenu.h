#pragma once
#include "GUI_Components/ButtonMap.h"
#include "States.h"

class PauseMenu
{
public:
	PauseMenu() = default;
	PauseMenu(sf::RenderWindow* window);
	~PauseMenu() = default;

	void Update(sf::Event event, float deltaTime, sf::RenderWindow* window);
	void Render(sf::RenderWindow* window, float deltaTime, sf::Vector2f resumePosition);

private:
	void InitButtons();
	void Quit(sf::RenderWindow* window);

};

