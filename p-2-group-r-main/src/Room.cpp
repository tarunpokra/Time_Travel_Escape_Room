//
// Created by colem on 2024-03-08.
//

#include "Room.h"

#include <Puzzle.h>

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>

#include "Inventory.h"
#include "Item.h"

//------------------------------------------------------------
// Room
Room::Room(RoomState* state)
    : _state(std::move(std::unique_ptr<RoomState>(state))),
      _inventory(),
      _actions() {}

std::string Room::getDescription() { return _state->generateDescription(); }

const Inventory* Room::getInventory() const { return &_inventory; }

std::vector<std::shared_ptr<Item>> Room::getItems() {
  return _inventory.viewInventory();
}

void Room::addItem(std::string name, std::string description) {
  _inventory.addItem(std::make_shared<Item>(name, description));
}

void Room::doAction(std::string action) {
  if (action == "look") {
    std::cout << getDescription() << std::endl;
    return;
  }
  auto it = std::find_if(_actions.begin(), _actions.end(),
                         [&](const auto& a) { return a->getName() == action; });

  if (it != _actions.end()) {
    (*it)->execute();
    return;
  }

  std::cout
      << "Dr. Ravenwood doesn't understand what you are asking them to do."
      << std::endl;
}

//------------------------------------------------------------
// NpcRoom

NpcRoom::NpcRoom(RoomState* state, NPC npc) : Room(state), _npc(npc) {}

NPC* NpcRoom::getNPC() { return &_npc; }

//------------------------------------------------------------
// PuzzleRoom

PuzzleRoom::PuzzleRoom(RoomState* state, Puzzle puzzle)
    : Room(state), _puzzle(puzzle) {}

void PuzzleRoom::doAction(std::string action) {
  if (action == "solve") {
    doPuzzle();
    return;
  }
  Room::doAction(action);
}

void PuzzleRoom::setPuzzleInteraction(Interaction* interaction) {
  _puzzle.setInteraction(interaction);
}

void PuzzleRoom::doPuzzle() {
  std::cout << _puzzle.getDescription() << std::endl;
  std::string answer;
  std::cin >> answer;
  // to lowercase
  for (auto& c : answer) {
    c = std::tolower(c);
  }
  if (_puzzle.solvePuzzle(answer)) {
    _puzzle.markPuzzleInteraction();
    std::cout << _puzzle.getCorrectText() << std::endl;
    return;
  }
  std::cout << _puzzle.getFailText() << std::endl;
}
