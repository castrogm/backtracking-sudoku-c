#include <stdio.h>
#include "settings.h"
#include "validator.h"

int readFileMatrix(int matrix[SIZE][SIZE])
{
    FILE *file = fopen("data/sudokuin.txt", "r");
    if (file == NULL)
        return 1; // Error opening file

    // else
    char buffer[SIZE + 1]; // +1 for null terminator
    for (int i = 0; i < SIZE; i++)
    {
        fscanf(file, " %s", buffer);
        if (!isValidLine(buffer))
        {
            fclose(file);
            return 1; // Invalid line in file
        }

        for (int j = 0; j < SIZE; j++)
        {
            if (buffer[j] == '.')
                matrix[i][j] = 0;
            else
                matrix[i][j] = buffer[j] - '0';
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
        for (int j = 0; j < SIZE; j++)
        {
            if (matrix[i][j] == 0)
                fprintf(file, ". ");
            else
                fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    return 0;
}