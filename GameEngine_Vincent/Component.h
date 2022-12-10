#pragma once
#include "Engine.h"
#include "Tile.h"
#include <fstream>
#include <iostream>

struct Transform
{
public:
	ECS_DECLARE_TYPE;
	float xPos;
	float yPos;
	float rotationAngle;
	float rotationSpeed;
	float xSpeed;
	float ySpeed;
	float xSpeedMod;
	float ySpeedMod;
	bool bColliding;

	Transform(float newX, float newY, float newXSpeed = 0.0f, float newYSpeed = 0.0f, float rotationAngle = 0.0f, float rotationSpeed = 0.0f)
	{
		this->xPos = newX;
		this->yPos = newY;
		this->xSpeed = newX;
		this->ySpeed = newY;
		this->xSpeedMod = newXSpeed;
		this->ySpeedMod = newYSpeed;
		this->rotationAngle = rotationAngle;
		this->rotationSpeed = rotationSpeed;
		
	}

	void Move() 
	{
		this->xPos += this->xSpeed;
		this->yPos += this->ySpeed;
	}

};
ECS_DEFINE_TYPE(Transform);

struct Sprite2D 
{
public:
	ECS_DECLARE_TYPE;

	sf::Sprite picture;
	std::string texture;
	int width, height;

	Sprite2D(std::string filepath) : texture(filepath) 
	{

	}
};
ECS_DEFINE_TYPE(Sprite2D);

struct Animator
{
public:
	ECS_DECLARE_TYPE

	int spriteWidth;
	int spriteHeight;
	int currentColumn;
	int currentRow;
	int totalColumns;
	int totalRows;
	float currentTime;
	float nextFrameTime;
	bool bFacingRight;

	Animator(int newWidth, int newHeight, float timeBetweenFrames, int columns, int rows)
	{
		this->spriteWidth = newWidth;
		this->spriteHeight = newHeight;
		this->currentColumn = 0;
		this->currentRow = 0;
		this->totalColumns = columns;
		this->totalRows = rows;
		this->nextFrameTime = timeBetweenFrames;
		this->currentTime = 0;
		this->bFacingRight = true;
	}
};
ECS_DEFINE_TYPE(Animator);

struct InputController
{
public:
	ECS_DECLARE_TYPE;
	bool bInputActive;
	bool w, a, s, d, left, right, up, down, space;

	InputController() 
	{
		std::memset(this, false, sizeof(InputController));
		bInputActive = true;
	}
};
ECS_DEFINE_TYPE(InputController);

struct BoxCollider 
{
public:
	ECS_DECLARE_TYPE;
	int leftEdge, rightEdge, bottomEdge, topEdge;

	BoxCollider()
	{
		std::memset(this, 0, sizeof(BoxCollider));
	}

	void Update(int x, int y, int width, int height) 
	{
		this->leftEdge = x;
		this->rightEdge = x + width;
		this->bottomEdge = y + height;
		this->topEdge = y;
	}
};
ECS_DEFINE_TYPE(BoxCollider);

struct Tag {
	ECS_DECLARE_TYPE;
public:
	std::vector<std::string> tagNames;
	Tag() = default;
	void addTag(std::string tag)
	{
		this->tagNames.push_back(tag);
	}

};
ECS_DEFINE_TYPE(Tag);

struct TileMap {
	ECS_DECLARE_TYPE;
public:
	float gridSizeF;
	uint32_t gridSizeU;
	uint32_t layers;
	sf::Vector2u maxSize;
	sf::RectangleShape collisionBox;
	std::vector<std::vector<std::vector<Tile*>>> map;
	
	TileMap() {
		this->gridSizeF = 50.0f;
		this->gridSizeU = static_cast<uint32_t>(this->gridSizeF); 
		// number of tiles
		this->maxSize.x = 20;
		this->maxSize.y = 20;
		this->layers = 1;
		this->map.resize(this->maxSize.x);
		for (size_t x = 0; x < this->maxSize.x; x++)
		{
			this->map.push_back(std::vector<std::vector<Tile*>>());

			for (size_t y = 0; y < this->maxSize.y; y++)
			{
				this->map.at(x).resize(this->maxSize.y);
				this->map[x].push_back(std::vector<Tile*>());

				for (size_t z = 0; z < this->layers; z++)
				{
					this->map.at(x).at(y).resize(this->layers);
					this->map[x][y].push_back(nullptr);
				}
			}
		}

		this->collisionBox.setSize(sf::Vector2f(this->gridSizeF, this->gridSizeF));
		this->collisionBox.setFillColor(sf::Color(0,255,0,50));
		this->collisionBox.setOutlineColor(sf::Color::Green);
		this->collisionBox.setOutlineThickness(-1.0f);
	}

	~TileMap() {
		this->Clear();
	}

	void AddTile(const int32_t x, const int32_t y, const int32_t z, bool bHasCollision) {
		if (x < this->maxSize.x && x >= 0 &&
			y < this->maxSize.y && y >= 0 &&
			z < this->layers && z >= 0) {
			if (this->map[x][y][z] == nullptr) {
				this->map[x][y][z] = new Tile(x, y, this->gridSizeF, bHasCollision);
				std::cout << "added" << std::endl;
			}
		}
	}

	void Clear() {
		for (size_t x = 0; x < this->maxSize.x; x++)
		{
			for (size_t y = 0; y < this->maxSize.y; y++)
			{
				for (size_t z = 0; z < this->layers; z++)
				{
					delete this->map[x][y][z];
				}
				this->map[x][y].clear();
			}
			this->map[x].clear();
		}
		this->map.clear();
	}

	void SaveTileMap(std::string filename) {
		std::ofstream saveFile;
		saveFile.open(filename);

		if (saveFile.is_open() == true)
		{
			saveFile << maxSize.x << " " << maxSize.y << "\n" << gridSizeF << "\n" << layers << "\n";
			for (size_t x = 0; x < this->maxSize.x; x++)
			{
				for (size_t y = 0; y < this->maxSize.y; y++)
				{
					for (size_t z = 0; z < this->layers; z++)
					{
						if (this->map[x][y][z] != nullptr)
						{
							saveFile << x << " " << y << " " << z << " " << this->map[x][y][z]->toString() << " " << "\n";
						}

					}
				}
			}
		}
		else {
			std::cout << "Error: Tilemap could not be saved to file" << filename << std::endl;
		
		}
		saveFile.close();
	}

	void LoadTileMap(std::string filename) {
		std::ifstream loadFile;
		loadFile.open(filename);
		if (loadFile.is_open() == true)
		{
			bool bColliding = false;
			loadFile >> maxSize.x >> maxSize.y >> gridSizeF >> layers;
			this->Clear();
			this->map.resize(this->maxSize.x, std::vector<std::vector<Tile*>>());

			for (size_t x = 0; x < this->maxSize.x; x++)
			{
				for (size_t y = 0; y < this->maxSize.y; y++)
				{
					this->map[x].resize(this->maxSize.y, std::vector<Tile*>());
					for (size_t z = 0; z < this->layers; z++)
					{
						this->map[x][y].resize(this->layers, nullptr);
					}
				}
			}

			while (loadFile >> maxSize.x >> maxSize.y >> layers >> bColliding)
			{
				std::cout << maxSize.x << ", " << maxSize.y << ", " << this->layers << "\n";
				this->map[this->maxSize.x][this->maxSize.y][this->layers] = new Tile(this->maxSize.x, this->maxSize.y, this->gridSizeF, bColliding);
			}
		}
		else 
		{
			std::cout << "Error: Tilemap could not load" << filename << std::endl;
		}
		loadFile.close();
	}
};
ECS_DEFINE_TYPE(TileMap);