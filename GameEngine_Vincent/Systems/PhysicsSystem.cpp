#include "PhysicsSystem.h"

bool PhysicsSystem::isColliding(ECS::ComponentHandle<BoxCollider> touchingBox, ECS::ComponentHandle<BoxCollider> touchedBox, float x, float y)
{
    return touchingBox->rightEdge + x > touchedBox->leftEdge &&
        touchedBox->rightEdge > touchingBox->leftEdge + x &&
        touchingBox->bottomEdge + y > touchedBox->topEdge &&
        touchedBox->bottomEdge > touchingBox->topEdge + y;
}

bool PhysicsSystem::isColliding(ECS::ComponentHandle<BoxCollider> touchingBox, sf::RectangleShape touchedRectangle, float x, float y)
{
    float touchedRectLeft = touchedRectangle.getPosition().x;
    float touchedRectRight = touchedRectLeft + touchedRectangle.getGlobalBounds().width;
    float touchedRectTop = touchedRectangle.getPosition().y;
    float touchedRectBottom = touchedRectTop + touchedRectangle.getGlobalBounds().height;

    return touchingBox->rightEdge + x > touchedRectLeft &&
        touchedRectRight > touchingBox->leftEdge + x &&
        touchingBox->bottomEdge + y > touchedRectTop &&
        touchedRectBottom > touchingBox->topEdge + y;
}

bool PhysicsSystem::isColliding(ECS::ComponentHandle<BoxCollider> touchingBox, sf::RectangleShape touchedRectangle)
{
    float touchedRectLeft = touchedRectangle.getPosition().x;
    float touchedRectRight = touchedRectLeft + touchedRectangle.getGlobalBounds().width;
    float touchedRectTop = touchedRectangle.getPosition().y;
    float touchedRectBottom = touchedRectTop + touchedRectangle.getGlobalBounds().height;

    return touchingBox->rightEdge > touchedRectLeft &&
        touchedRectRight > touchingBox->leftEdge &&
        touchingBox->bottomEdge > touchedRectTop &&
        touchedRectBottom > touchingBox->topEdge;
}

bool PhysicsSystem::isColliding(ECS::ComponentHandle<BoxCollider> touchingBox, ECS::ComponentHandle<BoxCollider> touchedBox)
{
    return touchingBox->rightEdge > touchedBox->leftEdge &&
        touchedBox->rightEdge > touchingBox->leftEdge &&
        touchingBox->bottomEdge > touchedBox->topEdge &&
        touchedBox->bottomEdge > touchingBox->topEdge;
}

void PhysicsSystem::checkCollisionSize(ECS::ComponentHandle<Transform> transform, ECS::ComponentHandle<BoxCollider> touchingBox, ECS::ComponentHandle<BoxCollider> touchedBox)
{
    // scenario dealing with collision from the right side by accelerating rightward
    if (transform->xSpeed > 0 &&
        touchedBox->rightEdge + transform->xSpeed > touchedBox->leftEdge &&
        touchingBox->topEdge < touchedBox->bottomEdge &&
        touchingBox->bottomEdge > touchedBox->topEdge)
    {
        transform->xSpeed = 0;
    }

    // scenario dealing with collision from the bottom side by accelerating downward
    if (transform->ySpeed > 0 &&
        touchedBox->bottomEdge + transform->ySpeed > touchedBox->topEdge &&
        touchingBox->leftEdge < touchedBox->rightEdge &&
        touchingBox->rightEdge > touchedBox->leftEdge)
    {
        transform->ySpeed = 0;
    }

    // scenario dealing with collision from the left side by accelerating leftward


}

void PhysicsSystem::checkCollisionSize(ECS::ComponentHandle<Transform> transform, ECS::ComponentHandle<BoxCollider> touchingBox, sf::RectangleShape touchedRectangle)
{
}

void PhysicsSystem::checkCollisionSize(ECS::Entity* touchingEntity, ECS::Entity* touchedEntity)
{
}

void PhysicsSystem::tick(ECS::World* world, float deltaTime)
{
}
