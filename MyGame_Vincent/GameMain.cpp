#include "../GameEngine_Vincent/Engine.h"

int main(int argc, char* args[])
{
	// declare and get instance of singleton
	Engine& gameEngine = Engine::GetInstance();
	sf::RenderWindow window(sf::VideoMode(800, 600), "My Game Engine");

	// create the world and attach entities and systems to
	gameEngine.world = ECS::World::createWorld();
	ECS::Entity* background = nullptr;
	ECS::Entity* stickFigure = nullptr;
	ECS::Entity* tux = nullptr;

	// add systems to the engine
	gameEngine.AddSystem(new RenderingSystem());
	gameEngine.AddSystem(new AnimationSystem());

	// Create and assign entities to the world
	background = gameEngine.world->create();
	stickFigure = gameEngine.world->create();
	tux = gameEngine.world->create();

	// Assign components to entities after creation 
	background->assign<Transform>(0, 0);
	background->assign<Sprite2D>("../Debug/Pics/bg.jpg");
	stickFigure->assign<Transform>(300, 300);
	stickFigure->assign<Sprite2D>("../Debug/Pics/heroSheet.png");
	stickFigure->assign<Animator>(32, 32, 200.0f, 4, 1);
	tux->assign<Transform>(200, 200);
	tux->assign<Sprite2D>("../Debug/Pics/tux_from_linux.png");
	tux->assign<Animator>(56, 72, 2000.0f, 3, 9);
	tux->get<Animator>()->currentRow = 0; // idle row

	std::cout << background->getEntityId() << " is the entity id." << std::endl;
	std::cout << stickFigure->getEntityId() << " is the entity id." << std::endl;
	std::cout << tux->getEntityId() << " is the entity id." << std::endl;

	// Pass window reference to the engine and start
	gameEngine.Start(&window);

	return 0;
}