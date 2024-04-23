//
// Created by colem on 2024-03-08.
//

#include "Item.h"

#include <string>

Item::Item(std::string name, std::string description) {
  _name = name;
  _description = description;
}

std::string Item::getName() const { return _name; }

std::string Item::getDescription() const { return _description; }
