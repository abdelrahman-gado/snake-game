#ifndef CELL_H
#define CELL_H

#include "CellType.h"
#include "SFML/Graphics.hpp"


class Cell
{
private:
    // cell row no, cell column no
    int row, col;
    // length of the cell (the cell is a square 20x20)
    float length; 
    sf::RectangleShape cellShape;
    
    // the type of the cell (empty cell, snake cell, food cell)
    CellType cellType;
    
public:
    Cell() = default;
    Cell(int row, int col, float length_cell, CellType cellType);
    CellType getCellType();
    void setCellType(CellType cellType);
    
    // change the color based on the change of the type of the cell
    void changeColorOnType();
    
    int getRow();
    int getCol();
    
    sf::FloatRect getPosition();
    sf::RectangleShape getShape();
    
    // compare if rhs cell is the same the current cell
    bool operator==(Cell rhs);
    ~Cell() = default;

};

#endif // CELL_H
