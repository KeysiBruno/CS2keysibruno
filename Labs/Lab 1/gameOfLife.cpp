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

    if (!file) 
    {
        cout << "Error! try again." << endl;
        return;
    }

    for (int i = 0; i < boardSize; i++) 
    {
        string copy;
        getline(file, copy);
        for (int j = 0; j < boardSize; j++) 
        {
            board[i][j]->state = copy[j] - '0';
        }
    }
    file.close();
}

/*
Function to print out all cells to cout
*/
void printCells(Cell* board[][10], size_t boardSize)
{
    for (int i = 0; i < boardSize; i++) 
    {
        for (int j = 0; j < boardSize; j++) 
        {
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
//This logic was really diffucult that I got helped by JeffDoder(youtube chanel)
// So, this logic might not count as mine

    int x = curCell->x;
    int y = curCell->y;

    curCell->numLiveNeighbors = 0;

    for (int i = -1; i <= 1; i++) 
    {
        for (int j = -1;  j<= 1; j++) 
        {
            if (i == 0 && j == 0) continue;

            int aux1 = i + x;
            int aux2 = j + y;

            if (aux1>= 0 && aux1 < boardSize && aux2 >= 0 && aux2 < boardSize) 
            {
                curCell->numLiveNeighbors += board[aux1][aux2]->state;
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
    int newStates[10][10];

    bool changed = false;
    
    for (int i = 0; i < boardSize; i++) 
    {
        for (int j = 0; j < boardSize; j++) 
        {
            findNumNeighbors(board, boardSize, board[i][j]);

            int neighbors = board[i][j]->numLiveNeighbors;

            if (board[i][j]->state==1) 
            {
               if(neighbors == 2 || neighbors == 3) 
                {
                   newStates[i][j] = 1;
                }
                else
                {
                   newStates[i][j] = 0;
                }
            } 
            else 
            {
                if(neighbors == 3)
                {
                    newStates[i][j] = 1;
                }
                else
                {
                    newStates[i][j] = 0;
                }
            }

            if (newStates[i][j] != board[i][j]->state)
            {
                changed = true;
            }
        }
    }

    for (int i = 0; i < boardSize; i++) 
    {
        for (int j = 0; j < boardSize; j++) 
        {
            board[i][j]->state = newStates[i][j];
        }
    }
    return changed;
}
