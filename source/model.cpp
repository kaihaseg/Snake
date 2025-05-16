#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#inlcude "model.h"

using namespace std;

class Point
{
public:
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    bool operator == (const Point &p) const
    {
        return x == p.x && y == p.y;
    }
};

class Snake
{
private:
    vector<Point> body;
    char direction;

public:
    Snake(int startX, int startY)
    {
        body.push_back(Point(startX, startY));
        direction = 'R';
    }

    void changeDirection(char newDirection)
    {
        if ((direction == 'L' && newDirection != 'R') ||
            (direction == 'R' && newDirection != 'L') ||
            (direction == 'U' && newDirection != 'D') ||
            (direction == 'D' && newDirection != 'U'))
        {
            direction = newDirection;
        }
    }

    void move()
    {
        Point newHead = body[0];

        switch (direction)
        {
            case 'L': newHead.x--; break;
            case 'R': newHead.x++; break;
            case 'U': newHead.y--; break;
            case 'D': newHead.y++; break;
        }

        body.insert(body.begin(), newHead);
        body.pop_back();
    }

    void grow()
    {
        body.push_back(body.back());
    }

    const vector<Point>& getBody() const
    {
        return body;
    }

    Point getHead() const
    {
        return body[0];
    }


};

class Game
{
    private:
        const int width, height;
        Snake snake;
        Point food;
        bool gameOver;

        void generateFood()
        {
            srand(time(nullptr));
            food.x = rand() % width;
            food.y = rand() % height;
        }

    public:
        void input()
        {
            if(khbit()){
                char key = getch();
                switch(key)
                {
                    case 'w': snake.changeDirection('U'); break;
                    case 's': snake.changeDirection('D'); break;
                    case 'a': snake.changeDirection('L'); break;
                    case 'd': snake.changeDirection('R'); break;
                }
            }
        }

        void logic()
        {
            snake.move();
            Point head = snake.getHead();

            if (head.x < 0 || head.x >= width || head.y < 0 || head.y >= height) { gameOver = true; }

            for (int i = 1; i < snake.getBody().size(); ++i)
            {
                if (head == snake.getBody()[i]) { gameOver = true; }
            }

            if (head == food)
            {
                snake.grow();
                generateFood();
            }
        }

        bool isGameOver() const { return gameOver; }
};



