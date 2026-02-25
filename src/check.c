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

int lookForBestEmptyCell(int matrix[SIZE][SIZE], int *line, int *column)
{
    int minOptions = SIZE + 1; // More than the maximum possible options (1-9)
    int bestLine = -1;
    int bestColumn = -1;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (matrix[i][j] == 0)
            {
                int optionsCount = 0;
                for (int num = 1; num <= SIZE; num++)
                {
                    if (!checkLine(matrix, i, num) &&
                        !checkColumn(matrix, j, num) &&
                        !checkSubMatrix(matrix, i, j, num))
                    {
                        optionsCount++;
                    }
                }
                if (optionsCount < minOptions) // Found a cell with fewer options
                {
                    minOptions = optionsCount;
                    bestLine = i;
                    bestColumn = j;
                }
            }
        }
    }

    if (bestLine != -1 && bestColumn != -1)
    {
        *line = bestLine;
        *column = bestColumn;
        return 1;
    } // else
    return 0; // No empty cell found
}