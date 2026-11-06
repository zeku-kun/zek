#include "grid.hpp"
#include <raylib.h>

void Grid::Draw()
{   
    // Renders grid-like boxes
    for(int row = 0; row < rows; row++){
        for(int column = 0; column < columns; column++){
            Color color = cells[row][column] ? GREEN : Color{55, 55, 55, 255}; // colors the boxes. grey if it is 0(dead) and green if it is 1(alive)
            DrawRectangle(column * cellSize, row * cellSize, cellSize - 1, cellSize - 1, color); // function to draw the box
        }
    }
}

void Grid::setValue(int row, int column, int value)
{
    // checks the row and column if they are valid if it is valid it assign a value to the specific cell(row, column)
    if(isWithinBounds(row, column)){ 
        cells[row][column] = value;
    }
}

int Grid::getValue(int row, int column)
{
    if(isWithinBounds(row , column)){
        return cells[row][column];
    }
    return 0;
}

bool Grid::isWithinBounds(int row, int column) // checks if the cell is within the grid.
{
    if(row >= 0 && row < rows && column >= 0 && column < columns){
        return true;
    }
    return false;
}

void Grid::fillRandom()
{
    for(int row = 0; row < rows; row++){
        for(int column = 0; column < columns; column++){
            int random = GetRandomValue(0, 4);
            cells[row][column] = (random == 4) ? 1 : 0;
        }
    }
}
