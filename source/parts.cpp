#include "parts.h"
#include "model.h"
#include <random>

Food::Food() : respawn();

void Food::respawn()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> disX(0, GRID_WIDTH - 1);
    std::uniform_int_distribution<> disY(0, GRID_HEIGHT - 1);

    x = disX(gen);
    y = disY(gen);
}
