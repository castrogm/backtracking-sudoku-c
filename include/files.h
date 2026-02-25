#ifndef FILES_H
#define FILES_H

#include "settings.h"

int readFileMatrix(int matrix[SIZE][SIZE]);
// Reads a Sudoku matrix from a file named 'sudokuin.txt', where '.' represents an empty cell

int writeFileMatrix(int matrix[SIZE][SIZE]);
// Writes the Sudoku matrix to a file 'sudokuout.txt', using '.' for empty cells

#endif // FILES_H