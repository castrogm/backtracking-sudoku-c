# Sudoku Solver

A simple and efficient Sudoku solver written in C. This project uses the **Backtracking** algorithm to find the solution for any valid 9x9 Sudoku grid.

## How it Works
The algorithm operates using recursive backtracking:
1. It scans the grid to find an empty cell (represented by `.`).
2. It attempts to place a number from 1 to 9.
3. It validates the insertion by checking the current row, column, and 3x3 subgrid.
4. If valid, it recursively calls itself to fill the next cell. If it encounters a dead end, it backtracks (resets the cell) and tries the next available number.

## Project Structure
- `src/`: Contains the source code files (`main.c`, `solver.c`, `check.c`, `display.c`).
- `include/`: Contains the header files (`solver.h`, `check.h`, `display.h`, `settings.h`).
- `Makefile`: Automates the build process.

## How to Compile and Run

### Prerequisites
- GCC Compiler
- Make tool

### Build
To compile the project, open the terminal in the root directory and type:
`make`

### Run
Execute the generated file:
- Linux/macOS: `./sudoku_solver`
- Windows: `sudoku_solver.exe`

### Clean
To remove object files and the executable, run:
`make clean`

## 🎮 Usage
The program will prompt you to type the 9 characters for each row.
- Input numbers from `1` to `9`.
- Use a dot `.` to represent an empty cell.
- Do not use spaces.

**Example input for a row:** `53..7....`