#ifndef ROOMSTATE_H
#define ROOMSTATE_H

#include <string>
#include <vector>

#include "Interaction.h"

class RoomState {
 protected:
  std::vector<Interaction> _interactions;

 public:
  /**
   * Generates a description of the current room using the constant description
   * and the interactions that have been completed.
   * @return the description of the room.
   */
  RoomState();
  std::string generateDescription();
  virtual std::string getDescription() const = 0;
  bool checkCompleted(std::string interactionName);
  bool markCompleted(std::string interactionName);
  Interaction* getInteraction(std::string interactionName);
  void addInteraction(const std::string& name,
                      const std::string& notCompletedText,
                      const std::string& completedText);
};

#endif  // ROOMSTATE_H
