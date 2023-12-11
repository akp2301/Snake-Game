#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include "Snake.h"
#include "Food.h"
#include "Obstacle.h"

class Game
{
public:
    Game ();
    void play();
    bool getGameOver() { return _gameOver; };
      
private:    
    void handleInput();
    void update();
    void draw();
    bool checkCollision(const std::vector<Position> &obstacle1_, const std::vector<Position> &obstacle2_);
    bool checkCollision(const Snake &snake_, const Obstacle &obstacle_);
    bool checkSnakeSelfCollision(const Snake &snake_);
    void checkSnakeFoodCollision();
      
    Snake     _snake;
    Food      _food;
    Obstacle  _obstacle;
    bool      _gameOver;

};

#endif
