#include "Game.h"

void Game::update()
{
    if (!gameOver)
    {
        // if the snake is moving, get the next cell based on the current direction
        if (direction != DIR_NONE)
        {
            Cell nextCell = getNextCell(snake.getHead());
            
            // check if the next cell is one of the body cells of the snake
            if (snake.checkCrash(nextCell))
            {
                setDirection(DIR_NONE);
                gameOver = true;
            }
            else
            {
                snake.move(nextCell);
                // if the nextcell is the food
                if (nextCell.getCellType() == FOOD)
                {
                    snake.grow();
                    // remove the previous food from the board and generate new one
                    board.removeFood(food.getRow(), food.getCol());
                    food = board.generateFood();
                }
                
            }
            
        }
    }
}