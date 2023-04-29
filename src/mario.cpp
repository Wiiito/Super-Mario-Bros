#include "../include/mario.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

extern int HOUSE_SIZE;
extern Clock elapsedTime;

// ---- Start Public ----

Mario::Mario() {
  this->velocity = Vector2f(0.f, 0.f);
  this->acceleration = Vector2f(1.f, 1.f);

  this->position = Vector2f(0.f, 0.f);
  this->hitbox.setFillColor(Color(255, 127, 127));
  this->hitbox.setSize(Vector2f(float(HOUSE_SIZE) * 2, float(HOUSE_SIZE) * 2));
}

Mario::~Mario() {}

void Mario::move() {
  if (Keyboard::isKeyPressed(Keyboard::A)) {
    velocity.x -= acceleration.x * elapsedTime.getElapsedTime().asSeconds();
  }
  if (Keyboard::isKeyPressed(Keyboard::D)) {
    velocity.x += acceleration.x * elapsedTime.getElapsedTime().asSeconds();
  }
  if (!Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D)) {
    if (velocity.x > 0) {
      velocity.x =
          std::max(0.f, velocity.x - acceleration.x * elapsedTime.getElapsedTime().asSeconds());
    }
    if (velocity.x < 0) {
      velocity.x = std::min(float(HOUSE_SIZE * 2),
                            velocity.x + acceleration.x * elapsedTime.getElapsedTime().asSeconds());
    }
  }
}

void Mario::update() {
  /*
    @return void

    Updates Mario state
    - Handle mario movement
  */

  move();

  this->position += this->velocity;
  this->hitbox.setPosition(this->position);
}

void Mario::render(RenderWindow *window) { window->draw(this->hitbox); }

// ---- End Public ----