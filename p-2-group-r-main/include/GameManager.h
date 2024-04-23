#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <string>

#include "RoomManager.h"

class GameManager {
 private:
  RoomManager _roomManager;
  void processInput(std::string action);
  bool _playing = true;
  void stopGame();
  void printHelp();

 public:
  GameManager();
  void play();
};

#endif  // GAMEMANAGER_H
