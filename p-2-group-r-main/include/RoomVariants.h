#ifndef ROOMVARIANTS_H
#define ROOMVARIANTS_H

#include <string>

#include "Player.h"
#include "Room.h"

class TimeMachineRoom : public Room {
 public:
  int getPowerLevel();
  std::string getName() const override;
  int getMinPower() const override;
  std::string getMapName() const override;
  void generateActions(Inventory* allItems, Player* player) override;
  TimeMachineRoom();
};

class PersiaRoom : public NpcRoom {
 public:
  std::string getName() const override;
  int getMinPower() const override;
  std::string getMapName() const override;
  void generateActions(Inventory* allItems, Player* player) override;
  PersiaRoom();
};

class EgyptRoom : public PuzzleRoom {
 public:
  std::string getName() const override;
  int getMinPower() const override;
  std::string getMapName() const override;
  void generateActions(Inventory* allItems, Player* player) override;
  EgyptRoom();
};

class RomeRoom : public Room {
 public:
  std::string getName() const override;
  int getMinPower() const override;
  std::string getMapName() const override;
  void generateActions(Inventory* allItems, Player* player) override;
  RomeRoom();
};

class JapanRoom : public Room {
 public:
  std::string getName() const override;
  int getMinPower() const override;
  std::string getMapName() const override;
  void generateActions(Inventory* allItems, Player* player) override;
  JapanRoom();
};
class RenaissanceRoom : public NpcRoom {
 public:
  std::string getName() const override;
  int getMinPower() const override;
  std::string getMapName() const override;
  void generateActions(Inventory* allItems, Player* player) override;
  RenaissanceRoom();
};

class USARoom : public PuzzleRoom {
 public:
  std::string getName() const override;
  int getMinPower() const override;
  std::string getMapName() const override;
  void generateActions(Inventory* allItems, Player* player) override;
  USARoom();
};

class WW2Room : public Room {
 public:
  std::string getName() const override;
  int getMinPower() const override;
  std::string getMapName() const override;
  void generateActions(Inventory* allItems, Player* player) override;
  WW2Room();
};

class PresentRoom : public Room {
 public:
  std::string getName() const override;
  int getMinPower() const override;
  std::string getMapName() const override;
  void generateActions(Inventory* allItems, Player* player) override;
  PresentRoom();
};

class FutureRoom : public Room {
 public:
  std::string getName() const override;
  int getMinPower() const override;
  std::string getMapName() const override;
  void generateActions(Inventory* allItems, Player* player) override;
  FutureRoom();
};

#endif  // ROOMVARIANTS_H
