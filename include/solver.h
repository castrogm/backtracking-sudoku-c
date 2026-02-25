#ifndef SOLVER_H
#define SOLVER_H

#include "settings.h"

int start_solver(int matrix[SIZE][SIZE], int *backtracks, int *recursive_calls);
// Boolean function that uses backtracking to solve the Sudoku puzzle.
// Returns 1 if a solution is found and 0 otherwise.
// Modifies the input matrix to contain the solution if one is found.
// The backtracks and recursive_calls parameters are pointers to integers
// that are updated during the solving process.

#endif // SOLVER_H