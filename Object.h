#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

struct Position
{
    int _x;
    int _y;
};

class Object
{
public:
    virtual std::vector<Position> getPositionList() const = 0;
protected:
    std::vector<Position> _positionList;
};

#endif
