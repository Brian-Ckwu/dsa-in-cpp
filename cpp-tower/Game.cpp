/**
 * C++ class for a game of the Tower of Hanoi puzzle.
 *
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "Game.h"

#include <iostream>

#include "Stack.h"
#include "uiuc/Cube.h"
#include "uiuc/HSLAPixel.h"
using std::cout;
using std::endl;

// Solves the Tower of Hanoi puzzle.
// (Feel free to call "helper functions" to help you solve the puzzle.)
void Game::solve() {
  // Prints out the state of the game:
  _move(4, 0, 1);

  // @TODO -- Finish solving the game!
}

void Game::_move(int num, int from, int to) {
  if (num == 1) {
    Cube top_cube = stacks_[from].removeTop();
    stacks_[to].push_back(top_cube);
    cout << *this << endl;
    return;
  }
  _move(num - 1, from, 3 - from - to);
  _move(1, from, to);
  _move(num - 1, 3 - from - to, to);
}

// Default constructor to create the initial state:
Game::Game() {
  // Create the three empty stacks:
  for (int i = 0; i < 3; i++) {
    Stack stackOfCubes;
    stacks_.push_back(stackOfCubes);
  }

  // Create the four cubes, placing each on the [0]th stack:
  Cube blue(4, uiuc::HSLAPixel::BLUE);
  stacks_[0].push_back(blue);

  Cube orange(3, uiuc::HSLAPixel::ORANGE);
  stacks_[0].push_back(orange);

  Cube purple(2, uiuc::HSLAPixel::PURPLE);
  stacks_[0].push_back(purple);

  Cube yellow(1, uiuc::HSLAPixel::YELLOW);
  stacks_[0].push_back(yellow);
}

std::ostream& operator<<(std::ostream& os, const Game& game) {
  for (unsigned i = 0; i < game.stacks_.size(); i++) {
    os << "Stack[" << i << "]: " << game.stacks_[i];
  }
  return os;
}
