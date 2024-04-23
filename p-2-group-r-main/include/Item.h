#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
 private:
  std::string _name;
  std::string _description;

 public:
  Item(std::string name, std::string description);
  std::string getName() const;
  std::string getDescription() const;
};

#endif  // ITEM_H
