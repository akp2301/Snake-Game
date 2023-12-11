#ifndef F00D_H
#define FOOD_H

class Food
{
public:
    Food(int x_, int y_);
    Food();
    
    int posX() const
    {
        return _foodX;
    };
    
    int posY() const
    {
        return _foodY;
    };
    
    void refresh(int x_, int y_);
    
private:
    int _foodX;
    int _foodY;
    
};

#endif
