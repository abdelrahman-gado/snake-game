#include "Snake.h"

Snake::Snake(Cell initPos)
{
    head = initPos;
    head.setCellType(SNAKE_NODE);
    snakePartList.push_back(head);
}

// when the snake eat food
void Snake::grow()
{
    snakePartList.push_back(head);
}

// when moving the snake, we remove the last cell in the snake and chnage color of it to empty
// then, we make the next node to the snake is the head and change the color of it to snake_cell
// then, we put in the front of the deque        (head_cell, body_cell, body_cell, body_cell, .... )
void Snake::move(Cell nextCell)
{
    Cell tail = snakePartList.back(); 
    snakePartList.pop_back();
    
    tail.setCellType(EMPTY);
    nextCell.setCellType(SNAKE_NODE);
    head = nextCell;
    snakePartList.push_front(head);
}

// we check if the nextcell is one of the snake body cells
bool Snake::checkCrash(Cell nextCell)
{
    for (Cell cell : snakePartList)
    {
        if (cell == nextCell)
            return true;
    }
    return false;
}

std::deque<Cell> Snake::getSnakePartList()
{
    return snakePartList;
}

void Snake::setSnakePartList(std::deque<Cell> newSnakePartList)
{
    snakePartList = newSnakePartList;
}

Cell Snake::getHead()
{
    return head;
}

void Snake::setHead(Cell newHead)
{
    head = newHead;
}
