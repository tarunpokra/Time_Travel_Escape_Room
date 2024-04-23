#ifndef ROOM_H
#define ROOM_H

#include <memory>
#include <string>
#include <vector>

#include "Action.h"
#include "Inventory.h"
#include "Item.h"
#include "NPC.h"
#include "Puzzle.h"
#include "RoomState.h"

class Room {
 protected:
  Inventory _inventory;
  std::vector<std::unique_ptr<Action>> _actions;
  std::unique_ptr<RoomState> _state;

 public:
  /**
   * Takes a string and searches for an action with that name in the room's
   * actions. If the action is found, the action is executed.
   */
  virtual void doAction(std::string action);
  virtual std::string getName() const = 0;
  virtual int getMinPower() const = 0;
  virtual std::string getMapName() const = 0;

  void addItem(std::string name, std::string description);
  std::string getDescription();
  const Inventory* getInventory() const;
  std::vector<std::shared_ptr<Item>> getItems();
  virtual void generateActions(Inventory* allItems, Player* player) = 0;
  Room(RoomState* state);
};

class NpcRoom : public Room {
 private:
  NPC _npc;

 public:
  NPC* getNPC();

 protected:
  NpcRoom(RoomState* state, NPC npc);
};

class PuzzleRoom : public Room {
 private:
  Puzzle _puzzle;

 protected:
  PuzzleRoom(RoomState* state, Puzzle puzzle);

 public:
  /**
   * Places the user into a distd::string name, std::string abbreviation,
         std::string Room::getMapName() const { return _name; }
              RoomState state, int minPowerLevel,
                       std::string puzzleDescription, std::string correctAnswer,
                       std::string failText, Interaction*
   puzzleInteractionalogue with the puzzle, prompting them to solve
   * it. If the user types exit, the puzzle is exited.
   */
  void doPuzzle();
  void doAction(std::string action) override;
  void setPuzzleInteraction(Interaction* interaction);
};

#endif  // ROOM_H
