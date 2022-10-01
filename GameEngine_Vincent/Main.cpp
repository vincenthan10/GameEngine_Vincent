#include "sfml/graphics.hpp"
#include "Engine.h"

int main(int argc, char* args[])
{
	// declare and get instance of singleton
	Engine& gameEngine = Engine::GetInstance();
	sf::RenderWindow window(sf::VideoMode(800, 600), "My Game Engine");

	// create the world and attach entities and systems to
	gameEngine.world = ECS::World::createWorld();
	ECS::Entity* stickFigure;

	// add systems to the engine
	gameEngine.AddSystem(new RenderingSystem());

	// create & assign 250 entities to the world
	for (int x = 0; x < 25; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			stickFigure = gameEngine.world->create();
			// assign components to entities after creation
			stickFigure->assign<Transform>(x * 25, y * 32);
			stickFigure->assign<Sprite2D>("../Debug/Pics/hero.png");
			std::cout << stickFigure->getEntityId() << " is the entity id." << std::endl;
		}
	}

	// Pass window reference to the engine and start
	gameEngine.Start(& window);

	return 0;
}