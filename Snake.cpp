#include "Snake.h"

Snake::Snake(int x_, int y_)
    : _direction{ Direction::STOP }
{
    Position pos = {x_,y_};
    _positionList.push_back(pos);
}

void Snake::changeDir(const Direction &direction_)
{
    _direction = direction_;
}

void Snake::SnakeHeadUpdate()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(170));
    switch (_direction)
    {
    case(Direction::LEFT):
        _positionList[0]._x--;
        break;
    case(Direction::RIGHT):
        _positionList[0]._x++;
        break;
    case(Direction::UP):
        _positionList[0]._y--;
        break;
    case(Direction::DOWN):
        _positionList[0]._y++;
        break;
    case(Direction::STOP):
        break;
    }
}

void Snake::snakeBodyUpdate()
{
    if (!getPositionList().empty())
    {
        for (int i = getLength() - 1; i > 0 ; i--)
        {
            _positionList[i] = _positionList[i-1];
        }
    }
}
