
#include "RoomStateVariants.h"

#include <string>

//-----------------------------------------
// TimeMachineState

std::string TimeMachineState::getDescription() const {
  return "You are in the time machine. It is made with many tubes and gizmos "
         "that you have designed.";
}

TimeMachineState::TimeMachineState() : RoomState() {
  addInteraction("slot1 filled", "The first slot is empty.",
                 "The chairot sits within the slot.");

  addInteraction("slot2 filled", "The second slot is empty.",
                 "The Film reel sits within the slot.");

  addInteraction("slot3 filled", "The third slot is empty.",
                 "The Quantum data cube fills the third slot.");
}

//-----------------------------------------
// PersiaState

std::string PersiaState::getDescription() const {
  return "You enter the Palace of Darius the Great. It is well furnished. "
         "Darius sits upon his throne.";
}

PersiaState::PersiaState() : RoomState() {
  addInteraction("sword picked up",
                 "There is a sword laying on the ground near the entrance.",
                 "");
  addInteraction("gem used on pedistal",
                 "Darius looks sick the guards are extra careful and dont seem "
                 "willing to let you approach. \nThere is a pedistal nearby "
                 "with a slot for a small gem.",
                 "Daruis looks healthy. The gaurds seem more "
                 "relaxed. The pedistal is filled with the Emporer's Gem.");

  addInteraction("talked to darius", "", "");

  addInteraction("take chariot", "", "");

  addInteraction("take chalice", "", "");

  addInteraction("vase used on darius", "",
                 "The vase is sitting beside the throne.");
}

//-----------------------------------------
// EgyptState

std::string EgyptState::getDescription() const {
  return "You are in an Ejyptian tomb.";
}

EgyptState::EgyptState() : RoomState() {
  addInteraction("vase taken", "There is a vase next to you on the ground.",
                 "");

  addInteraction("scripture taken", "", "");

  addInteraction(
      "riddle solved",
      "There is a sphinx in the room across from the "
      "entrance. It is staring at you. It has a riddle for you. (solve riddle)",
      "The pedistal where the sphinx sat lacks its presence.");
}

//-----------------------------------------
// RomeState

std::string RomeState::getDescription() const {
  return "You are in Rome. You enter into a dank and dark jail.";
}

RomeState::RomeState() : RoomState() {
  addInteraction(
      "zen stone used",
      "The jailer is sitting on a stool half asleep clutching a key.",
      "The jailer is fully asleep");
  addInteraction("key taken", "", "");

  addInteraction(
      "cut vines", "There are vines covering one of the jail doors.",
      "The vines have been cut from the door and are laying on the ground.");

  addInteraction("plant burnt",
                 "You can see a plant inbetween the bars, it is cluching a "
                 "wine bottle. The plant is covered in wine.",
                 "the plant is a burnt husk.");

  addInteraction("door opened", "", "The door is wide open.");

  addInteraction("wine bottle taken", "", "");
}

//-----------------------------------------
// JapanState

std::string JapanState::getDescription() const {
  return "You arrive in a serene Edo-era Japanese temple, where the "
         "tranquility of nature intertwines with the spiritual essence "
         "of "
         "ancient traditions.";
}

JapanState::JapanState() : RoomState() {
  addInteraction(
      "stone taken", "A calming bonzai tree sits in the center of the room.",
      "A bonzai tree sits in the center of the room. A stone is missing.");

  addInteraction("wall burnt",
                 "there is an out of place square panel on the wall in the "
                 "style of a shoji, it is made of paper.",
                 "The pannel has been burnt");

  addInteraction("gem taken", "", "");
}

//-----------------------------------------
// RenaissanceState

std::string RenaissanceState::getDescription() const {
  return "You are in a mannor. There is a lord sitting at the table. The walls "
         "are adorned with paintings of "
         "the renaissance. The table is set for a feast.";
}

RenaissanceState::RenaissanceState() : RoomState() {
  addInteraction("talked to lord", "",
                 "The lord has given you a clue for a riddle.");

  addInteraction(
      "chalice placed",
      "There is a cup missing from infront of the lord on the table.",
      "The chalice is placed infront of the lord.");

  addInteraction("wine poured", "The lord looks very sad. :(",
                 "The lord wishes to speak with you.");
}

//-----------------------------------------
// USAState

std::string USAState::getDescription() const {
  return "You arive in a empty suberban home.";
}

USAState::USAState() : RoomState() {
  addInteraction("note taken", "There is a note on the table.",
                 "The note has been taken.");

  addInteraction("safe unlocked",
                 "There is a safe in one of the rooms. The door is locked.",
                 "There is a safe in one of the rooms. the door is open.");

  addInteraction("film reel taken", "", "");
}

//-----------------------------------------
// WW2State

std::string WW2State::getDescription() const {
  return "You arive in a empty bunker. It looks like it hasnt been used, yet.";
}

WW2State::WW2State() : RoomState() {
  addInteraction("poster cut", "There is a propaganda poster on the wall.",
                 "The poster has been cut, revealing a shelf.");

  addInteraction("lighter taken", "", "");

  addInteraction("enigma machine unlocked",
                 "There is a strange machine in the "
                 "corner of the room. It has a lock holding a cover preventing "
                 "you from using it.",
                 "The enigma machine in the corner is unlocked.");

  addInteraction("note decoded", "", "");
}

//-----------------------------------------
// PresentState

std::string PresentState::getDescription() const { return ""; }

PresentState::PresentState() : RoomState() {}

//-----------------------------------------
// FutureState

std::string FutureState::getDescription() const {
  return "You are in a futuristic science lab. There are 2 machines that stand "
         "out to you. A replicator sits in the corner of the room. A screen "
         "and machine of unknown function.";
}

FutureState::FutureState() : RoomState() {
  addInteraction(
      "wine used replicator",
      "A note on the replicatior says it can make any liquid from just a drop.",
      "The replicator has powered down");

  addInteraction("taken full wine", "", "");

  addInteraction("scan gods scripture", "The screen says 'Scan powerful words'",
                 "The screen says 'Scan complete'");

  addInteraction("taken data cube", "", "");
}
