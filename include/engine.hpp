
#include <SFML/Graphics.hpp>

#include "../include/mario.hpp"

using namespace sf;

class Engine {
 private:
  // Game Variables
  RenderWindow *window;
  VideoMode resolution;
  Event ev;

  Mario mario;

  // Init game variables
  void initVariables();
  void initWindow();

  // Game Functions
  void poolEvents();

 public:
  // Constructor / Destructor
  Engine();
  ~Engine();

  // Game Update functions
  void update();
  void render();

  // get functions
  bool getIsWindowOpen();
};
