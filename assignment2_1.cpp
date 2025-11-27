#include <iostream>
using namespace std;

const int N = 9;

// Print the Sudoku board
void printBoard(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Check if placing num at (row, col) is consistent with constraints
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Row constraint
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num)
            return false;
    }

    // Column constraint
    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num)
            return false;
    }

    // Subgrid (3x3 box) constraint
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

// Find an unassigned location in the grid; returns true if found
bool findUnassigned(int grid[N][N], int &row, int &col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0)   // 0 means empty
                return true;
        }
    }
    return false;
}

// Backtracking CSP solver for Sudoku
bool solveSudoku(int grid[N][N]) {
    int row, col;

    // If there is no unassigned cell, puzzle is solved
    if (!findUnassigned(grid, row, col))
        return true;

    // Try digits 1 to 9 as domain values
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            // Assign num (tentatively)
            grid[row][col] = num;

            // Recurse
            if (solveSudoku(grid))
                return true;

            // Failure => undo assignment (backtrack)
            grid[row][col] = 0;
        }
    }

    // Trigger backtracking
    return false;
}

int main() {
    // 0 represents empty cells
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},

        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},

        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(grid)) {
        cout << "Solved Sudoku:" << endl;
        printBoard(grid);
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}