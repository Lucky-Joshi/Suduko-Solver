#include <iostream>
#include <vector>
using namespace std;
#define n 9

// Function prototypes
bool isSafe(int mat[n][n], int row, int col, int num);
void print(int mat[n][n]);
bool isValidInput(int mat[n][n]);
bool solveSuduko(int mat[n][n], int row, int col);

void print(int mat[n][n]) {
    for (int i = 0; i < n; i++) {
        if (i % 3 == 0 && i != 0) 
            cout << "---------------------\n";
        for (int j = 0; j < n; j++) {
            if (j % 3 == 0 && j != 0) 
                cout << "| ";
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValidInput(int mat[n][n]) {
    vector<bool> seen(n + 1, false);

    // Check rows
    for (int i = 0; i < n; i++) {
        fill(seen.begin(), seen.end(), false);
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != 0 && seen[mat[i][j]])
                return false;
            seen[mat[i][j]] = true;
        }
    }

    // Check columns
    for (int j = 0; j < n; j++) {
        fill(seen.begin(), seen.end(), false);
        for (int i = 0; i < n; i++) {
            if (mat[i][j] != 0 && seen[mat[i][j]])
                return false;
            seen[mat[i][j]] = true;
        }
    }

    // Check 3x3 subgrids
    for (int boxRow = 0; boxRow < n; boxRow += 3) {
        for (int boxCol = 0; boxCol < n; boxCol += 3) {
            fill(seen.begin(), seen.end(), false);
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int num = mat[boxRow + i][boxCol + j];
                    if (num != 0 && seen[num])
                        return false;
                    seen[num] = true;
                }
            }
        }
    }
    return true;
}

bool solveSuduko(int mat[n][n], int row, int col) {
    if (row == n - 1 && col == n)
        return true;

    if (col == n) {
        row++;
        col = 0;
    }

    if (mat[row][col] > 0)
        return solveSuduko(mat, row, col + 1);

    for (int num = 1; num <= n; num++) {
        if (isSafe(mat, row, col, num)) {
            mat[row][col] = num;
            if (solveSuduko(mat, row, col + 1))
                return true;
            mat[row][col] = 0; // Backtrack
        }
    }
    return false;
}

bool isSafe(int mat[n][n], int row, int col, int num) {
    // Check row and column
    for (int x = 0; x < n; x++) {
        if (mat[row][x] == num || mat[x][col] == num)
            return false;
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i + startRow][j + startCol] == num)
                return false;
        }
    }
    return true;
}

int main() {
    int mat[n][n];
    cout << "Enter the Sudoku grid (0 for empty cells):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    if (!isValidInput(mat)) {
        cout << "Invalid Sudoku input. Please check the grid.\n";
        return 1;
    }

    if (solveSuduko(mat, 0, 0)) {
        cout << "Solved Sudoku:\n";
        print(mat);
    } else {
        cout << "No solution exists!\n";
    }
    return 0;
}

