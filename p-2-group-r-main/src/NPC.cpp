//
// Created by colem on 2024-03-08.
//

#include "NPC.h"

NPC::NPC(const std::string name) : _name(name) {}

std::string NPC::getName() const { return _name; }
