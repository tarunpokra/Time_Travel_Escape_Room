
#include "RoomManager.h"

#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <stdexcept>
#include <string>

RoomManager::RoomManager() : _player(), _rooms(), _items() {
  // Create rooms from classes
  _timeMachine = std::make_unique<TimeMachineRoom>();
  _rooms.push_back(std::make_unique<PersiaRoom>());
  _rooms.push_back(std::make_unique<EgyptRoom>());
  _rooms.push_back(std::make_unique<RomeRoom>());
  _rooms.push_back(std::make_unique<JapanRoom>());
  _rooms.push_back(std::make_unique<RenaissanceRoom>());
  _rooms.push_back(std::make_unique<USARoom>());
  _rooms.push_back(std::make_unique<WW2Room>());
  _rooms.push_back(std::make_unique<PresentRoom>());
  _rooms.push_back(std::make_unique<FutureRoom>());

  // Add room items to the RoomManager
  for (auto& room : _rooms) {
    for (auto& item : room->getItems()) {
      _items.addItem(item);
    }
  }

  for (auto& room : _rooms) {
    room->generateActions(&_items, &_player);
  }

  _timeMachine->generateActions(&_items, &_player);

  // Set starting locations
  _timeMachineLocation = _rooms[0].get();
  _currentRoom = _timeMachine.get();
}

bool RoomManager::checkContinue() { return !(_currentRoom == _rooms[7].get()); }

void RoomManager::doAction(std::string action) {
  // Check for special commands
  // Like map, inventory
  if (action == "map") {
    printMap();
    return;
  }
  if (action == "inventory") {
    printInventory();
    return;
  }

  // Toggle between time machine and room
  if (action == "move") {
    toggleLocation();
    return;
  }

  if (action == "travel") {
    moveTimeMachine();
    return;
  }

  _currentRoom->doAction(action);
}

void RoomManager::moveTimeMachine() {
  if (_currentRoom != _timeMachine.get()) {
    std::cout << "You must be in the time machine to travel." << std::endl;
    return;
  }
  while (true) {
    std::cout << "\033[2J\033[H";
    printMap();
    std::string location;
    std::cout << "Enter the abbreviation of the location you would like to "
              << "travel to. Type exit to leave." << std::endl;
    std::cin >> location;
    if (location == "exit") {
      std::cout << "You stop controlling the time machine" << std::endl;
      return;
    }

    for (auto& c : location) {
      c = std::toupper(c);
    }
    int power = _timeMachine->getPowerLevel();
    for (unsigned i = 0; i < _rooms.size(); i++) {
      if (_rooms[i]->getMapName() == location &&
          _rooms[i]->getMinPower() <= power) {
        _timeMachineLocation = _rooms[i].get();
        std::cout << "The Time Machine rumbles as you arive at "
                  << _timeMachineLocation->getName() << std::endl;
        std::cout << "You stop controlling the time machine." << std::endl;
        return;
      }
    }
  }
}

void RoomManager::toggleLocation() {
  if (_currentRoom == _timeMachineLocation) {
    _currentRoom = _timeMachine.get();
  } else {
    _currentRoom = _timeMachineLocation;
  }

  std::cout << "You are now in " << _currentRoom->getName() << std::endl
            << std::endl;
  std::cout << _currentRoom->getDescription() << std::endl;
}

void RoomManager::printMap() {
  // Check if the room array is not of size
  if (_rooms.size() != 9) {
    throw std::runtime_error("Invalid Size");
  }

  printMapTable();

  // Print the Top bar
  std::cout << "||";
  for (unsigned i = 0; i < 9; i++) {
    std::cout << _rooms[i]->getMapName();
    if (i == 8) continue;
    std::cout << "   ";
  }
  std::cout << "||" << std::endl;

  // Print the middle bar
  std::cout << "||-";
  for (unsigned i = 0; i < 9; i++) {
    if (_currentRoom == _rooms[i].get()) {
      std::cout << 'o';
    } else {
      std::cout << '-';
    }
    if (i == 8) continue;
    std::cout << "-----";
  }
  std::cout << "-||" << std::endl;

  int power = _timeMachine->getPowerLevel();

  // Print the bottom bar
  std::cout << "||=";
  for (unsigned i = 0; i < 9; i++) {
    if (_timeMachineLocation == _rooms[i].get()) {
      std::cout << 'T';
    } else if (_rooms[i]->getMinPower() <= power) {
      std::cout << '|';
    } else {
      std::cout << 'X';
    }
    if (i == 8) continue;
    std::cout << "=====";
  }
  std::cout << "=||" << std::endl;
}

void tableLine() {
  std::cout << "+------+";
  for (int i = 0; i < 18; i++) {
    std::cout << '-';
  }
  std::cout << "+------+";
  for (int i = 0; i < 18; i++) {
    std::cout << '-';
  }
  std::cout << "+" << std::endl;
}

void RoomManager::printMapTable() {
  tableLine();
  std::cout << "| Abbv | " << std::setw(17) << std::left << "Full Name"
            << "| " << std::setw(7) << std::right << "| " << std::setw(18)
            << std::right << "|" << std::endl;
  tableLine();

  for (unsigned i = 0; i < 9; i++) {
    if (i % 2 == 0) {
      std::cout << "|";
    }
    std::cout << " " << std::setw(5) << std::left << _rooms[i]->getMapName()
              << "| " << std::setw(17) << std::left << _rooms[i]->getName()
              << "|";
    if (i % 2 == 1) {
      std::cout << std::endl;
    }
  }
  std::cout << "  " << std::setw(4) << std::left << ""
            << "| " << std::setw(17) << std::left << ""
            << "|" << std::endl;
  tableLine();
  std::cout << std::endl;
}

std::string RoomManager::getRoomName() { return _currentRoom->getName(); }

void RoomManager::printInventory() {
  std::cout << "Inventory: " << std::endl;
  for (auto item : _player.getInventory()->viewInventory()) {
    std::cout << item->getName() << ". " << item->getDescription() << std::endl;
  }
}
