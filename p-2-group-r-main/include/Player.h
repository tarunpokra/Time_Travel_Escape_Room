#ifndef PLAYER_H
#define PLAYER_H

#include "Inventory.h"

class Player {
 private:
  Inventory _inventory;

 public:
  Player();
  Inventory* getInventory();
};

#endif  // PLAYER_H
