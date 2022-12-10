#include "TileMapSystem.h"

void TileMapSystem::tick(ECS::World* world, float deltaTime)
{
	world->each<TileMap>(
		[&](ECS::Entity* entity, ECS::ComponentHandle<TileMap> tileMap)->void
		{
			if (States::GetPausedState() == false)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
				{
					this->AddTileOnClick(true, tileMap);
					std::cout << entity->getEntityId() << " is the entity id (with collision" << std::endl;
				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) == true)
				{
					this->AddTileOnClick(false, tileMap);
					std::cout << entity->getEntityId() << " is the entity id (without collision" << std::endl;
				}
			}

			if (ButtonMap::GetMap()["SAVE"]->bClicked == true)
			{
				std::cout << "Saved" << std::endl;
				tileMap->SaveTileMap("tiletest.txt");
				ButtonMap::GetMap()["SAVE"]->bClicked = false;
			}

			if (ButtonMap::GetMap()["LOAD"]->bClicked == true)
			{
				std::cout << "Loaded" << std::endl;
				tileMap->LoadTileMap("tiletest.txt");
				ButtonMap::GetMap()["LOAD"]->bClicked = false;
			}
		});
}

void TileMapSystem::AddTileOnClick(bool bHasCollision, ECS::ComponentHandle<TileMap> tileMap)
{
	// reference for window pointer that is used below to determine active cursor position for adding tiles 
	sf::RenderWindow* winRef = Engine::GetInstance().window;
	sf::Vector2f mousePosView = winRef->mapPixelToCoords(sf::Mouse::getPosition(*winRef));
	sf::Vector2i mousePosGrid(static_cast<int>(mousePosView.x / tileMap->gridSizeF), static_cast<int>(mousePosView.y / tileMap->gridSizeF));
	tileMap->AddTile(mousePosGrid.x, mousePosGrid.y, 0, bHasCollision);

}
