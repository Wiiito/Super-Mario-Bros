#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Mario {
 private:
  Vector2f position;
  RectangleShape hitbox;

  Vector2f velocity;
  Vector2f acceleration;

 public:
  Mario();
  ~Mario();

  void move();
  void update();
  void render(RenderWindow *window);
};
