#include "../include/mario.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

extern int HOUSE_SIZE;
extern Clock elapsedTime;

// ---- Start Public ----

// Constructors / Descontructors

Mario::Mario() {
  this->velocity = Vector2f(0.f, 0.f);
  this->acceleration = Vector2f(1.f, 1.f);

  this->position = Vector2f(0.f, 0.f);
  this->hitbox.setFillColor(Color(255, 127, 127));
  this->hitbox.setSize(Vector2f(float(HOUSE_SIZE) * 3, float(HOUSE_SIZE) * 3));

  this->jumping = false;
}

Mario::~Mario() {}

// Public Functions

void Mario::move() {
  /*
    @reutrn void
    Handle mario controls
    - if A or D pressed, add acceleartion to velocity, else, remove it from velocity

    - Applies gravity
  */

  if (Keyboard::isKeyPressed(Keyboard::A)) {
    if (velocity.x < 0) {
      velocity.x -= acceleration.x * elapsedTime.getElapsedTime().asSeconds();
    } else {
      velocity.x -= acceleration.x * 2 * elapsedTime.getElapsedTime().asSeconds();
    }
  }
  if (Keyboard::isKeyPressed(Keyboard::D)) {
    if (velocity.x > 0) {
      velocity.x += acceleration.x * elapsedTime.getElapsedTime().asSeconds();
    } else {
      velocity.x += acceleration.x * 2 * elapsedTime.getElapsedTime().asSeconds();
    }
  }
  if (!Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D)) {
    if (velocity.x > 0) {
      velocity.x =
          std::max(0.f, velocity.x - acceleration.x * elapsedTime.getElapsedTime().asSeconds());
    }
    if (velocity.x < 0) {
      velocity.x = std::min(float(HOUSE_SIZE),
                            velocity.x + acceleration.x * elapsedTime.getElapsedTime().asSeconds());
    }
  }

  // Appling gravity
  if (!this->jumping && !map.doesColide(this->position)) {
    this->velocity.y = std::min(
        float(HOUSE_SIZE), velocity.y + HOUSE_SIZE / 4 * elapsedTime.getElapsedTime().asSeconds());
  }

  // Checando se está no chão
  if (map.doesColide(this->position)) {
    this->velocity.y = 0;
    this->position.y = int(position.y / (HOUSE_SIZE * 3)) * HOUSE_SIZE * 3;
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

void Mario::render(RenderWindow *window, Texture *gameTexture) {
  this->map.render(window, gameTexture);

  window->draw(this->hitbox);
}

// ---- End Public ----