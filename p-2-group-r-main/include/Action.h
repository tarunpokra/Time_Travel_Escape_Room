#ifndef ACTION_H
#define ACTION_H

#include <memory>
#include <string>

#include "Interaction.h"
#include "Inventory.h"
#include "Item.h"
#include "NPC.h"
#include "Player.h"

class Action {
 protected:
  std::string _name;
  std::string _result;
  std::string _failed;
  Interaction* _interaction;
  Interaction* _requiredInteraction;

 public:
  Action(const std::string& name, const std::string& result,
         const std::string& failed, Interaction* interaction,
         Interaction* requiredInteraction);
  std::string getName() const;
  virtual void execute() = 0;
};

class Look : public Action {
 public:
  void execute() override;
};

class Pickup : public Action {
 private:
  Player* _player;
  Inventory* _roomInventory;
  std::shared_ptr<Item> _item;

 public:
  Pickup(const std::string& name, const std::string& result,
         const std::string& failed, Interaction* interaction,
         Interaction* requiredInteraction, std::shared_ptr<Item> item,
         Player* player, Inventory* roomInventory);
  void execute() override;
};

class Use : public Action {
 private:
  bool removeItem;
  std::shared_ptr<Item> _item;
  Player* _player;

 public:
  void execute() override;
  Use(const std::string& name, const std::string& result,
      const std::string& failed, Interaction* interaction,
      Interaction* requiredInteraction, std::shared_ptr<Item> item,
      Player* player, bool removeItem);
};

class Talk : public Action {
 private:
  NPC* _npc;

 public:
  Talk(const std::string& name, const std::string& result,
       const std::string& failed, Interaction* interaction,
       Interaction* requiredInteraction, NPC* npc);
  void execute() override;
};

#endif  // ACTION_H
