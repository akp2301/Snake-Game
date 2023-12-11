#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <ctime>
#include <cstdlib>
#include "Object.h"
#include <iostream>

class Obstacle : public Object
{
public:
    Obstacle(int boardHeight_, int boardWidth_);

    std::vector<Position> getPositionList() const
    {
        return _positionList;
    }

    int getBoardHeight()
    {
        return _boardHeight;
    }

    int getBoardWidth()
    {
        return _boardWidth;
    }

private:
    int                    _boardHeight;
    int                    _boardWidth;
};

#endif
