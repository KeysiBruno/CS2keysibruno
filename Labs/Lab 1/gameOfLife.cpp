#include "gameOfLife.h"

/*
Function to clear terminal depending on OS
*/
void clearScreen()
{
    system("clear"); // I use Mac
}

/*
Function to initialize all cells in the board.
Takes in 2D array of pointers and size of array
Should create structs and populate the array
*/
void initCells(Cell* board[][10], size_t boardSize)
{
    for (size_t i = 0; i < boardSize; i++)
    {
        for (size_t j = 0; j < boardSize; j++)
        {
            // Cell *board[][] was already created, so i´m reserving memory.
            board[i][j] = new Cell(); 
            board[i][j]->x = i;
            board[i][j]->y = j;
        }
    }
}

/*
Function to read the board from a file
Prompt for the file to read inside of the function
Structure of file should consist of 10 lines of 0 or 1 to indicate cell state
*/
void readBoard(Cell* board[][10], size_t boardSize)
{
    string filename;
    cout << "Enter filename: ";
    cin >> filename;
    ifstream file(filename);

    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    for (int i = 0; i < boardSize; i++) {
        string line;
        getline(file, line);
        for (int j = 0; j < boardSize && j < line.length(); j++) {
            board[i][j]->state = line[j] - '0';
        }
    }
    file.close();
}

/*
Function to print out all cells to cout
*/
void printCells(Cell* board[][10], size_t boardSize)
{
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            cout << (board[i][j]->state ? "■ " : "□ ");
        }
        cout << endl;
    }
    cout << endl;
}


/*
Function to count the number of live neighbors for each cell.
Must use the x, y position stored with each cell to determine which neighbors they have
*/

void findNumNeighbors(Cell* board[][10], size_t boardSize, Cell* curCell)
{
    int x = curCell->x, y = curCell->y;
    curCell->numLiveNeighbors = 0;

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < boardSize && ny >= 0 && ny < boardSize) {
                curCell->numLiveNeighbors += board[nx][ny]->state;
            }
        }
    }
}


/*
Function to update each cell's state based on number of neighbors
Must use following rules:

Any live cell with fewer than two live neighbors dies, as if by underpopulation.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by overpopulation.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Return if you updated cells or not to break out of while loop from main.
*/
bool updateCellState(Cell* board[][10], size_t boardSize)
{
    bool changed = false;
    int newStates[10][10] = {};

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            findNumNeighbors(board, boardSize, board[i][j]);
            int neighbors = board[i][j]->numLiveNeighbors;

            if (board[i][j]->state == 1) {
                newStates[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            } else {
                newStates[i][j] = (neighbors == 3) ? 1 : 0;
            }

            if (newStates[i][j] != board[i][j]->state) {
                changed = true;
            }
        }
    }

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            board[i][j]->state = newStates[i][j];
        }
    }
    return changed;
}
