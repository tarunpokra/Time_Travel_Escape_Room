
#include "RoomVariants.h"

#include <string>

#include "RoomStateVariants.h"

//-----------------------------------------
// TimeMachineRoom

TimeMachineRoom::TimeMachineRoom() : Room(new TimeMachineState()) {}

int TimeMachineRoom::getPowerLevel() {
  int power = 1;
  for (int i = 1; i < 4; i++) {
    if (_state->checkCompleted("slot" + std::to_string(i) + " filled")) {
      power += 1;
    }
  }
  return power;
}

std::string TimeMachineRoom::getName() const { return "The Time Machine"; }

int TimeMachineRoom::getMinPower() const { return 1; }

std::string TimeMachineRoom::getMapName() const { return "TME"; }

void TimeMachineRoom::generateActions(Inventory* allItems, Player* player) {
  _actions.push_back(std::make_unique<Use>(
      "use chariot on slot",
      "The chariot fits perfectly into the slot. The time machines gets "
      "powered up.",
      "You dont have the chariot.", _state->getInteraction("slot1 filled"),
      nullptr, allItems->getItem("Chariot"), player, true));
  _actions.push_back(std::make_unique<Use>(
      "use film reel on slot",
      "The film reel fits perfectly into the slot. The time machines gets "
      "powered up.",
      "You dont have the film reel.", _state->getInteraction("slot2 filled"),
      nullptr, allItems->getItem("Film reel"), player, true));
  _actions.push_back(std::make_unique<Use>(
      "use cube on slot",
      "The quantum data cube fits perfectly into the slot. The time machines "
      "gets powered up.",
      "You dont have the quantum data cube.",
      _state->getInteraction("slot3 filled"), nullptr,
      allItems->getItem("Quantum Data Cube"), player, true));
}

//-----------------------------------------
// PersiaRoom

PersiaRoom::PersiaRoom() : NpcRoom(new PersiaState(), NPC("Darius III")) {
  addItem("Sword", "A sword of the persian empire");
  addItem("Chariot",
          "A chariot of the persian empire. It resonates with time energy.");
  addItem("Chalice", "An empty chalice, looks to be looted from somewhere.");
}

std::string PersiaRoom::getName() const { return "Persia"; }

int PersiaRoom::getMinPower() const { return 1; }

std::string PersiaRoom::getMapName() const { return "PER"; }

void PersiaRoom::generateActions(Inventory* allItems, Player* player) {
  _actions.push_back(std::make_unique<Pickup>(
      "pickup sword", "You pick up the sword.", "The sword is already taken.",
      _state->getInteraction("sword picked up"), nullptr,
      allItems->getItem("Sword"), player, &_inventory));

  _actions.push_back(std::make_unique<Use>(
      "use gem on pedistal",
      "The gem fits perfectly into the slot. Light shines on Darius, curing "
      "all his wounds. The gaurds relax. The pedistal is filled with the "
      "Emporer's Gem.",
      "You dont have the gem.", _state->getInteraction("gem used on pedistal"),
      nullptr, allItems->getItem("Emporer's Gem"), player, true));

  _actions.push_back(std::make_unique<Talk>(
      "talk to darius",
      "Darius thanks you for curing him. He holds out a resonating golden "
      "chariot.",
      "The gaurds stop you from walking closer to Darius.",
      _state->getInteraction("talked to darius"),
      _state->getInteraction("gem used on pedistal"), getNPC()));

  _actions.push_back(std::make_unique<Use>(
      "use vase on darius",
      "Darius takes the vase and places it beside his throne. He holds out a "
      "golden chalice for you to take as a reward.",
      "The guards block you from approaching.",
      _state->getInteraction("vase used on darius"),
      _state->getInteraction("gem used on pedistal"),
      allItems->getItem("Darius vase"), player, true));

  _actions.push_back(std::make_unique<Pickup>(
      "pickup chalice", "You take the chalice.",
      "The chalice is already taken.", _state->getInteraction("take chalice"),
      _state->getInteraction("vase used on darius"),
      allItems->getItem("Chalice"), player, &_inventory));

  _actions.push_back(std::make_unique<Pickup>(
      "pickup chariot", "You take the chariot. It resonates with time energy.",
      "The chariot is already taken.", _state->getInteraction("take chariot"),
      _state->getInteraction("talked to darius"), allItems->getItem("Chariot"),
      player, &_inventory));
}

//-----------------------------------------
// EgyptRoom

EgyptRoom::EgyptRoom()
    : PuzzleRoom(
          new EgyptState(),
          Puzzle("Voiceless it cries, wingless flutters, toothless "
                 "bites, mouthless mutters. What am I?",
                 "wind", "The sphinx stares at you in mild disaponitment",
                 "The sphinx shines a glowing white light and vanashes "
                 "leaving the Gods Scripture in its place")) {
  setPuzzleInteraction(_state->getInteraction("riddle solved"));
  addItem("Gods Scripture", "A glowing white paper with ancient scripture.");
  addItem(
      "Darius vase",
      "A vase with the name Darius inscribed on it. It "
      "seems to be from the persian empire. It describes great battles won.");
}

std::string EgyptRoom::getName() const { return "Egypt"; }

int EgyptRoom::getMinPower() const { return 3; }

std::string EgyptRoom::getMapName() const { return "EGY"; }

void EgyptRoom::generateActions(Inventory* allItems, Player* player) {
  _actions.push_back(std::make_unique<Pickup>(
      "pickup vase", "You take the vase.", "You cannot pick up the vase.",
      _state->getInteraction("vase taken"), nullptr,
      allItems->getItem("Darius vase"), player, &_inventory));

  _actions.push_back(std::make_unique<Pickup>(
      "pickup scripture", "You take the scripture.",
      "You cannot pick up the vase.", _state->getInteraction("scripture taken"),
      _state->getInteraction("riddle solved"),
      allItems->getItem("Gods Scripture"), player, &_inventory));
}

//-----------------------------------------
// RomeRoom

RomeRoom::RomeRoom() : Room(new RomeState()) {
  addItem("Empty wine bottle",
          "An empty bottle of wine with a single drop remaining.");
  addItem("SkeletonKey", "Can open any lock.");
}

std::string RomeRoom::getName() const { return "Rome"; }

int RomeRoom::getMinPower() const { return 2; }

std::string RomeRoom::getMapName() const { return "ROM"; }

void RomeRoom::generateActions(Inventory* allItems, Player* player) {
  _actions.push_back(std::make_unique<Pickup>(
      "pickup bottle", "You take the wine bottle. There is but a drop within.",
      "The wine bottle is already taken.",
      _state->getInteraction("wine bottle taken"), nullptr,
      allItems->getItem("Empty wine bottle"), player, &_inventory));

  _actions.push_back(std::make_unique<Use>(
      "use zen stone on jailer",
      "The jailer falls into a deep trance, dropping the key to the floor.",
      "You dont have the zen stone.", _state->getInteraction("zen stone used"),
      nullptr, allItems->getItem("Zen Stone"), player, true));

  _actions.push_back(std::make_unique<Pickup>(
      "pickup key", "You take the key.",
      "You cant, the jailor grips it tight, or you already have it.",
      _state->getInteraction("key taken"),
      _state->getInteraction("zen stone used"),
      allItems->getItem("SkeletonKey"), player, &_inventory));

  _actions.push_back(std::make_unique<Use>(
      "use lighter on plant", "The plant burns to a crip, dropping the bottle.",
      "You can't reach the plant.", _state->getInteraction("plant burnt"),
      _state->getInteraction("door opened"), allItems->getItem("Lighter"),
      player, false));

  _actions.push_back(std::make_unique<Use>(
      "use sword on vines", "The vines are cut away, revealing the door.",
      "You cant cut the vines.", _state->getInteraction("cut vines"), nullptr,
      allItems->getItem("Sword"), player, false));

  _actions.push_back(std::make_unique<Use>(
      "use key on door", "The door swings open, letting you inside.",
      "You can't, either you dont have a key, or the vines block the lock.",
      _state->getInteraction("door opened"), nullptr,
      allItems->getItem("SkeletonKey"), player, false));
}

//-----------------------------------------
// JapanRoom

JapanRoom::JapanRoom() : Room(new JapanState()) {
  addItem("Zen Stone",
          "A stone with a calming aura. Holding it almost puts you asleep.");
  addItem("Emporer's Gem",
          "A gem that shines with the power of the emporer. May cure all "
          "sickness.");
}

std::string JapanRoom::getName() const { return "Edo Japan"; }

int JapanRoom::getMinPower() const { return 1; }

std::string JapanRoom::getMapName() const { return "JPN"; }

void JapanRoom::generateActions(Inventory* allItems, Player* player) {
  _actions.push_back(std::make_unique<Pickup>(
      "pickup stone", "You take the Zen Stone, it almost puts you to sleep.",
      "You cannot pick up the stone.", _state->getInteraction("stone taken"),
      nullptr, allItems->getItem("Zen Stone"), player, &_inventory));

  _actions.push_back(std::make_unique<Use>(
      "use lighter on shoji",
      "The wall burns away to reveal a cubby. There is a gem inside.",
      "You cannot burn the wall.", _state->getInteraction("wall burnt"),
      nullptr, allItems->getItem("Lighter"), player, false));

  _actions.push_back(std::make_unique<Pickup>(
      "pickup gem",
      "You pickup the emporer's gem, you feel healther holding it.",
      "You cant take the gem.", _state->getInteraction("gem taken"),
      _state->getInteraction("wall burnt"), allItems->getItem("Emporer's Gem"),
      player, &_inventory));
}

//-----------------------------------------
// RenaissanceRoom

RenaissanceRoom::RenaissanceRoom()
    : NpcRoom(new RenaissanceState(), NPC("Lord")) {}

std::string RenaissanceRoom::getName() const { return "Renaissance"; }

int RenaissanceRoom::getMinPower() const { return 3; }

std::string RenaissanceRoom::getMapName() const { return "REN"; }

void RenaissanceRoom::generateActions(Inventory* allItems, Player* player) {
  _actions.push_back(std::make_unique<Use>(
      "use chalice on table",
      "You place the chalice on the table. The lord a little happier.",
      "You dont have the chalice.", _state->getInteraction("chalice placed"),
      nullptr, allItems->getItem("Chalice"), player, true));

  _actions.push_back(std::make_unique<Use>(
      "use wine on chalice",
      "You pour the wine into the chalice. The lord looks at you with a smile.",
      "The chalice is not on the table.", _state->getInteraction("wine poured"),
      _state->getInteraction("chalice placed"), allItems->getItem("Wine"),
      player, true));

  _actions.push_back(std::make_unique<Talk>(
      "talk to lord",
      "The lord thanks you for the wine. He mutters something about a "
      "punchline to an old joke he just can't remember, but you hear him "
      "mutter something about the wind.",
      "The lord is busy eating.", _state->getInteraction("talked to lord"),
      _state->getInteraction("wine poured"), getNPC()));
}

//-----------------------------------------
// USARoom

USARoom::USARoom()
    : PuzzleRoom(new USAState(),
                 Puzzle("A safe requireing a three, two digit codes XX-XX-XX",
                        "32-72-94", "The Door doesnt budge.",
                        "The door swings open to reveal a Film reel.")) {
  setPuzzleInteraction(_state->getInteraction("safe unlocked"));
  addItem("Film reel",
          "A film reel with the words 'Roaring Twenties' on it. The film reel "
          "is glowing with time energy.");
  addItem("Note", "An encrypted note with an scrambled mess written on it.");
}

std::string USARoom::getName() const { return "Roaring Twenties"; }

int USARoom::getMinPower() const { return 2; }

std::string USARoom::getMapName() const { return "USA"; }

void USARoom::generateActions(Inventory* allItems, Player* player) {
  _actions.push_back(std::make_unique<Pickup>(
      "pickup note", "You take the note.", "You cannot take the note.",
      _state->getInteraction("note taken"), nullptr, allItems->getItem("Note"),
      player, &_inventory));

  _actions.push_back(std::make_unique<Pickup>(
      "pickup film reel", "You take the film reel.",
      "You cannot find a film reel.", _state->getInteraction("film reel taken"),
      _state->getInteraction("safe unlocked"), allItems->getItem("Film reel"),
      player, &_inventory));
}

//-----------------------------------------
// WW2Room

WW2Room::WW2Room() : Room(new WW2State()) {
  addItem("Lighter",
          "An old lighter with the words 'For Luck' inscribed on it.");
}

std::string WW2Room::getName() const { return "World War II"; }

int WW2Room::getMinPower() const { return 1; }

std::string WW2Room::getMapName() const { return "WW2"; }

void WW2Room::generateActions(Inventory* allItems, Player* player) {
  _actions.push_back(std::make_unique<Pickup>(
      "pickup lighter", "You take the lighter.", "You cant take the lighter.",
      _state->getInteraction("lighter taken"), nullptr,
      allItems->getItem("Lighter"), player, &_inventory));

  _actions.push_back(std::make_unique<Use>(
      "use sword on poster",
      "You slash the poster in half to reveal a shelf. A lighter sits inside.",
      "", _state->getInteraction("poster cut"), nullptr,
      allItems->getItem("Sword"), player, false));

  _actions.push_back(std::make_unique<Use>(
      "use key on enigma machine",
      "The enigma machine unlocks, you may now use it to decode messages.",
      "You dont have the key.",
      _state->getInteraction("enigma machine unlocked"), nullptr,
      allItems->getItem("SkeletonKey"), player, false));

  _actions.push_back(std::make_unique<Use>(
      "use note on enigma machine",
      "The enigma machine starts to decode the note. It reads '32-72-94'.",
      "The enigma machine is locked.", _state->getInteraction("note decoded"),
      nullptr, allItems->getItem("Note"), player, false));
}

//-----------------------------------------
// PresentRoom

PresentRoom::PresentRoom() : Room(new PresentState()) {}

std::string PresentRoom::getName() const { return "Present Day"; }

int PresentRoom::getMinPower() const { return 4; }

std::string PresentRoom::getMapName() const { return "PRE"; }

void PresentRoom::generateActions(Inventory* allItems, Player* player) {}

// -----------------------------------------
// FutureRoom

FutureRoom::FutureRoom() : Room(new FutureState()) {
  addItem("Wine", "A full bottle of wine.");
  addItem("Quantum Data Cube",
          "A cube encryped with the words of the gods. The "
          "cube is resonating with time energy.");
}

std::string FutureRoom::getName() const { return "The Future"; }

int FutureRoom::getMinPower() const { return 3; }

std::string FutureRoom::getMapName() const { return "FUT"; }

void FutureRoom::generateActions(Inventory* allItems, Player* player) {
  _actions.push_back(std::make_unique<Use>(
      "use bottle on replicator",
      "The replicator hums to life, filling the wine bottle. It sits within "
      "the slot",
      "You cant fill the wine.", _state->getInteraction("wine used replicator"),
      nullptr, allItems->getItem("Empty wine bottle"), player, true));

  _actions.push_back(std::make_unique<Pickup>(
      "pickup wine", "You take the wine.", "You cannot take the wine.",
      _state->getInteraction("taken full wine"),
      _state->getInteraction("wine used replicator"), allItems->getItem("Wine"),
      player, &_inventory));

  _actions.push_back(std::make_unique<Use>(
      "use scripture on scanner",
      "The screen says 'Scan complete'. A cube is ejected from the "
      "machine.",
      "You cant.", _state->getInteraction("scan gods scripture"), nullptr,
      allItems->getItem("Gods Scripture"), player, true));

  _actions.push_back(std::make_unique<Pickup>(
      "pickup cube",
      "You take the Quantum Data Cube. It resonates with time energy",
      "there is no cube.", _state->getInteraction("taken data cube"),
      _state->getInteraction("scan gods scripture"),
      allItems->getItem("Quantum Data Cube"), player, &_inventory));
}
