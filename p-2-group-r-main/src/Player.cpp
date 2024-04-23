
#include "Player.h"

Player::Player() : _inventory() {}

Inventory* Player::getInventory() { return &_inventory; }
