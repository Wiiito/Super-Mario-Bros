#include "../include/mario.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

extern int HOUSE_SIZE;
extern Clock elapsedTime;
extern Texture *gameTexture;

// ---- Start Public ----

// Constructors / Descontructors

Mario::Mario() {
  this->velocity = Vector2f(0.f, 0.f);
  this->acceleration = Vector2f(0.1f, 0.1f);

  this->position = Vector2f(0.f, 0.f);
  this->hitbox.setSize(Vector2f(float(HOUSE_SIZE) * 3, float(HOUSE_SIZE) * 3));
  this->hitbox.setTexture(gameTexture);
  this->hitbox.setTextureRect(IntRect(0, HOUSE_SIZE, HOUSE_SIZE, HOUSE_SIZE));
  // this->hitbox.setFillColor(Color(255, 127, 127));

  this->facingRight = true;
  this->isJumping = false;

  this->animations.push_back(Animation(idle, 1, 0.f, Vector2i(0, 0)));
  this->animations.push_back(Animation(moving, 3, 0.12f, Vector2i(0, 1)));
  this->animations.push_back(Animation(jumping, 3, 0.f, Vector2i(0, 2)));

  this->currentAnimation = &animations[idle];
}

Mario::~Mario() {}

// Public Functions

void Mario::move() {
  /*
    @reutrn void
    Handle mario controls
    - if A or D pressed, add acceleartion to velocity
      -If moving on another directin, stops faster
      -If none key is pressed, stops player
      - Sets facingRight variable

    - Applies gravity
    - Checks if on ground
  */

  if (Keyboard::isKeyPressed(Keyboard::A)) {
    if (this->velocity.x < 0) {
      this->velocity.x -= this->acceleration.x * elapsedTime.getElapsedTime().asSeconds();
    } else {
      this->velocity.x -= this->acceleration.x * 2 * elapsedTime.getElapsedTime().asSeconds();
    }

    // Setting face right var
    this->facingRight = false;
  }

  if (Keyboard::isKeyPressed(Keyboard::D)) {
    if (this->velocity.x > 0) {
      this->velocity.x += this->acceleration.x * elapsedTime.getElapsedTime().asSeconds();
    } else {
      this->velocity.x += this->acceleration.x * 2 * elapsedTime.getElapsedTime().asSeconds();
    }

    // Setting face right var
    this->facingRight = true;
  }

  if (!Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D)) {
    if (this->velocity.x > 0) {
      this->velocity.x = std::max(
          0.f, this->velocity.x - this->acceleration.x * elapsedTime.getElapsedTime().asSeconds());
    }

    if (this->velocity.x < 0) {
      this->velocity.x =
          std::min(float(1), this->velocity.x +
                                 this->acceleration.x * elapsedTime.getElapsedTime().asSeconds());
    }
  }

  // Appling gravity
  if (!this->isJumping && !map.doesColide(this->position)) {
    this->velocity.y = std::min(
        float(0.2), velocity.y + HOUSE_SIZE / 4 * elapsedTime.getElapsedTime().asSeconds());
  }

  // Ground check
  if (map.doesColide(this->position)) {
    this->velocity.y = 0;
    this->position.y = int(this->position.y / (HOUSE_SIZE * 3)) * HOUSE_SIZE * 3;
  }

  // Setting animation
  currentAnimation = &animations[idle];

  if (velocity.x != 0) {
    currentAnimation = &animations[moving];
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

void Mario::render(RenderWindow *window) {
  /*
    @return void
    Handles mario rendering
    - Change facing direction
    - Change animation
    - Renders map
    - Renders on screen
  */

  this->map.render(window);

  // Reads the texture from behind if facingRight is false
  hitbox.setTextureRect(
      IntRect(currentAnimation->getFramePosition().x * HOUSE_SIZE + HOUSE_SIZE * !this->facingRight,
              currentAnimation->getFramePosition().y * HOUSE_SIZE,
              HOUSE_SIZE * (2 * this->facingRight - 1), HOUSE_SIZE));

  window->draw(this->hitbox);
}

// ---- End Public ----