#include <SFML/Graphics.hpp>
#include "snake.h"
#include "parts.h"
#include "dir.h"

const int WIDTH = 800;
const int HEIGHT = 600;
const int GRID_SIZE = 20;
const int GRID_WIDTH = 40;
const int GRID_HEIGHT = 30;

class Game
{
    sf::RenderWindow window;
    Snake snake;
    Food food;
    float baseDelay = 0.1f;
    float currentDelay;
    int score = 0;
    void processInput();
    void update();
    void render();
    void drawScore();

public:
    Game();
    void run();
};

