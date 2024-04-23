
#include "Interaction.h"

std::string Interaction::getDescription() const {
  if (_value) {
    return _completedText;
  } else {
    return _notCompletedText;
  }
}

std::string Interaction::getName() const { return _name; }

bool Interaction::checkCompleted() { return _value; }

bool Interaction::markCompleted() {
  _value = true;
  return _value;
}

Interaction::Interaction(const std::string& name,
              const std::string& notCompletedText,
              const std::string& completedText)
    : _name(name),
      _notCompletedText(notCompletedText),
      _completedText(completedText),
      _value(false) {}
