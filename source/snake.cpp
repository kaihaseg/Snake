#include "model.h"

Snake::Snake()
{
    segments.push_back({GRID_WIDTH / 2, GRID_HEIGHT / 2});
    dir = Dir::Right;
}

void Snake::move()
{
    SnakeSegment newHead = segments[0];

    switch(dir)
    {
        case Dir::Up:    newHead.y--; break;
        case Dir::Down:  newHead.y++; break;
        case Dir::Left:  newHead.x--; break;
        case Dir::Right: newHead.x++; break;
    }

    segments.insert(segments.begin(), newHead);
    segments.pop_back();
}

void Snake::grow()
{
    SnakeSegment tail = segments.back();
    segments.push_back(tail);
}

bool Snake::checkCollision() const
{
    if (segments[0].x < 0 || segments[0].x >= GRID_WIDTH ||
        segments[0].y < 0 || segments[0].y >= GRID_HEIGHT) { return true; }

    for (size_t i = 1; i < segments.size(); ++i)
    {
        if (segments[0].x == segments[i].x && segments[0].y == segments[i].y) { return true; }
    }

    return false;
}
