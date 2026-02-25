#include "settings.h"
#include "check.h"

int start_solver(int matrix[SIZE][SIZE], int *backtracks, int *recursive_calls)
{
    int line, column;

    if (!lookForBestEmptyCell(matrix, &line, &column))
    {
        return 1;
    }
    // else
    for (int num = 1; num <= SIZE; num++)
    {
        if (!checkLine(matrix, line, num) && !checkColumn(matrix, column, num) && //
            !checkSubMatrix(matrix, line, column, num))
        {
            matrix[line][column] = num;

            (*recursive_calls)++; // Increment the recursive calls counter

            if (start_solver(matrix, backtracks, recursive_calls))
            {
                return 1;
            }
            // else
            matrix[line][column] = 0; // backtracking
            (*backtracks)++;          // Increment the backtracks counter
        }
    }
    return 0;
}