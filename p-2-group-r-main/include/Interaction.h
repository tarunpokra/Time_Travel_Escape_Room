#include <string>
#ifndef INTERACTION_H
#define INTERACTION_H

class Interaction {
 private:
  std::string _notCompletedText;
  std::string _completedText;
  std::string _name;
  bool _value;

 public:
  bool checkCompleted();
  bool markCompleted();
  std::string getName() const;
  std::string getDescription() const;
  Interaction(const std::string& name, const std::string& notCompletedText,
              const std::string& completedText);
};

#endif  // INTERACTION_H
