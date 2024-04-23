
#include <iostream>
#include <memory>
#include <string>

#include "Action.h"
#include "Interaction.h"

// -------------------------------
// Action

Action::Action(const std::string& name, const std::string& result,
               const std::string& failed, Interaction* interaction,
               Interaction* requiredInteraction)
    : _name(name),
      _result(result),
      _failed(failed),
      _interaction(interaction),
      _requiredInteraction(requiredInteraction) {}

std::string Action::getName() const { return _name; }

// -------------------------------
// Look

void Look::execute() {
  if (_requiredInteraction != nullptr) {
    if (_requiredInteraction->checkCompleted()) {
      std::cout << _failed << std::endl;
      return;
    }
  }

  std::cout << _result << std::endl;
}

// -------------------------------
// Pickup

Pickup::Pickup(const std::string& name, const std::string& result,
               const std::string& failed, Interaction* interaction,
               Interaction* requiredInteraction, std::shared_ptr<Item> item,
               Player* player, Inventory* roomInventory)
    : Action(name, result, failed, interaction, requiredInteraction),
      _item(item),
      _player(player),
      _roomInventory(roomInventory) {}

void Pickup::execute() {
  if (_interaction->checkCompleted()) {
    std::cout << "I've already done this." << std::endl;
    return;
  }
  if (_requiredInteraction != nullptr) {
    if (!_requiredInteraction->checkCompleted()) {
      std::cout << _failed << std::endl;
      return;
    }
  }

  _interaction->markCompleted();
  _player->getInventory()->moveItem(_item, _roomInventory);
  std::cout << _result << std::endl;
}

// -------------------------------
// Use

Use::Use(const std::string& name, const std::string& result,
         const std::string& failed, Interaction* interaction,
         Interaction* requiredInteraction, std::shared_ptr<Item> item,
         Player* player, bool removeItem)
    : Action(name, result, failed, interaction, requiredInteraction),
      _item(item),
      _player(player),
      removeItem(removeItem) {}

void Use::execute() {
  if (_interaction->checkCompleted()) {
    std::cout << "I've already done this." << std::endl;
    return;
  }

  if (_requiredInteraction != nullptr) {
    if (!_requiredInteraction->checkCompleted()) {
      std::cout << _failed << std::endl;
      return;
    }
  }
  if (!_player->getInventory()->getItem(_item->getName())) {
    std::cout
        << "Dr Ravenwood does not have the required item in their inventory."
        << std::endl;
    return;
  }

  if (removeItem) {
    _player->getInventory()->removeItem(_item);
  }

  _interaction->markCompleted();
  std::cout << _result << std::endl;
}

// -------------------------------
// Talk

Talk::Talk(const std::string& name, const std::string& result,
           const std::string& failed, Interaction* interaction,
           Interaction* requiredInteraction, NPC* npc)
    : Action(name, result, failed, interaction, requiredInteraction),
      _npc(npc) {}

void Talk::execute() {
  if (_interaction->checkCompleted()) {
    std::cout << "I've already done this." << std::endl;
    return;
  }
  if (_requiredInteraction != nullptr) {
    if (!_requiredInteraction->checkCompleted()) {
      std::cout << _failed << std::endl;
      return;
    }
  }

  _interaction->markCompleted();
  std::cout << _result << std::endl;
}
