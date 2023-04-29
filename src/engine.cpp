#include "../include/engine.hpp"

#include <iostream>

// ---- Start Private ----

// Init
void Engine::initVariables() {
  /*
     @return void

     Initialize every initial game configuration / variables
   */

  this->window = nullptr;
}

void Engine::initWindow() {
  /*
    @return void

    Initialize the window
  */

  this->resolution.width = 256 * 3;
  this->resolution.height = 224 * 3;
  window = new RenderWindow(resolution, "Super Mario Bros", Style::Titlebar);
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
}

void Engine::render() {
  /*
    @return void
    Function responsible to render all game objects in this order
  */

  this->window->clear();

  this->mario.render(this->window);

  this->window->display();
}

// Get Functions

bool Engine::getIsWindowOpen() { return this->window->isOpen(); }

// ---- End Public ----