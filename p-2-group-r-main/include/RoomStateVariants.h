#ifndef STATEVARIANTS_H
#define STATEVARIANTS_H

#include <string>

#include "RoomState.h"

class TimeMachineState : public RoomState {
 public:
  std::string getDescription() const override;
  TimeMachineState();
};

class PersiaState : public RoomState {
 public:
  std::string getDescription() const override;
  PersiaState();
};

class EgyptState : public RoomState {
 public:
  std::string getDescription() const override;
  EgyptState();
};

class RomeState : public RoomState {
 public:
  std::string getDescription() const override;
  RomeState();
};

class JapanState : public RoomState {
 public:
  std::string getDescription() const override;
  JapanState();
};

class RenaissanceState : public RoomState {
 public:
  std::string getDescription() const override;
  RenaissanceState();
};

class USAState : public RoomState {
 public:
  std::string getDescription() const override;
  USAState();
};

class WW2State : public RoomState {
 public:
  std::string getDescription() const override;
  WW2State();
};

class PresentState : public RoomState {
 public:
  std::string getDescription() const override;
  PresentState();
};

class FutureState : public RoomState {
 public:
  std::string getDescription() const override;
  FutureState();
};

#endif  // STATEVARIANTS_H
