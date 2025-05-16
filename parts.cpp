int main() {
    Game game(20, 10);

    while (!game.isGameOver()) {
        game.draw();
        game.input();
        game.logic();
    }

    cout << "Game Over!" << endl;
    return 0;
}


class Game
{
private:
    const int width, height;
    Snake snake;
    Point food;
    bool gameOver;

    void generateFood() {
        srand(time(nullptr));
        food.x = rand() % width;
        food.y = rand() % height;
    }

public:
    Game(int w, int h) : width(w), height(h), snake(w / 2, h / 2), gameOver(false)
    {
        generateFood();
    }

    void draw() const {
        system("cls");

        for (int i = 0; i < width + 2; ++i) cout << "#";
        cout << endl;

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                Point current(x, y);

                if (x == 0) cout << "#";

                if (current == snake.getHead()) {
                    cout << "O";
                } else if (current == food) {
                    cout << "*";
                } else {
                    bool isBody = false;
                    for (const auto &segment : snake.getBody()) {
                        if (current == segment) {
                            cout << "o";
                            isBody = true;
                            break;
                        }
                    }
                    if (!isBody) cout << " ";
                }

                if (x == width - 1) cout << "#";
            }
            cout << endl;
        }

        for (int i = 0; i < width + 2; ++i) cout << "#";
        cout << endl;
    }

    void input()
    {
        if (_kbhit())
        {
            char key = _getch();
            switch (key)
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

        if (head.x < 0 && head.x >= width && head.y < 0 || head.y >= height)
        {
            gameOver = true;
        }
        for (size_t i = 1; i < snake.getBody().size(); ++i)
        {
            if (head == snake.getBody()[i])
            {
                gameOver = true;
            }
        }

        if (head == food)
        {
            snake.grow();
            generateFood();
        }
    }

    bool isGameOver() const
    {
        return gameOver;

    }
