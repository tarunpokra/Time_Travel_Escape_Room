#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include <memory>
#include <string>
#include <vector>

#include "Item.h"
#include "Player.h"
#include "Room.h"
#include "RoomVariants.h"

class RoomManager {
 private:
  std::vector<std::unique_ptr<Room>> _rooms;
  Room* _currentRoom;
  Inventory _items;
  std::unique_ptr<TimeMachineRoom> _timeMachine;
  Room* _timeMachineLocation;
  Player _player;

  void toggleLocation();
  void moveTimeMachine();
  void printMap();
  void printInventory();
  void printMapTable();

 public:
  std::string getRoomName();
  RoomManager();
  bool checkContinue();
  void doAction(std::string Action);
};

#endif  // ROOMMANAGER_H
