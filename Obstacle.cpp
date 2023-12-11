#include "Obstacle.h"

Obstacle::Obstacle(int boardHeight_, int boardWidth_)
    : _boardHeight(boardHeight_)
    , _boardWidth(boardWidth_)
{
    for (int x = 0; x < _boardHeight ; ++x)
    {
        for (int y = 0; y < _boardWidth ; ++y)
        {
            if(x == 0 ||
               x == _boardHeight - 1 ||
               y == 0 ||
               y == _boardWidth - 1 )
            {
                Position pos = {y,x};
                _positionList.push_back(pos);
            }
        }
    }
}

