#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Mario {
 private:
  Vector2f position;
  RectangleShape hitbox;

 public:
  Mario();
  ~Mario();

  void update();
  void render(RenderWindow *window);
};
