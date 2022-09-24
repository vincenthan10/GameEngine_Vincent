#pragma once
#include "../Engine.h"

class RenderingSystem: public ECS::EntitySystem
{
public:
	RenderingSystem();
	~RenderingSystem();
	void tick(ECS::World* world, float deltaTime) override;
};

