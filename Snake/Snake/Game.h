#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Cell.h"
#include "Board.h"
#include "CellType.h"
#include "SFML/Graphics.hpp"


class Game
{
private:
    
    // The Directions of the Snake
    const int DIR_NONE = 0, DIR_RIGHT = 1, DIR_LEFT = -1, DIR_UP = 2, DIR_DOWN = -2;
    sf::RenderWindow m_window;
    int window_width_mode;
    int window_height_mode;
    float length_cell;  // cell is square (length_cell X length_cell)
    
    
    Snake snake;
    Board board;
    
    // the food cell in the board 
    Cell food;
    bool gameOver;
    
    // the current direction of the snake
    int direction;
    
    void input();
    void update();
    void draw();
    
public:
    Game(int window_width, int widnow_height, float length_cell);
    Snake getSnake();
    void setSnake(Snake newSnake);
    Board getBoard();
    void setBoard(Board board);
    bool isGameOver();
    void setGameOver(bool flag);
    int getDirection();
    void setDirection(int d);
    
    // get the next cell based on the current position and the direction of the snake
    Cell getNextCell(Cell currentPosition);
    
    // run the Game
    void run();
    ~Game() = default;

};

#endif // GAME_H
