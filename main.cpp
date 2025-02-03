#include <iostream>
#include <string>
#include "gameOfLife.h"

using namespace std;

int main(void)
{
    int stage = 0;
    bool boardChanged = true;
    size_t boardSize = 10;
    Cell* board[10][10];

    // Initialize the board
    initCells(board, boardSize);

    // Prompt for file and read it
    cout << "Please enter the board file:" << endl;
    readBoard(board, boardSize);

    // Main loop to update board
    while(boardChanged) {
        clearScreen();  // Clear the screen each time
        cout << "Stage: " << stage << endl;

        printCells(board, boardSize);  // Print the board to the console
        boardChanged = updateCellState(board, boardSize);  // Update cells and check if the board changed

        cout << "Press Enter to continue to the next generation..." << endl;
        cin.ignore();  // Ignore leftover newline characters
        cin.get();  // Wait for the user to press Enter
        stage++;
    }

    cleanupBoard(board, boardSize); // Clean up memory at the end
    return 0;
}
