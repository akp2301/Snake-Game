#include "Game.h"
#include "kbhit.h"
#include "getch.h"

Game::Game()
    : _snake(5,5)
    , _food(10,5)
    , _obstacle(20,35)
    , _gameOver(false)
{}


void Game::play()
{
    while(!getGameOver())
    {
        handleInput();
        update();
        draw();
    }
    std::cout << "Game over" << std::endl;
}


void Game::handleInput()
{
    while(kbhit())
    {
        switch(getch())
        {
        case('a'):
            _snake.changeDir(Direction::LEFT);
            break;
        case('d'):
            _snake.changeDir(Direction::RIGHT);
            break;
        case('w'):
            _snake.changeDir(Direction::UP);
            break;
        case('s'):
            _snake.changeDir(Direction::DOWN);
            break;
        default:
            break;
        }
    }
}


void Game::update() 
{
    if(checkSnakeSelfCollision(_snake))
    {
        _gameOver = true;
    }
    if(checkCollision(_snake , _obstacle))
    {
        _gameOver = true;
    }
    checkSnakeFoodCollision();
    _snake.snakeBodyUpdate();
    _snake.SnakeHeadUpdate();
}

bool Game::checkSnakeSelfCollision(const Snake &snake_)
{
    std::vector<Position> snakeHeadPositionList = {snake_.getPosition(0)};
    std::vector<Position> snakeBodyPositionList = snake_.getPositionList();
    snakeBodyPositionList.erase(snakeBodyPositionList.begin());
    return checkCollision(snakeHeadPositionList, snakeBodyPositionList);
}

bool Game::checkCollision(const Snake &snake_, const Obstacle &obstacle_)
{
    std::vector<Position> snakeHeadPositionList = {snake_.getPosition(0)};
    return checkCollision(snakeHeadPositionList,obstacle_.getPositionList());
}

bool Game::checkCollision(const std::vector<Position> &obstacle1_ , const std::vector<Position> &obstacle2_ )
{
    srand(time(0));
    bool collision ;
    for(auto &i : obstacle1_)
     {
         for(auto &j : obstacle2_)
         {
            if (i._x == j._x && i._y == j._y)
            {
                collision = true;
            }
        }
    }
    return collision;
}

void Game::checkSnakeFoodCollision()
{
    if(_snake.getPosition(0)._x == _food.posX() && _snake.getPosition(0)._y == _food.posY())
    {
        _food.refresh(rand() % (_obstacle.getBoardWidth() - 2) + 1, rand() % (_obstacle.getBoardHeight() - 2) + 1);
        _snake.eat();
    }
}


void Game::draw()
{
    system("clear");

    for (int i = 0; i < _obstacle.getBoardHeight(); ++i)
    {
        for (int j = 0; j < _obstacle.getBoardWidth(); ++j)
        {
            if (j == _food.posX() && i == _food.posY())
            {
                std::cout << "\u0E4F";//food
            }
            else if (i == 0 )
            {
                std::cout << "\u2583";//horizontal left
            }
            else if ( i == _obstacle.getBoardHeight() - 1 )
            {
                std::cout << "\u2580";//horizontal right
            }
            else if (j == 0 )
            {
                std::cout << "\u258C";//vertical left
            }
            else if ( j == _obstacle.getBoardWidth() - 1 )
            {
                std::cout << "\u2590";//vertical right
            }
            else if (j == _snake.getPosition(0)._x && i == _snake.getPosition(0)._y)
            {
                std::cout << "\u25EF";//head
            }
            else
            {
                bool flag = false;
                for(auto it : _snake.getPositionList())
                {
                    if(it._x == j && it._y == i)
                    {
                        std::cout << "\u2B24";//tail
                        flag = true;
                        break;
                    }
                }
                if(!flag)
                {
                    std::cout << " ";
                }
            }
        }
        std::cout << "\n";
    }

    std::cout <<  "Score: " << _snake.getLength()-1 << std::endl;
}
