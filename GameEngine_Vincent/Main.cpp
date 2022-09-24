#include "sfml/graphics.hpp"
#include "Engine.h"

int main(int argc, char* args[])
{
	// declare and get instance of singleton
	Engine& gameEngine = Engine::GetInstance();
	sf::RenderWindow window(sf::VideoMode(800, 600), "My Game Engine");
	// Pass window reference to the engine and start
	gameEngine.Start(& window);

	return 0;
}