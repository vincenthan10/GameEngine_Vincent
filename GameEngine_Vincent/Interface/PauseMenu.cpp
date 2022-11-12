#include "PauseMenu.h"

PauseMenu::PauseMenu(sf::RenderWindow* window)
{
	States::SetPausedState(false);
	this->InitButtons();
}

void PauseMenu::Update(sf::Event event, float deltaTime, sf::RenderWindow* window)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			States::SetPausedState(!States::GetPausedState());
		}
	}

	if (States::GetPausedState())
	{
		std::printf("Game Paused\n");

		ButtonMap::GetMap()["RESUME"]->Update(event, deltaTime);
		ButtonMap::GetMap()["SAVE"]->Update(event, deltaTime);
		ButtonMap::GetMap()["QUIT"]->Update(event, deltaTime);
		ButtonMap::GetMap()["LOAD"]->Update(event, deltaTime);
	}

	if (ButtonMap::GetMap()["RESUME"]->bClicked)
	{
		States::SetPausedState(States::GetPausedState() == false);
		ButtonMap::GetMap()["RESUME"]->bClicked = false;
	}
	if (ButtonMap::GetMap()["QUIT"]->bClicked)
	{
		this->Quit(window);
		ButtonMap::GetMap()["RESUME"]->bClicked = false;
	}
}

void PauseMenu::Render(sf::RenderWindow* window, float deltaTime, sf::Vector2f resumePosition)
{
	sf::Font arial;
	arial.loadFromFile("../Debug/Fonts/arial.ttf");
	sf::Vector2f sizeOffset = sf::Vector2f(
		ButtonMap::GetMap()["RESUME"]->buttonBG.getSize().x / 2.0f,
		ButtonMap::GetMap()["RESUME"]->buttonBG.getSize().y / 2.0f
	);

	ButtonMap::GetMap()["RESUME"]->buttonBG.setPosition(resumePosition + sf::Vector2f(0, -80) - sizeOffset);
	ButtonMap::GetMap()["RESUME"]->buttonText.setFont(arial);
	ButtonMap::GetMap()["RESUME"]->buttonText.setPosition(ButtonMap::GetMap()["RESUME"]->buttonBG.getPosition());
	ButtonMap::GetMap()["RESUME"]->HighlightedButton(window);
	ButtonMap::GetMap()["RESUME"]->Render(window, deltaTime);

	ButtonMap::GetMap()["LOAD"]->buttonBG.setPosition(resumePosition + sf::Vector2f(0, -40) - sizeOffset);
	ButtonMap::GetMap()["LOAD"]->buttonText.setFont(arial);
	ButtonMap::GetMap()["LOAD"]->buttonText.setPosition(ButtonMap::GetMap()["LOAD"]->buttonBG.getPosition());
	ButtonMap::GetMap()["LOAD"]->HighlightedButton(window);
	ButtonMap::GetMap()["LOAD"]->Render(window, deltaTime);

	ButtonMap::GetMap()["SAVE"]->buttonBG.setPosition(resumePosition + sf::Vector2f(0, 0) - sizeOffset);
	ButtonMap::GetMap()["SAVE"]->buttonText.setFont(arial);
	ButtonMap::GetMap()["SAVE"]->buttonText.setPosition(ButtonMap::GetMap()["SAVE"]->buttonBG.getPosition());
	ButtonMap::GetMap()["SAVE"]->HighlightedButton(window);
	ButtonMap::GetMap()["SAVE"]->Render(window, deltaTime);

	ButtonMap::GetMap()["QUIT"]->buttonBG.setPosition(resumePosition + sf::Vector2f(0, 40) - sizeOffset);
	ButtonMap::GetMap()["QUIT"]->buttonText.setFont(arial);
	ButtonMap::GetMap()["QUIT"]->buttonText.setPosition(ButtonMap::GetMap()["QUIT"]->buttonBG.getPosition());
	ButtonMap::GetMap()["QUIT"]->HighlightedButton(window);
	ButtonMap::GetMap()["QUIT"]->Render(window, deltaTime);

	window->display();
}

void PauseMenu::InitButtons()
{
	sf::Vector2f size(125, 35);
	ButtonMap::GetMap().insert(
		{
			"RESUME", new Button(size, sf::Color(100,100,100,255), "RESUME GAME")
		}
	);
	ButtonMap::GetMap().insert(
		{
			"LOAD", new Button(size, sf::Color(100,100,100,255), "LOAD TILE MAP")
		}
	);
	ButtonMap::GetMap().insert(
		{
			"SAVE", new Button(size, sf::Color(100,100,100,255), "SAVE TILE MAP")
		}
	);
	ButtonMap::GetMap().insert(
		{
			"QUIT", new Button(size, sf::Color(100,100,100,255), "QUIT GAME")
		}
	);

}

void PauseMenu::Quit(sf::RenderWindow* window)
{
	window->close();
}
