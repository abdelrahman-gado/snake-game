#include "Game.h"

void Game::draw()
{
    m_window.clear();
    
    // draw the board
    for (int i {0}; i < board.get_rows_count(); i++)
    {
        for (int j {0}; j < board.get_cols_count(); j++)
        {
            m_window.draw(board.getCells()[i][j].getShape());
        }
    }
        
    
    // darw the snake cell including the head
    for (size_t s {0}; s < snake.getSnakePartList().size(); s++)
    {
        m_window.draw(snake.getSnakePartList().at(s).getShape());
    }

    m_window.display();
    
}