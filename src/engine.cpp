#include "../include/engine.hpp"

#include <iostream>

#include "../include/globals.hpp"

// ---- Start Private ----

// Init
void Engine::initVariables() {
  /*
     @return void

     Initialize every initial game configuration / variables
   */

  this->window = nullptr;
  this->gameTexture = nullptr;
}

void Engine::initWindow() {
  /*
    @return void

    Initialize the window
  */

  this->resolution.width = 256 * 3;
  this->resolution.height = 224 * 3;
  this->window = new RenderWindow(resolution, "Super Mario Bros", Style::Titlebar);

  this->gameTexture = new Texture;
  this->gameTexture->loadFromFile("assets/texture.png");
}

void Engine::poolEvents() {
  /*
    @return void
    Pool window events into ev
  */

  while (this->window->pollEvent(this->ev)) {
    switch (this->ev.type) {
      case Event::Closed:
        window->close();
        break;
      case Event::KeyPressed:
        if (this->ev.key.code == Keyboard::Escape) {
          window->close();
        }
        break;
    }
  }
}

// ---- End Private ----

// ---- Start Public ----

// Constructor / Destructor

Engine::Engine() {
  initVariables();
  initWindow();
}

Engine::~Engine() {}

// Game Functions
void Engine::update() {
  /*
    @return void
    Function responsible for updating game state / variables
  */

  poolEvents();

  this->mario.update();
  elapsedTime.restart();
}

void Engine::render() {
  /*
    @return void
    Function responsible to render all game objects in this order
  */

  this->window->clear();

  this->mario.render(this->window, this->gameTexture);

  this->window->display();
}

// Get Functions

bool Engine::getIsWindowOpen() { return this->window->isOpen(); }

// ---- End Public ----