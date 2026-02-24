#include "settings.h"

int checkLine(int matrix[SIZE][SIZE], int line, int num);
// Boolean function that checks if a given number is
// already present in a specific line of the Matrix.

int checkColumn(int matrix[SIZE][SIZE], int column, int num);
// Boolean function that checks if a given number is
// already present in a specific column of the Matrix.

int checkSubMatrix(int matrix[SIZE][SIZE], int line, int column, int num);
// Boolean function that checks if a given number is
// already present in the 3x3 submatrix that contains the cell at the
// given line and column coordinates.

int lookForEmptyCell(int matrix[SIZE][SIZE], int *line, int *column);
// Returns 1 if an empty cell is found in the matrix, 0 otherwise.
// If an empty cell is found, the line and column coordinates are returned through pointers.