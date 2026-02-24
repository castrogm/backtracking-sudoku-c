#include "settings.h"
#include "check.h"

int start_solver(int matrix[SIZE][SIZE])
{
    int line, column;

    if (!lookForEmptyCell(matrix, &line, &column))
    {
        return 1;
    }
    // else
    for (int num = 1; num <= SIZE; num++)
    {
        if (checkLine(matrix, line, num) == 0 && checkColumn(matrix, column, num) == 0 && //
            checkSubMatrix(matrix, line, column, num) == 0)
        {
            matrix[line][column] = num;

            if (start_solver(matrix))
            {
                return 1;
            }
            // else
            matrix[line][column] = 0; // backtracking
        }
    }
    return 0;
}