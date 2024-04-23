#ifndef PUZZLE_H
#define PUZZLE_H

#include <string>

#include "Interaction.h"

class Puzzle {
 private:
  std::string _puzzleDescription;
  std::string _correctAnswer;
  std::string _failText;
  std::string _correctText;
  Interaction* _puzzleInteraction;

 public:
  Puzzle(std::string puzzleDescription, std::string correctAnswer,
         std::string failText, std::string _correctText);

  bool solvePuzzle(std::string answer);
  std::string getDescription() const;
  std::string getFailText() const;
  std::string getCorrectText() const;
  void getInteraction(Interaction* interaction);
  void setInteraction(Interaction* interaction);
  void markPuzzleInteraction();
};

#endif  // PUZZLE_H
