#include <vector>
#include "dir.h"

struct SnakeSegment
{
    int x, y;
};

class Snake
{
public:
    std::vector <SnakeSegment> segments;
    Dir dir;

    Snake();
    void move();
    void grow();
    bool checkCollision() const;
};

