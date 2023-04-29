#include "../include/mario.hpp"

#include <SFML/Graphics.hpp>

using namespace sf;

// ---- Start Public ----

Mario::Mario() {
  position = Vector2f(0, 0);
  hitbox.setFillColor(Color(255, 127, 127));
  hitbox.setSize(Vector2f(32.f * 2, 32.f * 2));
  hitbox.setPosition(position);
}

Mario::~Mario() {}

void Mario::update() {}

void Mario::render(RenderWindow *window) { window->draw(hitbox); }

// ---- End Public ----