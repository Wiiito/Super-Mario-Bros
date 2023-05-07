#include "../include/map.hpp"

#include <iostream>

extern int HOUSE_SIZE;
extern Texture *gameTexture;

// Constructor / Descontructor

Map::Map() {
  for (int i = 0; i < 16; i++) {
    std::vector<Cell> yAxis(14);
    map.push_back(yAxis);
  }

  for (int x = 0; x < 16; x++) {
    for (int y = 12; y < 14; y++) {
      map[x][y] = floor;
    }
  }
}

Map::~Map() {}

// Functions

void Map::render(RenderWindow *window) {
  /*
    @return void
    Renders the map array
  */

  RectangleShape block;
  block.setTexture(gameTexture);
  block.setSize(Vector2f(HOUSE_SIZE * 3, HOUSE_SIZE * 3));
  for (int x = 0; x < map.size(); x++) {
    for (int y = 0; y < map[x].size(); y++) {
      block.setTextureRect(IntRect(map[x][y] * HOUSE_SIZE, 0, HOUSE_SIZE, HOUSE_SIZE));
      block.setPosition(x * HOUSE_SIZE * 3, y * HOUSE_SIZE * 3);
      window->draw(block);
    }
  }
}

bool Map::doesColide(Vector2f pos) {
  /*
    @return bool
    Check for collision
  */

  pos.x = int(pos.x / (HOUSE_SIZE * 3));
  pos.y = int(pos.y / (HOUSE_SIZE * 3));

  if (!map[pos.x][pos.y + 1]) {
    return false;
  }

  return true;
}