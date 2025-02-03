#include "gameOfLife.h"

void clearScreen()
{
    system("clear");  // I use Mac
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
void readBoard(Cell* board[][10], size_t boardSize) {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    ifstream file(filename);  
    if (!file) {
        cerr << "Error bro!, try again. " << endl;
        exit(1);
    }

    for (size_t i = 0; i < boardSize; i++) {
        string line;
        file >> line;  
        for (size_t j = 0; j < boardSize; j++) {
            board[i][j]->state = line[j] - '0';  // Converting char from '0' or '1' to int
        }
    }

    file.close();  
}

// Function to print all cells to cout
void printCells(Cell* board[][10], size_t boardSize)
{
    for (size_t i = 0; i < boardSize; i++)
    {
        for (size_t j = 0; j < boardSize; j++)
        {
            cout << (board[i][j]->state ? 'O' : '.');  // 'O' for alive, '.' for dead
        }
        cout << endl;
    }
    cout << endl;
}

// Function to count the number of live neighbors for each cell
void findNumNeighbors(Cell* board[][10], size_t boardSize, Cell* curCell)
{
    int x = curCell->x;
    int y = curCell->y;
    curCell->numLiveNeighbors = 0;

    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (dx == 0 && dy == 0) continue;  // Skip the current cell itself

            int nx = x + dx;
            int ny = y + dy;

            // Check if the neighbor is within bounds
            if (nx >= 0 && ny >= 0 && nx < (int)boardSize && ny < (int)boardSize)
            {
                curCell->numLiveNeighbors += board[nx][ny]->state;
            }
        }
    }
}

// Function to update each cell's state based on Game of Life rules
bool updateCellState(Cell* board[][10], size_t boardSize) {
    bool changed = false;

    // First pass: Count the live neighbors for each cell
    for (size_t i = 0; i < boardSize; i++) {
        for (size_t j = 0; j < boardSize; j++) {
            findNumNeighbors(board, boardSize, board[i][j]);
        }
    }

    // Second pass: Update the state of each cell based on the Game of Life rules
    for (size_t i = 0; i < boardSize; i++) {
        for (size_t j = 0; j < boardSize; j++) {
            Cell* cell = board[i][j];
            int liveNeighbors = cell->numLiveNeighbors;
            int prevState = cell->state;

            if (cell->state == 1) {  // Cell is alive
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    cell->state = 0;  // Dies due to underpopulation or overpopulation
                }
            } else {  // Cell is dead
                if (liveNeighbors == 3) {
                    cell->state = 1;  // Becomes alive due to reproduction
                }
            }

            if (prevState != cell->state) changed = true;  // Track if any cell changed
        }
    }

    return changed;
}

// Function to clean up dynamically allocated memory for the board
void cleanupBoard(Cell* board[][10], size_t boardSize)
{
    for (size_t i = 0; i < boardSize; i++)
    {
        for (size_t j = 0; j < boardSize; j++)
        {
            delete board[i][j];  // Free the memory for each cell
            board[i][j] = nullptr;  // Set the pointer to nullptr
        }
    }
}
