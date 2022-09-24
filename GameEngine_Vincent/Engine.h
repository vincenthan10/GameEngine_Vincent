#pragma once
#include <iostream>
#include "sfml/Graphics.hpp"
#include "ECS.h"
#include "Component.h"
#include "Systems/RenderingSystem.h"

class Engine
{
public:
	sf::RenderWindow* window = nullptr;
	ECS::World* world = nullptr;

private:
	bool bQuit;

public:
	void Start(sf::RenderWindow* win);
	static Engine& GetInstance();
	void AddSystem(ECS::EntitySystem* newSys);

private:
	Engine();
	// required to prevent the reference from being copied moved or assigned
	Engine(Engine& copy); // hide copy constructor
	Engine(Engine&& other); // hide move constructor
	Engine& operator=(Engine& copy); // hide assignment operator

	~Engine();
	void Update();

};

