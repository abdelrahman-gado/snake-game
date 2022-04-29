#include "Cell.h"

Cell::Cell(int row, int col, float length_cell, CellType cellType)
    : row {row}, col {col}, length {length_cell}, cellType {cellType}
{
    cellShape.setPosition(sf::Vector2f(col*length, row*length));
    cellShape.setSize(sf::Vector2f(length, length));
    
    // initial color of the cell
    if (cellType == EMPTY)
        cellShape.setFillColor(sf::Color::Blue);
    else if (cellType == FOOD)
        cellShape.setFillColor(sf::Color::Green);
    else if (cellType == SNAKE_NODE)
        cellShape.setFillColor(sf::Color::Red);
    
}

CellType Cell::getCellType()
{
    return cellType;
}

// change the type and in the same change the color
void Cell::setCellType(CellType newCellType)
{
    cellType = newCellType;
    changeColorOnType();
}

void Cell::changeColorOnType()
{
    if (cellType == EMPTY)
        cellShape.setFillColor(sf::Color::Blue);
    else if (cellType == FOOD)
        cellShape.setFillColor(sf::Color::Green);
    else if (cellType == SNAKE_NODE)
        cellShape.setFillColor(sf::Color::Red);
}


int Cell::getRow()
{
    return row;
}

int Cell::getCol()
{
    return col;
}

sf::FloatRect Cell::getPosition()
{
    return cellShape.getGlobalBounds();
}

sf::RectangleShape Cell::getShape()
{
    return cellShape;
}

// compare two cells to see if they are equal (the same row and col) (if they are the same cell)
bool Cell::operator==(Cell rhs)
{
    if (this->row == rhs.row && this->col == rhs.col)
        return true;
    else
        return false;
}