# Sudoku Solver in C++

This is a C++ implementation of a Sudoku solver that uses backtracking to solve 9x9 Sudoku puzzles. It includes functionalities to validate inputs, check safe placements, and print the Sudoku grid.

---

## Features

- **Backtracking Algorithm**: Efficiently solves Sudoku puzzles.
- **Input Validation**: Ensures the initial grid follows Sudoku rules.
- **Grid Printing**: Displays the Sudoku grid in a readable format.
- **Customizable**: Supports any 9x9 Sudoku puzzle as input.

---

## How It Works

1. **Input Validation**: 
   - The program checks rows, columns, and 3x3 subgrids for duplicates.
   - Ensures the input grid adheres to Sudoku rules.

2. **Backtracking**:
   - The algorithm tries placing numbers (1–9) in each empty cell.
   - Recursively checks if the placement is valid.
   - If a placement leads to a dead end, it backtracks and tries the next possible number.

3. **Grid Printing**:
   - The grid is printed with separators for better visualization.

---

## Code Structure

- **`isSafe`**: Checks if placing a number in a cell is valid.
- **`isValidInput`**: Validates the initial Sudoku grid.
- **`solveSudoku`**: Solves the Sudoku puzzle using backtracking.
- **`print`**: Prints the Sudoku grid in a formatted manner.

---

## Usage

1. **Include the Code**:
   Copy and paste the code into your C++ project.

2. **Input the Sudoku Grid**:
   - Replace `mat[n][n]` with your Sudoku puzzle.
   - Use `0` for empty cells.

3. **Compile and Run**:
   ```bash
   g++ sudoku_solver.cpp -o sudoku_solver
   ./sudoku_solver


## Sample Input and Output
### Input:

5 3 0 | 0 7 0 | 0 0 0
6 0 0 | 1 9 5 | 0 0 0
0 9 8 | 0 0 0 | 0 6 0
------+------+------
8 0 0 | 0 6 0 | 0 0 3
4 0 0 | 8 0 3 | 0 0 1
7 0 0 | 0 2 0 | 0 0 6
------+------+------
0 6 0 | 0 0 0 | 2 8 0
0 0 0 | 4 1 9 | 0 0 5
0 0 0 | 0 8 0 | 0 7 9


### Output:

5 3 4 | 6 7 8 | 9 1 2
6 7 2 | 1 9 5 | 3 4 8
1 9 8 | 3 4 2 | 5 6 7
------+------+------
8 5 9 | 7 6 1 | 4 2 3
4 2 6 | 8 5 3 | 7 9 1
7 1 3 | 9 2 4 | 8 5 6
------+------+------
9 6 1 | 5 3 7 | 2 8 4
2 8 7 | 4 1 9 | 6 3 5
3 4 5 | 2 8 6 | 1 7 9


## Dependencies

Standard C++ library (<iostream>, <vector>).

## Contributing

Contributions are welcome! Feel free to submit a pull request or open an issue for bugs, improvements, or suggestions.

## License

This project is licensed under the MIT License.

## Author

Developed by Lucky Joshi