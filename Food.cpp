#include "Food.h"

Food::Food(int x_, int y_)
{
    _foodX = x_;
    _foodY = y_;
}


Food::Food()
    :_foodX{ 2 },
     _foodY{ 2 }
{}


void Food::refresh(int x_, int y_)
{
    _foodX = x_;
    _foodY = y_;
}





