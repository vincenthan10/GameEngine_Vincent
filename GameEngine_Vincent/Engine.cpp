#include "Engine.h"

void Engine::Start(sf::RenderWindow* win)
{
	this->window = win;
	// Run the program as long as the window is open
	while (window->isOpen() == true)
	{
		this->Update();
	}
}

Engine::Engine()
{
	bQuit = false;
}

Engine::~Engine() = default;

void Engine::Update()
{
	sf::Event event;
	while (window->pollEvent(event) == true)
	{
		// Close requested event
		if (event.type == sf::Event::Closed)
		{
			window->close();
		}
	}
}

Engine& Engine::GetInstance()
{
	static Engine instance;
	return instance;
}
