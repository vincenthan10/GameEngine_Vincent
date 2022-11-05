#include "Engine.h"

void Engine::Start(sf::RenderWindow* win)
{
	this->window = win;
	mainCamera = new MainCamera(sf::Vector2f(this->window->getSize().x / 2, this->window->getSize().y / 2));

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

	world->tick(10.0f);

	mainCamera->Update(world, 10.0f, window);
}

Engine& Engine::GetInstance()
{
	static Engine instance;
	return instance;
}

void Engine::AddSystem(ECS::EntitySystem* newSys)
{
	world->registerSystem(newSys);
	world->enableSystem(newSys);
}
