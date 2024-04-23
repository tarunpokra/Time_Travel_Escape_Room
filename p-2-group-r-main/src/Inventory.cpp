//
// Created by colem on 2024-03-08.
//

#include "Inventory.h"

#include <algorithm>
#include <stdexcept>

#include "Item.h"

Inventory::Inventory() : _items() {}

void Inventory::addItem(std::shared_ptr<Item> item) { _items.push_back(item); }

std::vector<std::shared_ptr<Item>> Inventory::viewInventory() { return _items; }

std::shared_ptr<Item> Inventory::removeItem(std::shared_ptr<Item> item) {
  for (int i = 0; i < _items.size(); i++) {
    if (_items[i] == item) {
      std::shared_ptr<Item> item = _items[i];
      _items.erase(_items.begin() + i);
      return item;
    }
  }
  return nullptr;
}

bool Inventory::moveItem(std::shared_ptr<Item> item,
                         Inventory* otherInventory) {
  // Find the item in the other inventory
  auto it = std::find(otherInventory->_items.begin(),
                      otherInventory->_items.end(), item);

  // If the item is found in the other inventory
  if (it != otherInventory->_items.end()) {
    _items.push_back(std::move(*it));
    otherInventory->_items.erase(it);
    return true;
  }
  return false;
}

std::shared_ptr<Item> Inventory::getItem(std::string name) {
  auto it = std::find_if(_items.begin(), _items.end(),
                         [name](const std::shared_ptr<Item>& item) {
                           return item->getName() == name;
                         });
  if (it != _items.end()) {
    return *it;  // Return the shared pointer to the found item
  }
  return nullptr;
}

std::shared_ptr<Item> Inventory::removeItem(std::string name) {
  for (int i = 0; i < _items.size(); i++) {
    if (_items[i]->getName() == name) {
      std::shared_ptr<Item> item = _items[i];
      _items.erase(_items.begin() + i);
      return item;
    }
  }
  return nullptr;
}
