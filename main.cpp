#include <iostream>

#include "include/engine.hpp"

int main() {
  Engine game;
  while (game.getIsWindowOpen()) {
    game.update();
    game.render();
  }
}