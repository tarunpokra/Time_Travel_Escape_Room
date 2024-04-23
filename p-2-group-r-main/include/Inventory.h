#ifndef INVENTORY_H
#define INVENTORY_H

#include <memory>
#include <string>
#include <vector>

#include "Item.h"

class Inventory {
 private:
  std::vector<std::shared_ptr<Item>> _items;

 public:
  Inventory();

  void addItem(std::shared_ptr<Item> item);

  std::shared_ptr<Item> removeItem(std::shared_ptr<Item> item);
  std::shared_ptr<Item> removeItem(std::string name);

  std::vector<std::shared_ptr<Item>> viewInventory();

  bool moveItem(std::shared_ptr<Item> item, Inventory* otherInventory);
  std::shared_ptr<Item> getItem(std::string name);
};

#endif  // INVENTORY_H
