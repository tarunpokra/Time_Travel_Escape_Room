#ifndef NPC_H
#define NPC_H

#include <string>
#include <vector>

class NPC {
 private:
  std::string _name;

 public:
  NPC(const std::string name);
  std::string getName() const;
};

#endif
