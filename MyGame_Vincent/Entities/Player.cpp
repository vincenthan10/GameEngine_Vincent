#include "Player.h"

Player::Player(sf::Vector2f location):Soldier("../Debug/Pics/Player_1.png", location)
{
	entity->assign<InputController>();

}
