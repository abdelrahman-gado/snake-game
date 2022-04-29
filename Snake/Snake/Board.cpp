#include "Board.h"

Board::Board(int rowCount, int colCount, float length_cell)
    : ROW_COUNT {rowCount}, COL_COUNT {colCount}, length_cell {length_cell}
{
    
    // create the board two-dim array using vector
    for (int i {0}; i < ROW_COUNT; i++)
    {
        std::vector<Cell> row;
        for (int j {0}; j < COL_COUNT; j++)
        {
            row.push_back(Cell (i, j, length_cell, EMPTY));
        }
        cells.push_back(row);
    }
}


std::vector<std::vector<Cell>> Board::getCells()
{
    return cells;
}

void Board::setCells(std::vector<std::vector<Cell>> vec)
{
    cells = vec;
}

int Board::get_rows_count()
{
    return ROW_COUNT;
}

int Board::get_cols_count()
{
    return COL_COUNT;
}


// generate the food on the board and return that cell to return it to a normal baord cell (empty)
// if the snake eat the food
Cell Board::generateFood()
{
    srand(time(NULL));
    int row = rand() % ROW_COUNT;
    int col = rand() % COL_COUNT;
    cells[row][col].setCellType(FOOD);
    Cell food = cells[row][col];
    return food;
}

// remove the food when snake ate it using the food cell row and col from the board two-dim array
void Board::removeFood(int row, int col)
{
    cells[row][col].setCellType(EMPTY);
}