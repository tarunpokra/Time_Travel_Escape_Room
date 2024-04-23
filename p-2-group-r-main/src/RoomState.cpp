#include "RoomState.h"

#include <stdexcept>

RoomState::RoomState() : _interactions() {}

std::string RoomState::generateDescription() {
  std::string description = getDescription();
  for (Interaction interaction : _interactions) {
    description += "\n" + interaction.getDescription();
  }
  return description;
}

bool RoomState::checkCompleted(std::string interactionName) {
  for (Interaction interaction : _interactions) {
    if (interaction.getName() == interactionName) {
      return interaction.checkCompleted();
    }
  }
  return false;
}

bool RoomState::markCompleted(std::string interactionName) {
  for (Interaction interaction : _interactions) {
    if (interaction.getName() == interactionName) {
      return interaction.markCompleted();
    }
  }
  return false;
}

Interaction* RoomState::getInteraction(std::string interactionName) {
  for (auto& interaction : _interactions) {
    if (interaction.getName() == interactionName) {
      return &interaction;
    }
  }
  throw std::invalid_argument("Interaction not found : " + interactionName);
}

void RoomState::addInteraction(const std::string& name,
                               const std::string& notCompletedText,
                               const std::string& completedText) {
  _interactions.push_back(Interaction(name, notCompletedText, completedText));
}
