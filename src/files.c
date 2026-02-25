#include "settings.h"
#include <stdio.h>

int readFileMatrix(int matrix[SIZE][SIZE])
{
    FILE *file = fopen("data/sudokuin.txt", "r");
    if (file == NULL)
        return 1; // Error opening file

    // else
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            char c;
            fscanf(file, " %c", &c);
            if (c == '.')
                matrix[i][j] = 0;
            else
                matrix[i][j] = c - '0';
        }
    }

    fclose(file);
    return 0;
}

int writeFileMatrix(int matrix[SIZE][SIZE])
{
    FILE *file = fopen("data/sudokuout.txt", "w");
    if (file == NULL)
        return 1; // Error opening file
    // else
    for (int i = 0; i < SIZE; i++)
    {
        if (i % 3 == 0 && i != 0)
            fprintf(file, "------+-------+------\n");
        for (int j = 0; j < SIZE; j++)
        {
            if (j % 3 == 0 && j != 0)
                fprintf(file, "| ");
            else
                fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    return 0;
}