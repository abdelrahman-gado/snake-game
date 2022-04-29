#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"
#include "CellType.h"
#include "SFML/Graphics.hpp"
#include <vector>

class Board
{
private:
    // board rows count, board column board
    int ROW_COUNT, COL_COUNT;
    float length_cell;
    std::vector<std::vector<Cell>> cells;
    
public:
    Board() = default;
    Board(int rowCount, int colCount, float length_cell);
    std::vector<std::vector<Cell>> getCells();
    void setCells(std::vector<std::vector<Cell>> vec);
    
    // generate the food in the board
    Cell generateFood();
    
    int get_rows_count();
    int get_cols_count();
    
    // if the snake eat the food, change the cell to normal board cell (Empty)
    void removeFood(int row, int col);
    ~Board() = default;

};

#endif // BOARD_H
