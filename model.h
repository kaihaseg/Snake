class Point
{
    public:
        int x,y;
        bool operator;
};

class Snake
{
    private:
        vector<Point> body;
        char direction = 0;
    public:
        void changeDirection();
        void move();
        void grow();
};

class Game
{
    private:
        const int width, height;
        Snake snake;
        Point food;
        bool gameOver;
        void generateFood();

    public:
        void input();
        void logic();

};

