#pragma once
#include "Entity.h"
class Soldier: public Entity
{
private:
	int32_t fireDelay = 0;

public:
	Soldier() = default;
	Soldier(std::string picture, sf::Vector2f location);
	~Soldier() = default;

private:
	static void Fire(ECS::Entity* entity);
};

