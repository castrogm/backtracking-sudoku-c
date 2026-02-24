#include "settings.h"

int checkLine(int matrix[SIZE][SIZE], int line, int num)
{
    for (int j = 0; j < SIZE; j++)
    {
        if (matrix[line][j] == num)
        {
            return 1;
        }
    } // else
    return 0;
}

int checkColumn(int matrix[SIZE][SIZE], int column, int num)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (matrix[i][column] == num)
        {
            return 1;
        }
    } // else
    return 0;
}

int checkSubMatrix(int matrix[SIZE][SIZE], int line, int column, int num)
{
    int startLine = line - line % 3;       // offset 0, 3, 6
    int startColumn = column - column % 3; // offset 0, 3, 6

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[startLine + i][startColumn + j] == num)
            {
                return 1;
            }
        }
    } // else
    return 0;
}

int lookForEmptyCell(int matrix[SIZE][SIZE], int *line, int *column)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (matrix[i][j] == 0)
            {
                *line = i;
                *column = j;
                return 1;
            }
        }
    } // else
    return 0;
}