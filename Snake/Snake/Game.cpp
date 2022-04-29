#include "Game.h"

Game::Game(int window_width, int window_height, float length_cell)
    : window_width_mode {window_width}, window_height_mode {window_height}, length_cell {length_cell}
{
    int cols_count = window_width_mode / length_cell;  
    int rows_count = window_height_mode / length_cell;
    
    Cell initPos (0, 0, length_cell, SNAKE_NODE);
    snake = Snake (initPos);
    board = Board (rows_count, cols_count, length_cell);
    
    food = board.generateFood();
    
    gameOver = false;
    direction = DIR_RIGHT;
    
    m_window.create(sf::VideoMode(window_width_mode, window_height_mode), "SNAKE");
}

Snake Game::getSnake()
{
    return snake;
}

void Game::setSnake(Snake newSnake)
{
    snake = newSnake;
}

Board Game::getBoard()
{
    return board;
}

void Game::setBoard(Board newBoard)
{
    board = newBoard;
}

bool Game::isGameOver()
{
    return gameOver;
}

void Game::setGameOver(bool flag)
{
    gameOver = flag;
}

int Game::getDirection()
{
    return direction;
}

void Game::setDirection(int d)
{
    direction = d;
}

// get the next cell based on the current position and the direction of the snake
Cell Game::getNextCell(Cell currentPosition)
{
    int row = currentPosition.getRow();
    int col = currentPosition.getCol();
    if (direction == DIR_RIGHT)
    {
        col++;
    }
    else if (direction == DIR_LEFT)
    {
        col--;
    }
    else if (direction == DIR_UP)
    {
        row--;
    }
    else if (direction == DIR_DOWN)
    {
        row++;
    }
    
    Cell nextCell = board.getCells()[row][col];
    
    return nextCell;
}


void Game::run()
{
    sf::Event event;
    while (m_window.isOpen())
    {
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                m_window.close();
        }
        
        input();
        update();
        draw();
        
    }
}




