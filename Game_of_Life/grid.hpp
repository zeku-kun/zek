#pragma once
#include <vector>

class Grid{

    public:
        // this initializes the private variables(rows, columns, cellsize, cells)
        Grid(int width, int height, int cellSize)
        : rows(height/cellSize), columns(width/cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)){}; 
        void Draw();
        void setValue(int row, int column, int value);
        int getValue(int row, int column);
        bool isWithinBounds(int row, int column);
        int getRows(){return rows;}
        int getColumns(){return columns;}
        void fillRandom();
    private:
        int rows;
        int columns;
        int cellSize;
        std::vector<std::vector<int>> cells; // 2d vector for the cells
};