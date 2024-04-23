//
// Created by colem on 2024-03-08.
//

#include "GameManager.h"

#include <iostream>
#include <limits>
#include <string>

GameManager::GameManager() : _roomManager() {}

void GameManager::play() {
  std::cout << "\033[2J\033[H";
  std::cout
      << "You are Dr. Ravenwood, a brilliant scientist who has invented a "
         "time machine. You were working on your time machine when you spilt "
         "coffee on a component, the coffee caused it to explode. \nYou were "
         "thrown into your damnaged time machine and now are stuck in another "
         "time. \nUse your time machine to find resonating artifacts to get "
         "yourself home. Type help for guidnce. Good luck!"
      << std::endl;
  std::cout << "Press ENTER to continue..." << std::endl;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  // std::cin.get();
  while (_roomManager.checkContinue() && _playing) {
    std::cout << "\033[2J\033[H";
    std::string action;

    std::cout << "You are currently in " << _roomManager.getRoomName()
              << std::endl
              << "What would you like to do?" << std::endl;
    std::getline(std::cin, action);
    std::cout << std::endl << std::endl;
    processInput(action);
    std::cout << "Press ENTER to continue..." << std::endl << std::flush;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // std::getline(std::cin, action);
  }
  if (_playing) {
    std::cout << "Returning to the present day, you stop yourself from "
                 "spilling coffee on the component. You have saved the day! "
                 "And now there are two of you..."
              << std::endl;
  }
}

void GameManager::processInput(std::string action) {
  // Convert to lowercase
  for (char& c : action) {
    c = std::tolower(c);
  }

  if (action == "help") {
    std::cout << "Commands: " << std::endl
              << "move: Move between the time machine and the current room"
              << std::endl
              << "look: Look around the room"
              << std::endl
              //<< "Look at ___: Look at something in the room" << std::endl
              << "pickup ___: Take something in the room"
              << std::endl
              //<< "use ___: use an item in your inventory" << std::endl
              << "use ___ on ___: use an item on something in the room"
              << std::endl
              << "solve ___: Solve a puzzle" << std::endl
              << "talk to ___: Talk to an NPC" << std::endl
              << "travel: Travel to a different time period"
              << " (only available in the time machine)" << std::endl
              << "inventory: List the items in your inventory" << std::endl
              << "map: Show the map" << std::endl
              << "help: Show this message" << std::endl
              << "quit: Quit the game" << std::endl;
    return;
  }

  if (action == "quit") {
    std::cout << "quitting..." << std::endl;
    stopGame();
    return;
  }

  _roomManager.doAction(action);
}

void GameManager::stopGame() { _playing = false; }
