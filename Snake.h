#ifndef SNAKE_H
#define SNAKE_H

#include <chrono>
#include <thread>
#include <iostream>
#include "Object.h"

enum class Direction
{
    STOP, UP, DOWN, LEFT, RIGHT
};
class Snake : public Object
{
public:
    Snake(int x_, int y_);
    std::vector<Position> getPositionList() const
    {
        return _positionList;
    }
    Position getPosition(int i) const
    {
        return _positionList[i];
    }

    int  getLength() const
    {
        return _positionList.size();
    }
    void eat()
    {
        Position pos = {1,1};
        _positionList.push_back(pos);
    }
    
    Position getSnakeHeadPosition() const
    {
        return _positionList[0];
    }
    /*
    std::vector<Position> headPositionList() const
    {
        Position pos = _positionList[0];
        return headPositionList().push_back(pos);
    }
    */
    void changeDir(const Direction &direction_);
    void SnakeHeadUpdate();
    void snakeBodyUpdate();
    
private:
    Direction               _direction;

};

#endif
