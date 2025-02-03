#pragma once
#include <iostream>
#include <fstream>

using namespace std;

// Cell structure for each cell in the board
struct Cell
{
    int x, y;              // Coordinates of the cell
    int state;             // State of the cell (0 = dead, 1 = alive)
    int numLiveNeighbors;  // Number of live neighbors

    // Constructor to initialize values
    Cell() {
        x = 0;
        y = 0;
        state = 0;
        numLiveNeighbors = 0;
    }
};

/*
Function to clear terminal depending on OS
*/
void clearScreen();

/*
Function to initialize all cells in the board.
*/
void initCells(Cell* board[][10], size_t boardSize);

/*
Function to read the board from a file.
*/
void readBoard(Cell* board[][10], size_t boardSize);

/*
Function to print out all cells to cout.
*/
void printCells(Cell* board[][10], size_t boardSize);

/*
Function to count the number of live neighbors for each cell.
*/
void findNumNeighbors(Cell* board[][10], size_t boardSize, Cell* curCell);

/*
Function to update each cell's state based on Game of Life rules.
*/
bool updateCellState(Cell* board[][10], size_t boardSize);

/*
Function to deallocate memory for dynamically allocated cells.
*/
void cleanupBoard(Cell* board[][10], size_t boardSize);


/*
Function to clear terminal depending on OS
*/
void clearScreen();

/*
Function to initialize all cells in the board.
*/
void initCells(Cell* board[][10], size_t boardSize);

/*
Function to read the board from a file.
*/
void readBoard(Cell* board[][10], size_t boardSize);

/*
Function to print out all cells to cout.
*/
void printCells(Cell* board[][10], size_t boardSize);

/*
Function to count the number of live neighbors for each cell.
*/
void findNumNeighbors(Cell* board[][10], size_t boardSize, Cell* curCell);

/*
Function to update each cell's state based on Game of Life rules.
*/
bool updateCellState(Cell* board[][10], size_t boardSize);

/*
Function to deallocate memory for dynamically allocated cells.
*/
void cleanupBoard(Cell* board[][10], size_t boardSize);
