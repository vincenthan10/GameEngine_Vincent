#include "Tile.h"

Tile::Tile(float xPos, float yPos, float gridSizef, bool bColliding)
{
    this->shape.setSize(sf::Vector2f(gridSizef, gridSizef));
    this->shape.setFillColor(sf::Color::Red);
    this->shape.setPosition(xPos * gridSizef, yPos * gridSizef);
    this->bColliding = bColliding;
}

void Tile::Render(sf::RenderTarget& target)
{
    target.draw(this->shape);
}

const bool& Tile::GetCollision() const
{
    return this->bColliding;
}

const sf::Vector2f& Tile::GetPosition() const
{
    return this->shape.getPosition();
}

std::string Tile::toString()
{
    std::stringstream stringForm;
    stringForm << this->bColliding << " ";
    return stringForm.str();
}
