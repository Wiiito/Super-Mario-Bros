#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

enum Cell { none, floor, brick };

using namespace std;

class Map {
 private:
  vector<vector<Cell>> map;

 public:
  // Constructor - Deconstructor
  Map();
  ~Map();

  // Functions
  bool doesColide(Vector2f pos);

  void render(RenderWindow *window, Texture *texture);
};
