
#include "Puzzle.h"

Puzzle::Puzzle(std::string puzzleDescription, std::string correctAnswer,
               std::string failText, std::string correctText)
    : _puzzleDescription(puzzleDescription),
      _correctAnswer(correctAnswer),
      _failText(failText),
      _correctText(correctText) {}

bool Puzzle::solvePuzzle(std::string answer) {
  return answer == _correctAnswer;
}

std::string Puzzle::getDescription() const { return _puzzleDescription; }

std::string Puzzle::getFailText() const { return _failText; }

std::string Puzzle::getCorrectText() const { return _correctText; }

void Puzzle::getInteraction(Interaction* interaction) {
  _puzzleInteraction = interaction;
}

void Puzzle::setInteraction(Interaction* interaction) {
  _puzzleInteraction = interaction;
}

void Puzzle::markPuzzleInteraction() {
  if (_puzzleInteraction != nullptr) {
    _puzzleInteraction->markCompleted();
  }
}
