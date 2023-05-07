#pragma once

#include <SFML/Graphics.hpp>

#include "map.hpp"

using namespace sf;

class Mario {
 private:
  Vector2f position;
  RectangleShape hitbox;

  Map map;

  Vector2f velocity;
  Vector2f acceleration;

  bool facingRight;
  bool jumping;

 public:
  Mario();
  ~Mario();

  void move();
  void update();
  void render(RenderWindow *window);
};
