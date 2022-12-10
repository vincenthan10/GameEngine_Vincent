#include "Soldier.h"

Soldier::Soldier(std::string picture, sf::Vector2f location)
{
	Engine& engine = Engine::GetInstance();
	entity = engine.world->create();
	entity->assign<Sprite2D>(picture);
	entity->assign<Transform>(location.x, location.y, 0.03f, 0.03f, 0.0f, 0.05f);
	entity->assign<BoxCollider>(); 
	// TODO: assign fire call back entity

}

void Soldier::Fire(ECS::Entity* entity)
{
}
