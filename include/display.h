#ifndef DISPLAY_H
#define DISPLAY_H

#include "settings.h"

void readManualMatrix(int matrix[SIZE][SIZE]);
// Reads a matrix from user input, where '.' represents an empty cell

void printMatrix(int matrix[SIZE][SIZE]);
// Prints the Sudoku matrix on the display, using '.' for empty cells

#endif // DISPLAY_H