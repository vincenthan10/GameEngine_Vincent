#pragma once
#include "../Engine.h"
#include "../Interface/GUI_Components/Button.h"

class TileMapSystem: public ECS::EntitySystem
{
public:
	TileMapSystem() = default;
	~TileMapSystem() = default;
	void tick(ECS::World* world, float deltaTime) override;
	void AddTileOnClick(bool bHasCollision, ECS::ComponentHandle<TileMap> tileMap);
};

