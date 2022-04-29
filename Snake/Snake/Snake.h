#ifndef SNAKE_H
#define SNAKE_H

#include "SFML/Graphics.hpp"
#include "Cell.h"
#include "CellType.h"
#include <deque>

class Snake
{
private:
    Cell head;
    std::deque<Cell> snakePartList; // the snake list
    
    
public:
    Snake() = default;
    Snake(Cell initPos);
    
    // when snake eat the food
    void grow();
    
    void move(Cell nextCell);
    
    // check if the snake hit itself
    bool checkCrash(Cell nextCell);
    std::deque<Cell> getSnakePartList();
    void setSnakePartList(std::deque<Cell> newSnakePartList);
    Cell getHead();
    void setHead(Cell newHead);
    ~Snake() = default;

};

#endif // SNAKE_H
