#include <iostream>
#include <vector>
using namespace std;

#define n 9 // Define the size of the Sudoku grid as 9x9

// Function prototypes
bool isSafe(int mat[n][n], int row, int col, int num);
void print(int mat[n][n]);
bool isValidInput(int mat[n][n]);
bool solveSudoku(int mat[n][n], int row, int col);

// Function to print the Sudoku grid
void print(int mat[n][n]) {
    for (int i = 0; i < n; i++) {
        if (i % 3 == 0 && i != 0) 
            cout << "---------------------\n"; // Print a horizontal line after every 3 rows
        for (int j = 0; j < n; j++) {
            if (j % 3 == 0 && j != 0) 
                cout << "| "; // Print a vertical line after every 3 columns
            cout << mat[i][j] << " "; // Print the element of the grid
        }
        cout << endl;
    }
}

// Function to validate the initial input of the Sudoku grid
bool isValidInput(int mat[n][n]) {
    vector<bool> seen(n + 1, false); // Vector to track if a number is already seen

    // Check rows
    for (int i = 0; i < n; i++) {
        fill(seen.begin(), seen.end(), false); // Reset the vector for each row
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != 0 && seen[mat[i][j]]) // If duplicate is found in the row
                return false;
            seen[mat[i][j]] = true;
        }
    }

    // Check columns
    for (int j = 0; j < n; j++) {
        fill(seen.begin(), seen.end(), false); // Reset the vector for each column
        for (int i = 0; i < n; i++) {
            if (mat[i][j] != 0 && seen[mat[i][j]]) // If duplicate is found in the column
                return false;
            seen[mat[i][j]] = true;
        }
    }

    // Check 3x3 subgrids
    for (int block = 0; block < n; block++) {
        fill(seen.begin(), seen.end(), false); // Reset the vector for each block
        int startRow = (block / 3) * 3;
        int startCol = (block % 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = mat[startRow + i][startCol + j];
                if (num != 0 && seen[num]) // If duplicate is found in the block
                    return false;
                seen[num] = true;
            }
        }
    }
    return true; // Return true if the input is valid
}

// Function to check if placing a number is safe in the given cell
bool isSafe(int mat[n][n], int row, int col, int num) {
    // Check if the number is not in the current row
    for (int x = 0; x < n; x++) 
        if (mat[row][x] == num)
            return false;

    // Check if the number is not in the current column
    for (int x = 0; x < n; x++) 
        if (mat[x][col] == num)
            return false;

    // Check if the number is not in the current 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (mat[i + startRow][j + startCol] == num)
                return false;

    return true; // Return true if the placement is safe
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int mat[n][n], int row, int col) {
    // If we have reached the end of the grid, return true
    if (row == n - 1 && col == n)
        return true;

    // Move to the next row if we are at the end of the current row
    if (col == n) {
        row++;
        col = 0;
    }

    // If the cell is already filled, move to the next cell
    if (mat[row][col] != 0)
        return solveSudoku(mat, row, col + 1);

    // Try placing numbers 1 to 9 in the cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(mat, row, col, num)) {
            mat[row][col] = num; // Place the number
            if (solveSudoku(mat, row, col + 1)) // Recur to solve the rest of the grid
                return true;
            mat[row][col] = 0; // Backtrack if the placement leads to no solution
        }
    }

    return false; // Return false if no solution is found
}
