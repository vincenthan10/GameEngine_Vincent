#include "MainCamera.h"

MainCamera::MainCamera(sf::Vector2f pivot)
{
	cameraView.setCenter(pivot);
}

void MainCamera::Update(ECS::World* world, float deltaTime, sf::RenderWindow* window)
{
	if (States::GetPausedState() == false)
	{
		float cameraMoveSpeed = 0.1f;

		cameraView.setSize(window->getSize().x, window->getSize().y);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) == true)
		{
			cameraView.move(-cameraMoveSpeed * deltaTime, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) == true)
		{
			cameraView.move(cameraMoveSpeed * deltaTime, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) == true)
		{
			cameraView.move(0, cameraMoveSpeed * deltaTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) == true)
		{
			cameraView.move(0, -cameraMoveSpeed * deltaTime);
		}
		window->setView(cameraView);
	}
}
